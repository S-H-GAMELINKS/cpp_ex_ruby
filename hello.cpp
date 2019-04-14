#include <iostream>
#include "hello.hpp"

Hello::Hello(int var) {
    std::cout << "Create Hello Object!" << std::endl;
    this->var = var;
}

Hello::~Hello() {
    std::cout << "Delete Hello Object!" << std::endl;
}

void Hello::sayHello() {
    std::cout << "Var is " << this->var << std::endl;
}