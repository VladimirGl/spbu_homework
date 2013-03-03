#pragma once

#include "stack.h"


class PointerStack: public Stack {
public:
    PointerStack();
    void push(double value);
    double top() const;
    void pop();
    bool isEmpty() const;
    ~PointerStack();
protected:
    struct StackElement {
        double value;
        StackElement *next;
        
    StackElement(StackElement * nextElement, double x = 0) :
            value(x),
            next(nextElement)
        {}
    };
    StackElement *stack;
    StackElement *createElement(double value);
};
