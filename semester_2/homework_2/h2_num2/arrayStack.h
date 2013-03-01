#pragma once

#include "stack.h"

class ArrayStack: public Stack {
public:
    ArrayStack();
    void push(int value);
    void pop();
    int top() const;
    bool isEmpty() const;
    ~ArrayStack();
protected:
    int **arrayStack;
    int arrayCounter;
    int arraySize;
    int findHole() const;
    void increaseArray();
};
