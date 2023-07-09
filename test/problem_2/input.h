#pragma once
#include <iostream>
using namespace std;

class Input{
    public:
    int x;
    int y;
    Input(){
        int a;
        int b;
        cin >> a >> b;
        x = a;
        y = b;
    }

};