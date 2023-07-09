#pragma once
#include <list>
#include <iostream>
#include <memory>
#include <vector>

#include "CustomClass.h"

using namespace std;

class Content
{
    public:
    virtual Content& operator+=(int a) {}
    virtual Content& operator+=(string y) {}
    virtual void output(std::ostream& out){ //virtual function for output
        std::cout << "the operator is not supported for this type." << std::endl;
    }
};

class IntContent: public Content
{
private:
    int x;
public:
    IntContent(int _x): x(_x) {}
    void output(std::ostream& out){ //???
        out << x;
    }
    IntContent& operator+=(int a) override
    {
        x += a;
        return *this;
    }
};


class StringContent: public Content
{
private:
    std::string x;
public:
    StringContent(std::string _x): x(_x) {}
    void output(std::ostream& out){  //???
        out << x;
    }

    StringContent& operator+=(string a) override
    {
        x += a;
        return *this;
    }
};

class CustomContent: public Content
{
private:
    CustomClass x;
public:
    CustomContent(const CustomClass& _x): x(_x) {}
};

class Object
{
private:
    shared_ptr<Content> pt;

public:
    Object() {}
    Object(int x) {
        pt = make_shared<IntContent>(x); // where to delete? maybe use std::shared_ptr?
    }
    Object(const std::string &x){
        pt = make_shared<StringContent>(x);
    }
    Object(const std::vector<Object> &a);

    Object(const CustomClass &x){
        pt = make_shared<CustomContent>(x);
    }

    friend std::ostream& operator<<(std::ostream& out, const Object& obj) {
        obj.pt->output(out);
        return out;
    }

    Object& operator+=(int y){
        pt->operator+=(y);
        return *this;
    }
    Object& operator+=(const std::string &y){
        pt->operator+=(y);
        return *this;
    }
    Object& operator[](int);

    //need more operators......
};

class VectorContent: public Content
{
private:
    std::vector<Object> x; //Object is not defined???
public:
    VectorContent(const std::vector<Object>& _x): x(_x) {}
    Object & operator[](int a)
    {
        return x[a];
    }
};

Object& Object::operator[](int a)
{
    shared_ptr<VectorContent> ptr = dynamic_pointer_cast<VectorContent>(pt);
    return ptr->operator[](a);

}

Object::Object(const vector<Object> &a)
{
        pt = make_shared<VectorContent>(a);
}