#include <iostream>
#include <cstring>
#include "Map.h"
#include "Pair.h"

using namespace std;

Map::Map(int n)
{
    data = new Pair[n];
    sz = 0;
}

int & Map::operator[](string key)
{
    for(int i = 0; i < sz; i++)
    {
        if(data[i].hasKey(key))
            return data[i].getVal();
    }
    data[sz].reset(key, 0);
    sz++;
    return data[sz-1].getVal();
}

int Map::operator[](string key) const
{
    for(int i = 0; i < sz; i++)
    {
        if(data[i].hasKey(key))
            return data[i].getVal();
    }
    return 0;
}

Map::~Map()
{
    delete [] data;
}

int Map::size()
{
    return sz;
}
