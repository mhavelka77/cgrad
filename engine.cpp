/*
engine.cpp
Author: Martin Havelka

This file contains the implementation of all core structures.
*/
#include "engine.hpp"

void Value::backward() {
    if (this->operation == 1) {
        this->lhs->gradient += this->gradient;
        this->rhs->gradient += this->gradient;
    } else if (this->operation == 2) {
        this->lhs->gradient += this->gradient;
        this->rhs->gradient -= this->gradient;
    } else if (this->operation == 3) {
        this->lhs->gradient += this->gradient * this->rhs->value;
        this->rhs->gradient += this->gradient * this->lhs->value;
    } else if (this->operation == 4) {
        //todo
    }


    if (this->lhs->operation != 0) {
        this->lhs->backward();
    }
    if (this->rhs->operation != 0) {
        this->rhs->backward();
    }
}

Value::Value(int32_t value) {
    this->value = value;
}

Value operator+(Value &lhs, Value &rhs) {
    Value v(lhs.value + rhs.value);
    v.lhs = &lhs;
    v.rhs = &rhs;
    v.operation = 1;
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
    v.lhs = &lhs;
    v.rhs = &rhs;
    v.operation = 3; 
    return v;
}

Value operator*(int lhs, Value &rhs) {
    Value left(lhs); 
    return left * rhs;
}

Value operator*(Value &lhs, int rhs) {
    Value right(rhs);
    return right * lhs;
}

Value operator-(Value &lhs, Value &rhs) {
    Value v(lhs.value - rhs.value);
    v.lhs = &lhs;
    v.rhs = &rhs;
    v.operation = 2;
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
