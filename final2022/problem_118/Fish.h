#include "Animal.h"

#include <iostream>
using namespace std;
class Fish: public Animal{
    public:
    Fish(int c):Animal(c){
        t = 1;
        // cout << t << endl;
    }
    void swim(){
        // cout << t << endl;
        if(t == 1)
        cout << colorstr << " fish is swimming." << endl;
        
    }
    void sing(){
        // cout << t << endl;
        if(t == 1)
        cout << "Fish can not sing." << endl;
    }
    ~Fish(){
        cout << colorstr <<  " fish is gone." << endl;
    }

};
