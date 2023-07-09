#include <iostream>
#include "weapon.h"

using namespace std;

class NormalWeapon: public Weapon{

    public:
    NormalWeapon(string name): Weapon(name){
        cout << "Normal weapon " << name << " was created." << endl;
    }
    ~NormalWeapon(){
        cout << "Normal weapon " << get_name();
        if(get_level() != 0)
            cout << "+" << get_level();
        cout << " was destroyed." << endl;
    }
    string nw_get_name(){
        return get_name();
    }
    int nw_get_level(){
        return get_level();
    }
    void nw_upgrade(){
        upgrade();
        cout << "Normal weapon " << get_name();
        if(get_level() - 1 != 0)
            cout << "+" << get_level() - 1;
        cout << " was upgraded to " << get_name() << "+" << get_level()  << "." << endl;
    }

};
