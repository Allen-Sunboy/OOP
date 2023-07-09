#pragma once
#include "card.h"
#include "soldier.h"
#include "beggar.h"
using namespace std;

class King: public Card{
    public:
    King(): Card("king"){}
    int battle(Card * other){
        if(other->name() == "soldier")
        {
            return 1;
        }
        if(other->name() == "beggar")
        {
            return -1; //maybe??
        }
        
    }


};