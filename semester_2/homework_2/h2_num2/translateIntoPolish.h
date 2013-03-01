#pragma once

#include "arrayStack.h"
//#include "pointerStack.h"

class TranslateIntoPolish {
public:
    TranslateIntoPolish(StackType type, char *ch);
    char *translator();
    ~TranslateIntoPolish();
protected:
    char *inString;
    Stack *stack;
    int priority(int a) const;
    bool isOperator() const;
};

