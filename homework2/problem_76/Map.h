#pragma once
#include "Pair.h"

class Map{
    Pair * data;
    int sz;
public:
    Map(int n);
    // TODO
    int size();
    int& operator[](string key);
    int operator[](string key) const;
    ~Map();
};