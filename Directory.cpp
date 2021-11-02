#include "Directory.h"
#include "Bucket.h"
#include <vector>

Directory::Directory(int pglobal, int bucket_size)
{
    this->pglobal = pglobal;
    this->bucket_size = 2046;
    for(int i = 0 ; i < 1<<pglobal ; i++ )
    {
        buckets.push_back(new Bucket(pglobal,bucket_size));
    }
}

//funcao
int Directory::hash(int n)
{
    return n&((1<<pglobal)-1);
}

int Directory::pairIndex(int bucket_no, int profundidade)
{
    return bucket_no^(1<<(profundidade-1));
}

void Directory::crescer(void)
{
    for(int i = 0 ; i < 1<<pglobal ; i++ )
        buckets.push_back(buckets[i]);
    pglobal++;
}

void Directory::diminuir(void)
{
    int i,flag=1;
    for( i=0 ; i<buckets.size() ; i++ )
    {
        if(buckets[i]->getDepth()==pglobal)
        {
            flag=0;
            return;
        }
    }
    pglobal--;
    for(i = 0 ; i < 1<<pglobal ; i++ )
        buckets.pop_back();
}

void Directory::split(int bucket_no)
{
    int plocal,pair_index,index_diff,dir_size,i;
    map<int, string> temp;
    map<int, string>::iterator it;

    plocal = buckets[bucket_no]->increaseDepth();
    if(plocal>pglobal)
        crescer();
    pair_index = pairIndex(bucket_no,plocal);
    buckets[pair_index] = new Bucket(plocal,bucket_size);
    temp = buckets[bucket_no]->copy();
    buckets[bucket_no]->clear();
    index_diff = 1<<plocal;
    dir_size = 1<<pglobal;
    for( i=pair_index-index_diff ; i>=0 ; i-=index_diff )
        buckets[i] = buckets[pair_index];
    for( i=pair_index+index_diff ; i<dir_size ; i+=index_diff )
        buckets[i] = buckets[pair_index];
    for(it=temp.begin();it!=temp.end();it++)
        insert((*it).first,(*it).second,1);
}

void Directory::merge(int bucket_no)
{
    int plocal,pair_index,index_diff,dir_size,i;

    plocal = buckets[bucket_no]->getDepth();
    pair_index = pairIndex(bucket_no,plocal);
    index_diff = 1<<plocal;
    dir_size = 1<<pglobal;

    if( buckets[pair_index]->getDepth() == plocal )
    {
        buckets[pair_index]->decreaseDepth();
        delete(buckets[bucket_no]);
        buckets[bucket_no] = buckets[pair_index];
        for( i=bucket_no-index_diff ; i>=0 ; i-=index_diff )
            buckets[i] = buckets[pair_index];
        for( i=bucket_no+index_diff ; i<dir_size ; i+=index_diff )
            buckets[i] = buckets[pair_index];
    }
}

string Directory::bucket_id(int n)
{
    int d;
    string s;
    d = buckets[n]->getDepth();
    s = "";
    while(n>0 && d>0)
    {
        s = (n%2==0?"0":"1")+s;
        n/=2;
        d--;
    }
    while(d>0)
    {
        s = "0"+s;
        d--;
    }
    return s;
}

void Directory::insert(int key,string value,bool reinserido)
{
    int bucket_no = hash(key);
    int status = buckets[bucket_no]->insert(key,value);
    if(status==1)
    {
        if(!reinserido)
            cout<<"Inserted key "<<key<<" in bucket "<<bucket_id(bucket_no)<<endl;
        else
            cout<<"Moved key "<<key<<" to bucket "<<bucket_id(bucket_no)<<endl;
    }
    else if(status==0)
    {
        split(bucket_no);
        insert(key,value,reinserido);
    }
    else
    {
        cout<<"Key "<<key<<" already exists in bucket "<<bucket_id(bucket_no)<<endl;
    }
}

void Directory::remove(int key,int mode)
{
    int bucket_no = hash(key);
    if(buckets[bucket_no]->remove(key))
        cout<<"Deleted key "<<key<<" from bucket "<<bucket_id(bucket_no)<<endl;
    if(mode>0)
    {
        if(buckets[bucket_no]->isEmpty() && buckets[bucket_no]->getDepth()>1)
            merge(bucket_no);
    }
    if(mode>1)
    {
        diminuir();
    }
}

void Directory::update(int key, string value)
{
    int bucket_no = hash(key);
    buckets[bucket_no]->update(key,value);
}

void Directory::search(int key)
{
    int bucket_no = hash(key);
    cout<<"Searching key "<<key<<" in bucket "<<bucket_id(bucket_no)<<endl;
    buckets[bucket_no]->search(key);
}

void Directory::mostra(bool duplicates)
{
    int i,j,d;
    string s;
    std::set<string> shown;
    cout<<"Global depth : "<<pglobal<<endl;
    for(i=0;i<buckets.size();i++)
    {
        d = buckets[i]->getDepth();
        s = bucket_id(i);
        if(duplicates || shown.find(s)==shown.end())
        {
            shown.insert(s);
            for(j=d;j<=pglobal;j++)
                cout<<" ";
            cout<<s<<" => ";
            buckets[i]->mostra();
        }
    }
}


