#pragma once
#include "card.h"
#include "king.h"
#include "soldier.h"

using namespace std;

class Beggar: public Card{
    public:
    Beggar(): Card("beggar"){}
    int battle(Card*other)
    {
        if(other->name()=="king")
            return 1;
        if(other->name()=="soldier")
            return -1;
    }
};