#include <iostream>
#include "Vector.h"


Vector::Vector(int n)
{
    capacity = n;
    array = new Node[capacity];
    len = 0;
    //
}

Vector::~Vector()
{
    delete [] array;
    //
}

Vector::Vector(const Vector & other)
{
    len = other.len;
    capacity = other.capacity;
    array = new Node[capacity];
    for(int i = 0; i < len; i++)
    {
        array[i] = other.array[i];
    }
}

Vector::Vector(Vector && other)
{
    array = other.array;
    len = other.len;
    capacity = other.capacity;
    other.array = nullptr;
}

Vector & Vector::operator=(const Vector & other)
{
    len = other.len;
    capacity = other.capacity;
    delete []array;
    array = new Node[other.capacity];
    for(int i = 0; i < len; i++)
    {
        array[i] = other.array[i];
    }
    return *this;
}


Vector & Vector::operator=(Vector && other)
{
    len = other.len;
    capacity = other.capacity;
    if(this != &other)
    {
        delete []array;
        array = other.array;
        other.array = nullptr;
        other.len = 0;
        other.capacity = 0;
    }
    return *this;
}

Node & Vector::operator[](int pos)
{
    return array[pos];
}



void Vector::append(int value)
{
    array[len] = value;
    len++;
}

void Vector::insert(int pos, int value)
{
    for(int i = len; i > pos; i--)
    {
        array[i] = std::move(array[i-1]);
    }
    array[pos] = value;
    len++;
}

void Vector::swap(int pos1, int pos2)
{
    Node a(std::move(array[pos1]));
    array[pos1] = std::move(array[pos2]);
    array[pos2] = std::move(a);

}

void Vector::dilatation()
{
    
    capacity *= 2;
    Node *twi = new Node[capacity];
    for(int i = 0; i < len; i++)
        twi[i] = std::move(array[i]);
    delete []array;
    array = twi;
}


int Vector::getlen()
{
    return len;
}

