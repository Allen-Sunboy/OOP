#include "Fraction.h"
#include <iostream>
using namespace std;

long long gcd(long long a, long long b)
{
    return b==0 ? a : gcd(b, a%b);
}

ostream& operator<<(ostream& out, const Fraction & c)
{

    if(c.fenzi == 0)
    {
        out << 0 << endl;
        // return out;
    }
    if(c.fenmu == 1)
    {
        out << c.fenzi << endl;
        // return out;
    }
    out << c.fenzi << "/" << c.fenmu << endl;
    // out << "hao" << endl;
    return out;
}