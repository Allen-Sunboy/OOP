#include <iostream>
#include "weapon.h"

using namespace std;

class SomberWeapon: public Weapon{

    public:
    SomberWeapon(string name): Weapon(name){
        cout << "Somber weapon " << name << " was created." << endl;
    }
    ~SomberWeapon(){
        cout << "Somber weapon " << get_name();
        if(get_level() != 0)
            cout << "+" << get_level();
        cout << " was destroyed." << endl;
    }
    string sw_get_name(){
        return get_name();
    }
    int sw_get_level(){
        return get_level();
    }
    void sw_upgrade(){
        upgrade();
        cout << "Somber weapon " << get_name();
        if(get_level() - 1 != 0)
            cout << "+" << get_level() - 1;
        cout << " was upgraded to " << get_name() << "+" << get_level()  << "." << endl;
    }



};