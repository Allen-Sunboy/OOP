#pragma once
#include <iostream>

using namespace std;

class Vehicle{
    public:
    int max_wheel;
    int max_wing;
    int cur_wheel = 0;
    int cur_wing = 0;
    void set_max_wheel_num(int i)
    {
        max_wheel = i;
    }
    void set_max_wing_num(int i)
    {
        max_wing = i;
    }
    void add_wing(){
        cur_wing++;
    }
    void add_wheel(){
        cur_wheel++;
    }
    bool finished()
    {
        if (cur_wheel == max_wheel && cur_wing == max_wing)
        {
            return true;
        }
        else
            return false;
    }
    virtual void run(){
        cout << "I am running" << endl;
    }

};

