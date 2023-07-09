#pragma once
#include <string>

class PayStrategy {								
    double pay(std::string name, double money)
};


class NormalStrategy : public PayStrategy {	

};

class SwiftStrategy : public PayStrategy {	

};

class BitcoinStrategy : public PayStrategy {	

};
