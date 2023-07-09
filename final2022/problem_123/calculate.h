#pragma once
#include <iostream>
#include "Fraction.h"
template<class A>
A calculate (char e, int x, int y, int z){


}

template<>
Fraction calculate(char e, int x, int y, int z){
    Fraction xx(x);
    Fraction yy(y);
    Fraction zz(z);
    return xx;


}

template<>
int calculate(char e, int ax, int ay, int az){
    if(e == 'A')
    {
        return ax * ax + ay * ay + az * az;
    }
    if(e == 'B')
    {
        return ax * ay + ay / az - ax * az;
    }
    if(e == 'C')
    {
        return ay * 3 * az - ax * az / (ay - 2) - ax * ay / (az + 1);
    }

}

