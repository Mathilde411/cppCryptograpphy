//
// Created by mathilde on 28/04/24.
//

#include <iostream>
#include "crypto/BigInt.hpp"



class Test {
public:
    Test();
    ~Test();
    int num;
    static int NUM;
};

int Test::NUM = 0;

Test::Test() {
    num = Test::NUM++;
    std::cout << "Test " << num << " created" << std::endl;
}

Test::~Test() {
    std::cout << "Test " << num << " deleted" << std::endl;
}


Test testRetour() {
    Test t;
    std::cout << "Hi test !" << std::endl;
    return t;
}

int main() {
    Test t = testRetour();
    std::cout << "Hi main !" << std::endl;
}