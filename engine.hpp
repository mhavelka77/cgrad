/*
engine.hpp
Author: Martin Havelka

This file contains the definitions of all core structures.

Operations:

0 - unassigned
1 - addition
2 - substraction
3 - multiplication
4 - division

*/

#include <iostream>

struct Value {
    public:
        int32_t value;
        uint8_t operation = 0;
        int32_t gradient = 0;
        Value *lhs;
        Value *rhs;

        Value(int32_t value);
        void backward();
};



std::ostream &operator<<(std::ostream & os, Value &v);
Value operator*(Value & lhs, Value & rhs);
Value operator*(int lhs, Value & rhs);
Value operator*(Value & lhs, int rhs);
Value operator+(Value & lhs, Value & rhs);
Value operator+(int lhs, Value & rhs);
Value operator+(Value & lhs, int rhs);
Value operator-(Value & lhs, Value & rhs);
Value operator-(int lhs, Value & rhs);
Value operator-(Value & lhs, int rhs);
