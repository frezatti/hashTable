#ifndef HASHTABLE_H
#define HASHTABLE_H
#include<hashtableTemplate.h>
template<class K, class T>
class HashTable:public HashTableTem<K,T>
{
public:
    HashTable(int size, int colisions):HashTableTem<K,T>(size,colisions){}

    K hash(K key)override {
        return key% this->size;
    }
};

#endif // HASHTABLE_H
