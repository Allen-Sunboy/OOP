#pragma once
#include "card.h"
#include "king.h"
#include "beggar.h"
using namespace std;

class Soldier: public Card{
    public:
    Soldier(): Card("soldier"){}
    int battle(Card*other)
    {
        if(other->name()=="soldier")
            return 0;
        if(other->name()=="king")
            return -1;
        if(other->name()=="begger")
            return 1;
    }
};