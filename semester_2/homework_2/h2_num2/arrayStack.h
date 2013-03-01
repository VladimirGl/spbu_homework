#pragma once

#include "stack.h"

class ArrayStack: public Stack {
public:
    ArrayStack();
    void push(int value);
    void pop();
    int top() const;
    ~ArrayStack();
protected:
    int **arrayStack;
    int arrayCounter;
    int arraySize;
    int findHole() const;
    bool isEmpty() const;
    void increaseArray();
};
