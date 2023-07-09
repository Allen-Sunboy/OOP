#include <iostream>
#include "smithing_stone.h"

using namespace std;

class SomberSmithingStone: public SmithingStone{

    public:
    SomberSmithingStone(int level): SmithingStone(level){
        cout << "Somber smithing stone " << level << " was created." << endl;
    }
    ~SomberSmithingStone(){
        cout << "Somber smithing stone " << get_level() << " was destroyed." << endl;
    }
    void ss_add_amount(int amount){
        add_amount(amount);
        cout << "Somber smithing stone " << get_level() << " was added with " << amount << "." << endl;
    }
    void ss_sub(int amount){
        add_amount(-amount);
        cout << "Somber smithing stone " << get_level() << " was substracted with " << amount  << "." << endl;
    }
    bool ss_greater_equal(int need){
        return greater_equal(need);
    }

};