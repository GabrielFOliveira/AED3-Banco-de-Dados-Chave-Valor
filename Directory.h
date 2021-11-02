#ifndef DIRECTORY_H_INCLUDED
#define DIRECTORY_H_INCLUDED
#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include "Bucket.h"

class Directory {
        int pglobal, bucket_size;
        std::vector<Bucket*> buckets;
        int hash(int n);
        int pairIndex(int bucket_no, int profundidade);
        void crescer(void);
        void diminuir(void);
        void split(int bucket_no);
        void merge(int bucket_no);
        string bucket_id(int n);
    public:
        Directory(int profundidade, int bucket_size);
        void insert(int key,string valor,bool reinserido);
        void remove(int key,int mode);
        void update(int key, string valor);
        void search(int key);
        void mostra(bool duplicates);
};

#endif