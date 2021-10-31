#ifndef BUCKET_H_INCLUDED
#define BUCKET_H_INCLUDED
#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

class Bucket {
        int p,size;
        map<int, string> keys;
    public:
        Bucket(int depth, int size);
        int insert(int key,string value);
        int remove(int key);
        int update(int key, string value);
        std::map <int, string> search(int key);
        int isFull(void);
        int isEmpty(void);
        int getDepth(void);
        int increaseDepth(void);
        int decreaseDepth(void);
        std::map<int, string> copy(void);
        void clear(void);
        void mostra(void);
};

#endif