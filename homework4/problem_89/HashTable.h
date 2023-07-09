#pragma once
#include <string>
#include "Hash.h"

template <typename T1, typename T2>
class HashTable
{
public:
    T2 table[6000];
    bool exist[50000];
    int num;
    HashTable(int num1) : num(num1){};
    void addItem(const T1 &key, const T2 &value);
    void removeItem(const T1 &key);
    T2 *findByKey(const T1 &key);
};

template <typename T1, typename T2>
void HashTable<T1, T2>::addItem(const T1 &key, const T2 &value)
{
    Hash<T1> te(num);
    table[te(key)] = value;
    exist[te(key)] = 1;
}


template <typename T1, typename T2>
void HashTable<T1, T2>::removeItem(const T1 &key)
{
    Hash<T1> te(num);
    exist[te(key)] = 0;
}

template <typename T1, typename T2>
T2 * HashTable<T1, T2>::findByKey(const T1 &key)
{
    Hash<T1> te(num);
    //std::cout << "oiejf  " << te(key) << std::endl;
    if(exist[te(key)])
        return &table[te(key)];
    else
        return nullptr;
    
}