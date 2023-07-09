#include <iostream>
#include "smithing_stone.h"

using namespace std;

class NormalSmithingStone: public SmithingStone{

    public:
    NormalSmithingStone(int level): SmithingStone(level){
        cout << "Normal smithing stone " << level << " was created." << endl;
    }
    ~NormalSmithingStone(){
        cout << "Normal smithing stone " << get_level() << " was destroyed." << endl;
    }
    void ns_add_amount(int amount){
        add_amount(amount);
        cout << "Normal smithing stone " << get_level() << " was added with " << amount  << "." << endl;
    }
    void ns_sub(int amount){
        add_amount(-amount);
        cout << "Normal smithing stone " << get_level() << " was substracted with " << amount << "." << endl;
    }
    bool ns_greater_equal(int need){
        return greater_equal(need);
    }

};