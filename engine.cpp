/*
engine.cpp
Author: Martin Havelka

This file contains the implementation of all core structures.
*/
#include "engine.hpp"

// This method is recursively calling itself and applying the chain rule
void Value::backward(bool first) {
    if (first) {
        this->gradient = 1;
    }
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
        if (this->value > 0) {
            this->lhs->gradient = this->gradient;
        } else {
            this->lhs->gradient = 0;
        }
    } 

    if (this->lhs->operation != 0) {
        this->lhs->backward(false);
    }
    if (this->rhs != NULL && this->rhs->operation != 0) {
        this->rhs->backward(false);
    }
}

Value::Value(float value) {
    this->value = value;
}

Value operator+(Value &lhs, Value &rhs) {
    Value v(lhs.value + rhs.value);
    v.lhs = &lhs;
    v.rhs = &rhs;
    v.operation = 1;
    return v;
}

Value operator+(Value &lhs, float rhs) {
    Value right(rhs);
    return lhs + right;
}

Value operator+(float lhs, Value &rhs) {
    return rhs + lhs;
}

Value operator*(Value &lhs, Value &rhs) {
    int a =2;
    int b =2;
    Value v(lhs.value * rhs.value);
    v.lhs = &lhs;
    v.rhs = &rhs;
    v.operation = 3; 
    return v;
}

Value operator*(float lhs, Value &rhs) {
    Value left(lhs); 
    return left * rhs;
}

Value operator*(Value &lhs, float rhs) {
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

Value operator-(float lhs, Value &rhs) {
    Value left(lhs);
    return left - rhs;
}

Value operator-(Value &lhs, float rhs) {
    return rhs - lhs;
}

Value relu(Value v) {
    Value relued(0);
    if (v.value > 0) {
        relued.value = v.value; 
    }
    relued.lhs = &v;
    relued.operation = 4;
    return relued;
}

std::ostream & operator<<(std::ostream &os, Value &v) {
    os << "Value: " << v.value << std::endl << "Grad: " << v.gradient << std::endl;
    return os; 
}
