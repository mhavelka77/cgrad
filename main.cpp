/*
main.cpp
Author: Martin Havelka

This file demonstrates the capability of the cgrad.
*/

#include "engine.hpp"



int main() {

    Value a(-4);
    Value b(2);

    Value c = a - b;
    Value d = c * 4;
    d.gradient = 1;
    d.backward(); 

    std::cout << a.gradient << std::endl;
}