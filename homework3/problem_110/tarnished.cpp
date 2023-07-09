#include "tarnished.h"
#include <cstring>

using namespace std;

int nw_num = 0;
int sw_num = 0;

int nw_need[10];
bool ns_exist[10];
bool ss_exist[10];

Tarnished::Tarnished()
{
    
}

Tarnished::~Tarnished()
{
    for(int i = 1; i <= 8; i++)
    {
        if(ns_exist[i])
            delete normal_smithing_stones[i];
    }
    for(int i = 1; i <= 8; i++)
    {
        if(ss_exist[i])
            delete somber_smithing_stones[i];
    }
    for(int i = 0; i < nw_num; i++)
        delete normal_weapons[i];
    for(int i = 0; i < sw_num; i++)
        delete somber_weapons[i];

}

void Tarnished::pick_up_stone(int type, int level, int number)
{
    if(type == 0)
    {
        if(ns_exist[level] == 0)
        {
            normal_smithing_stones[level] = new NormalSmithingStone(level);
            ns_exist[level] = 1;
        }
        normal_smithing_stones[level]->ns_add_amount(number);

    }
    if(type == 1)
    {
        if(ss_exist[level] == 0)
        {
            somber_smithing_stones[level] = new SomberSmithingStone(level);
            ss_exist[level] = 1;
        }
        somber_smithing_stones[level]->ss_add_amount(number);
    }
}

void Tarnished::pick_up_weapon(int type, string name)
{
    if(type == 0)
    {
        normal_weapons[nw_num] = new NormalWeapon(name);
        nw_num++;

    }
    if(type == 1)
    {
        somber_weapons[sw_num] = new SomberWeapon(name);
        sw_num++;
    }

}

void Tarnished::upgrade_weapon(int target, string name)
{
    int nw_pose = -1;
    int sw_pose = -1;
    for(int i = 0; i < nw_num; i++)
    {
        if(name == normal_weapons[i]->nw_get_name())
        {
            nw_pose = i;
            break;
        }
    }
    if(nw_pose == -1)
    {
        for(int i = 0; i < sw_num; i++)
        {
            if(name == somber_weapons[i]->sw_get_name())
            {
                sw_pose = i;
                break;
            }
        }
    }
    if(nw_pose == -1 && sw_pose == -1)
    {
        cout << "You don't have the right!" << endl;
        return;
    }
    else if(nw_pose >= 0)
    {
        int nowlevel = normal_weapons[nw_pose]->nw_get_level();

        if(normal_weapons[nw_pose]->nw_get_level() >= target)
        {
            cout << "Stay calm!" << endl;
            return;
        }
        else
        {
            for(int i = nowlevel+1; i <= target; i++)
            {
                int currentlevel = (i-1)/3+1;
                //cout << "currentlevel " << currentlevel << endl;
                nw_need[currentlevel] += (i-1)%3*2 + 2;
                if( ns_exist[currentlevel] == 0 || normal_smithing_stones[currentlevel]->ns_greater_equal(nw_need[currentlevel]) == 0)
                {
                    cout << "Upgrade failed for lacking normal smithing stone " << currentlevel << "." << endl;
                    for(int i = 1; i <= currentlevel; i++)
                        nw_need[i] = 0;
                    memset(nw_need, 0, sizeof(nw_need));
                    return;
                }
            }
            memset(nw_need, 0, sizeof(nw_need));
            for(int i = nowlevel+1; i <= target; i++)
            {
                normal_smithing_stones[(i-1)/3+1]->ns_sub((i-1)%3*2 + 2);
                if(normal_smithing_stones[(i-1)/3+1]->ns_greater_equal(1) == 0)
                {
                    delete normal_smithing_stones[(i-1)/3+1];
                    ns_exist[(i-1)/3+1] = 0;
                }
                    
                normal_weapons[nw_pose]->nw_upgrade();
            }
            cout << "Upgrade " << name ;
            if(nowlevel != 0)
                cout << "+" << nowlevel;
            cout << " to " << name << "+" << target << " Successfully." << endl;

        }
    }
    else if(sw_pose >= 0)
    {
        int nowlevel = somber_weapons[sw_pose]->sw_get_level();
        if(nowlevel >= target)
        {
            cout << "Stay calm!" << endl;
            return;
        }
        else
        {
            //cout << "//////somber 3 null ?" << (somber_smithing_stones[3] == nullptr) << endl;
            for(int i = nowlevel+1; i <= target; i++)
            {
                //cout << "now i:" << i << endl;
                if( ss_exist[i] == 0 ||  somber_smithing_stones[i]->ss_greater_equal(1) == 0 )
                {
                    cout << "Upgrade failed for lacking somber smithing stone " << i << "." << endl;
                    return;
                }
            }
            for(int i = nowlevel+1; i <= target; i++)
            {
                somber_smithing_stones[i]->ss_sub(1);
                if(somber_smithing_stones[i]->ss_greater_equal(1) == 0)
                {
                    delete somber_smithing_stones[i];
                    ss_exist[i] = 0;
                }
                    
                somber_weapons[sw_pose]->sw_upgrade();
            }
            cout << "Upgrade " << name ;
            if(nowlevel != 0)
                cout << "+" << nowlevel;
            cout << " to " << name << "+" << target << " Successfully." << endl;
        }
    }

}