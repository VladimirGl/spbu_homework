#pragma once

class Stack {
public:
    Stack() {};
    virtual void push(int value) = 0;
    virtual void pop() = 0;
    virtual int top() const = 0;
    virtual ~Stack() {};
};
