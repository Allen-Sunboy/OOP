#pragma once
#include <vector>
#include "animal.h"

using namespace std;


void action(Animal* animal, std::vector<Dog> & dogzone, std::vector<Bird> & birdzone)
{
    auto ndog = dynamic_cast<Dog*>(animal);
    auto nbird = dynamic_cast<Bird*>(animal);
    if(ndog)
    {
        // auto n1 = move(*ndog);
        dogzone.push_back(move(*ndog));
    }
    else if(nbird)
    {
        // auto n2 = move(*nbird);
        birdzone.push_back(move(*nbird));
    }

}