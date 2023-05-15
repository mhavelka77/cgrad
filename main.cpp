/*
main.cpp
Author: Martin Havelka

This file demonstrates the capability of the cgrad.
*/

#include "engine.hpp"



int main() {

    Value a(8);
    Value b(2);
    
    Value c = a / b;

    c.backward(true); // should be -2
    std::cout << b.gradient << std::endl;
}