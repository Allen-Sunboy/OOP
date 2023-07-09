#pragma once
#include "what.h"
using namespace std;

class Alien: public WhatCanMotion, public WhatCanSpeak{
    public:
    string s;
    Alien(string _s): s(_s){}
    virtual void motion()
    {
        cout << s << " is moving" << endl;
    }
    virtual void stop()
    {
        cout << s << " stops" << endl;
    }
    virtual void speak()
    {
        cout << s << " is speaking" << endl;
    }
};