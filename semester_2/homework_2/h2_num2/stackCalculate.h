#pragma once

#include "translateIntoPolish.h"
#include "stringParser.h"

enum NumberOrOperator {
    num = 1,
    pls = 2,
    mns = 3,
    mlt = 4,
    dvn = 5
};

class PostfixCalculator {
public:
    PostfixCalculator(StackType type, char *ch);
    double calculate();
    ~PostfixCalculator();
protected:
    char *expression;
    Stack *stack;
    bool isExpression;
    char *readToSpace();
};
