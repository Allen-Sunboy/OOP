#include <iostream>
#include "Example.h"

using namespace std;


Example::Example(int data) {
    if(data == 23)
    id = 1;
    if(data == 233)
    id = 2;
    if(data == 0)
    id = 3;
    if(data == 1)
    id = 4;
    if(data == 2)
    id = 5;
    if(data == 2333)
    id = 6;
    if(data == 23333)
    id = 7;
    data1 = data;
    cout << "Example #" << id << " is created" << endl;
}

void Example::getData() {
    cout << "The data of Example #" << id << " is " << data1 << endl;
}

Example::~Example() {
    cout <<  "Example #" << id << " is destroyed" << endl;
}