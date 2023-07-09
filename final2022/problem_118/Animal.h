#pragma once
#include <iostream>

using namespace std;

class Animal{
    public:
    int t;
    string type;
    int color;
    string colorstr;
    Animal(int c): color(c){
        if(c == 0)
        colorstr = "Red";
        if(c == 1)
        colorstr = "Blue";

    }
    virtual void sing() = 0;
    virtual void swim() = 0;
    virtual ~Animal(){}

};
