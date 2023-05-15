/*
engine.cpp
Author: Martin Havelka

This file contains the implementation of all core structures.
*/
#include "engine.hpp"

Value::Value(int32_t value) {
    this->value = value;
    this->backward = [&](){};
}

Value operator+(Value &lhs, Value &rhs) {
    Value v(lhs.value + rhs.value);
    v.firstChild = &lhs;
    v.secondChild = &rhs;

    v.backward = [&]() {
        lhs.gradient += v.gradient;
        rhs.gradient += v.gradient;
        lhs.backward();
        rhs.backward();
    };
    
    return v;
}

Value operator+(Value &lhs, int rhs) {
    Value right(rhs);
    return lhs + right;
}

Value operator+(int lhs, Value &rhs) {
    return rhs + lhs;
}

Value operator*(Value &lhs, Value &rhs) {
    Value v(lhs.value * rhs.value);
    v.firstChild = &lhs;
    v.secondChild = &rhs;

    v.backward = [&]() {
        lhs.gradient += v.gradient * rhs.value;
        rhs.gradient += v.gradient * lhs.value;
        lhs.backward();
        rhs.backward();
    };

    return v;
}

Value operator*(int lhs, Value &rhs) {
    Value left(lhs); 
    return left * rhs;
}

Value operator*(Value &lhs, int rhs) {
    Value right(rhs);
    return lhs * right;
}

Value operator-(Value &lhs, Value &rhs) {
    Value v(lhs.value - rhs.value);
    v.firstChild = &lhs;
    v.secondChild = &rhs;

    v.backward = [&]() {
        lhs.gradient += v.gradient;
        rhs.gradient -= v.gradient;
        lhs.backward();
        rhs.backward();
    };
    
    return v;
}

Value operator-(int lhs, Value &rhs) {
    Value left(lhs);
    return left - rhs;
}

Value operator-(Value &lhs, int rhs) {
    return rhs - lhs;
}

std::ostream & operator<<(std::ostream &os, Value &v) {
    os << v.value;
    return os; 
}
