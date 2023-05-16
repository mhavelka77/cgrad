/*
engine.hpp
Author: Martin Havelka

This file contains the definitions of all core structures.

Operations:

0 - unassigned
1 - addition
2 - substraction
3 - multiplication
4 - relu

*/

#include <iostream>

struct Value {
    public:
        float value;
        uint8_t operation = 0;
        float gradient = 0;
        Value *lhs = NULL;
        Value *rhs = NULL;

        Value(float value);
        void backward(bool first);
};



std::ostream &operator<<(std::ostream &os, Value &v);
Value operator*(Value &lhs, Value &rhs);
Value operator*(float lhs, Value &rhs);
Value operator*(Value &lhs, float rhs);
Value operator+(Value &lhs, Value &rhs);
Value operator+(float lhs, Value &rhs);
Value operator+(Value &lhs, float rhs);
Value operator-(Value &lhs, Value &rhs);
Value operator-(float lhs, Value &rhs);
Value operator-(Value &lhs, float rhs);
Value relu(Value lhs);