#include "Bucket.h"
#include <iostream>
#include <stdbool.h>
#include <sstream>
#include <cassert>
#include <iostream>
#include <vector>
#include <bits/stdc++.h>


/*INFO: 
Map:  são contêineres associativos que armazenam elementos
formados por uma combinação de um valor-chave e um valor mapeado , seguindo uma ordem específica
https://www.cplusplus.com/reference/map/map/
*/

using namespace std;


//função de insersção no bucket
int Bucket::insert(int key, string value)
{   //usado pra percorrer o container
    std::map<int,string>::iterator it; 
    //it =procura a key passada no container de keys
    it = keys.find(key); 
    if(it!=keys.end())
        return -1;
    //caso o container esteja cheio
    if(isFull())
        return 0;

    //insere a key passada no container <keys>
    keys[key] = value;
    return 1;
}

//funcao delete
int Bucket::remove(int key)
{
    std::map<int,string>::iterator it;
    it = keys.find(key);
    if(it!=keys.end())
    {
        keys.erase(it);
        return 1;
    }
    else
    {
        //caso nao encontre a key retorna falso
        return -1;
    }
}

int Bucket::update(int key, string value)
{
    std::map<int,string>::iterator it;
    it = keys.find(key);
    if(it!=keys.end())
    {
        keys[key] = value;
        cout<<"Value updated"<<endl;
        return 1;
    }
    else
    {
        cout<<"Cannot update : This key does not exists"<<endl;
        return 0;
    }
}

std::map <int, string> Bucket::search(int key)
{
    std::map<int,string>::iterator it;
    it = keys.find(key);
    if(it!=keys.end())
    {
        //return keys[key];
        cout<<"Value = "<<it->second<<endl;
    }
    else
    {
        cout<<"This key does not exists"<<endl;
        //return NULL;
    }
}

//verifica se o bucket ta cheio
int Bucket::isFull(void)
{
    if(keys.size()==2046)
        return 1;
    else
        return 0;
}

//verifica se o bucket está vazio
int Bucket::isEmpty(void)
{
    if(keys.size()==0)
        return 1;
    else
        return 0;
}

//retorna profundidade local do bucket
int Bucket::getDepth(void)
{
    return p;
}

//incrementa a profundidade local do bucket
int Bucket::increaseDepth(void)
{
    p++;
    return p;
}

//decrementa a profundidade local do bucket
int Bucket::decreaseDepth(void)
{
    p--;
    return p;
}

//faz uma copia do bucket
std::map<int, string> Bucket::copy(void)
{
    std::map<int, string> temp(keys.begin(),keys.end());
    return temp;
}
//limpa :-) 
void Bucket::clear(void)
{
    keys.clear();
}

//mostra :-)
void Bucket::mostra()
{
    std::map<int,string>::iterator it;
    for(it=keys.begin();it!=keys.end();it++)
        cout<<it->first<<" ";
    cout<<endl;
}