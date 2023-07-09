#pragma once

#include "Student.h"
#include <iostream>
#include <vector>

bool isprime(int n)
{
    for(int i = 2; i * i <= n; i++)
    {
        if(n % i == 0)
            return 0;
    }
    return 1;
}

vector<int> select(vector<int> credit, int l, int r, Student *student)
{
    vector<int> result;
    int ty = student->type;
    for(int i = l-1; i < r; i++)
    {
        if(ty == 1)
        {
            if(credit[i] <= 2)
                result.push_back(i+1);
        }
        if(ty == 2)
        {
            if(i+1 != 1 && isprime(i+1))
                result.push_back(i+1);
        }
        if(ty == 3)
        {
            if((i+1) % credit[i] == 0)
                result.push_back(i+1);
        }
        
    }
    return result;

}