#pragma once
#include <iostream>
#include <cmath>
using namespace std;

long long gcd(long long a, long long b);

class Fraction{
    public:
    long long fenzi;
    long long fenmu;

    void huajian()
    {
        long long g = gcd(abs(fenzi),abs(fenmu));
        fenzi /= g;
        fenmu /= g;


        // cout << "tect ";
        // cout << fenzi << " " << fenmu << endl;
    }
    Fraction(int in){
        fenzi = in;
        fenmu = 1;


        cout << fenzi << " " << fenmu << endl;
    }

    Fraction operator+(int x)
    {
        fenzi += x * fenmu;
        huajian();
        return *this;

    }
    Fraction operator-(int x)
    {
        fenzi -= x * fenmu;
        huajian();
        return *this;

    }
    Fraction operator*(int x)
    {
        fenzi *= x;
        huajian();
        return *this;
    }
    Fraction operator/(int x)
    {
        fenmu *= x;
        huajian();
        return *this;

    }

    Fraction operator+(Fraction& c)
    {
        Fraction aa(1);
        aa.fenmu = fenmu + c.fenmu;
        aa.fenzi = fenzi * c.fenmu + fenmu * c.fenzi;
        huajian();
        return aa;

    }
    Fraction operator-(Fraction& c){
        fenmu *= c.fenmu;
        fenzi = fenzi * c.fenmu - fenmu * c.fenzi;
        huajian();
        return *this;

    }
    Fraction operator*(Fraction& c){
        fenzi *= c.fenzi;
        fenmu *= c.fenmu;
        huajian();
        return *this;

    }
    Fraction operator/(Fraction c)
    {
        fenzi *= c.fenmu;
        fenmu *= c.fenzi;
        huajian();
        return *this;

    }
    friend ostream& operator<<(ostream& out, const Fraction & c);


};

