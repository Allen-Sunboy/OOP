#include "Animal.h"
#include <iostream>
using namespace std;

class Bird: public Animal{
    public:
    Bird(int c): Animal(c){
        t = 0;
        // cout << t << endl;
        
    }
    ~Bird(){
        cout << colorstr << " bird is gone." << endl;

    }
    void sing(){
        // cout << t << endl;
        if(t == 0)
        cout << colorstr << " bird is singing." << endl;
    }
    void swim(){
        // cout << t << endl;
        if(t == 0)
        cout << "Bird can not swim." << endl;
    }

};