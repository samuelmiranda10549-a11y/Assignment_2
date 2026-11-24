#ifndef STACK_HPP
#define STACK_HPP

#include "StackNode.hpp"

class Stack {
    StackNode* top;
    unsigned int var_length;
public:
    Stack();
    ~Stack();

    void push(RGBPixelXY* pixel);
    RGBPixelXY* pop();
    bool isEmpty();
    StackNode* getTop();
    void makenull();
    unsigned int length();
};

#endif // STACK_HPP