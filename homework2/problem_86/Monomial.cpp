#include "Monomial.h"
#include <iostream>

using namespace std;

Monomial::Monomial()
{
    coe = 0;
    deg = 0;
}



istream& operator>>(istream& in, Monomial& x)
{
    in >> x.str;
    int p = 0;
    for(int i = 0; i < x.str.size(); i++)
        if(x.str[i] == 'x')
            p = i;
    int co = 0;
    int de = 0;
    int k1 = 1;
    int k2 = 1;
    for(int i = p-1; i >= 0; i--)
    {
        if(x.str[i] == '-')
        {
            co = -co;
            continue;
        }
            
        co += (x.str[i] - '0') * k1;
        k1 *= 10;
    }
    for(int i = x.str.size()-1; i >= p+2; i--)
    {
        if(x.str[i] == '-')
        {
            de = -de;
            continue;
        }
            
        de += (x.str[i] - '0') * k2;
        k2 *= 10;
    }
    x.coe = co; 
    x.deg = de;
    return in;
}

ostream& operator<<(ostream& out, Monomial& x)
{
    out << x.coe << "x^" << x.deg << endl;
    return out;
}

Monomial Monomial::operator+(const Monomial &x) const
{
    Monomial a;
    a.coe = x.coe + this->coe;
    a.deg = this->deg;
    if(a.coe==0)
    a.deg=0;
    return a;
}
Monomial Monomial::operator-(const Monomial &x) const
{
    Monomial a;
    a.coe = this->coe - x.coe;
    a.deg = this->deg;
    if(a.coe==0)
    a.deg=0;
    return a;
}

Monomial Monomial::operator*(const Monomial &x) const
{
    Monomial a;
    a.coe = this->coe * x.coe;
    a.deg = this->deg + x.deg;
    if(a.coe==0)
    a.deg=0;
    return a;
}

Monomial Monomial::operator/(const Monomial &x) const
{
    Monomial a;
    a.coe = this->coe / x.coe;
    a.deg = this->deg - x.deg;
    if(a.coe==0)
    a.deg=0;
    return a;
}

int Monomial::definite_integral(const int a, const int b) const
{
    Monomial xx;
    xx.coe = coe / (deg+1);
    xx.deg = deg + 1;
    
    int ya = 1;
    int yb = 1;
    if(xx.deg>=0)
    {
        for(int i = 0; i < xx.deg; i++)
            ya *= a;
        ya *= xx.coe;
        for(int i = 0; i < xx.deg; i++)
            yb *= b;
        yb *= xx.coe;
        return yb-ya;
    }
    else
    {
        for(int i = 0; i < -xx.deg; i++)
            ya *= a;
        ya = xx.coe / ya;
        for(int i = 0; i < -xx.deg; i++)
            yb *= b;
        yb = xx.coe / yb;
        return yb-ya;
    }


}

Monomial Monomial::derive() const
{
    Monomial a;
    a.coe = this->coe * this->deg;
    a.deg = this->deg - 1;
    if(deg==0)
    {
        a.coe = 0;
        a.deg = 0;
    }
    return a;
    
}

int Monomial::get_val(int x) const
{
    int val = 1;
    if(deg >= 0)
    {
        for(int i = 0; i < deg; i++)
        {
            val *= x;
        }
        return val * coe;
    }
    else
    {
        for(int i = 0; i < -deg; i++)
            val *= x;
        return coe / val;
    }
}