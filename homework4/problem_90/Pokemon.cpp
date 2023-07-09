#include "Pokemon.h"
#include <iostream>
using namespace std;

string Pokemon::get_name()
{
	return name;
}

int Pokemon::get_atk()
{
	return atk;
}

bool Pokemon::alive()
{
	return (hp > 0);
}

int Pokemon::get_hp()
{
	return hp;
}
Pokemon::~Pokemon()
{

}

void Pokemon::use_skill(int idx, Pokemon* target)
{

}



void Squirtle::use_skill(int idx, Pokemon* target)
{
	if(idx == 0)
	{
		hp += (int)(tot_hp / 5);
		if(hp > tot_hp)
			hp = tot_hp;
		cout << get_name() << " used Regen" << endl;
	}
	if(idx == 1)
	{
		cout << get_name() << " used Splash to " << target->get_name() << endl;
		target->hurt(atk, this);
	}
}

void Charizard::use_skill(int idx, Pokemon* target)
{
	if(idx == 0)
	{
		fire ++;
		atk *= 2;
		cout << get_name() << " used Ignite" << endl;
		hurt(fire * 10, this);
	}
	if(idx == 1)
	{
		cout << get_name() << " used Flame to " << target->get_name() << endl;
		target->hurt(atk, this);
	}
}

void Pokemon::hurt(int dmg, Pokemon* from)
{

}
void Squirtle::hurt(int dmg, Pokemon* from)
{
	if(hp <= tot_hp / 5)
	{
		dmg /= 2;
		if(dmg <= 1)
		dmg = 1;
	}
	hp -= dmg;
	cout << get_name() << " received " << dmg << " damage from " << from->get_name() << endl;
}

void Charizard::hurt(int dmg, Pokemon* from)
{
	hp -= dmg;
	cout << get_name() << " received " << dmg << " damage from " << from->get_name() << endl;
	if(from != this && dmg > 10)
	{
		from->hurt(dmg / 5, this);
	}
}