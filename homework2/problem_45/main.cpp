#include <iostream>
#include "Example.h"

using namespace std;

void create_example(int n) {
    
    cout << "--------create_example is ready--------\n";
    
    Example* e[10];
    
    for (int i = 0; i < n; i++)
        e[i] = new Example(i);
            
    static Example a6(2333);

    for (int i = 0; i < n; i++)
    {
        e[i]->getData();

    }
    delete e[0];
    delete e[1];
    delete e[2];
    a6.getData();
    
    cout << "--------create_example is over--------\n";
}

Example n1(23);

int main() {

    cout << "--------main_function is ready--------\n";

    Example n2(233);
        
    create_example(3);
    
    Example n7(23333);
    n1.getData();
    n2.getData();
    n7.getData();

    cout << "--------main_function is over---------\n";

    return 0;
}
