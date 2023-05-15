/*
engine.hpp
Author: Martin Havelka

This file contains the definitions of all core structures.

*/

#include <iostream>

struct Value {
    public:
        int32_t value;
        uint8_t operation = 0;
        int32_t gradient = 0;
        Value *firstChild;
        Value *secondChild;

        Value(int32_t value);
        std::function<void()> backward;
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
