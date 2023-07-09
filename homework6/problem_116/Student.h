#pragma once
#include <iostream>

using namespace std;

class Student{
    public:
    int type;

};

class StudentTypeA: public Student{
    public:
    StudentTypeA(){
        type = 1;
    }
};

class StudentTypeB: public Student{
    public:
    StudentTypeB(){
        type = 2;
    }
};

class StudentTypeC: public Student{
    public:
    StudentTypeC(){
        type = 3;
    }
};