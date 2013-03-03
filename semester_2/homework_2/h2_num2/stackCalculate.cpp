#include <iostream>
#include <float.h>
#include <string.h>

#include "stackCalculate.h"

using namespace std;

PostfixCalculator::PostfixCalculator(StackType type, char *ch) {
    switch (type) {
        case (array): {
            stack = new ArrayStack;
            break;
        }
        case (pointer): {
            stack = new PointerStack;
            break;
        }
    }
    Parser *string = new Parser(ch);
    isExpression = string->isCorrectExpression();
    delete string;
    TranslateIntoPolish *object = new TranslateIntoPolish(array, ch);
    expression = object->translator();
    delete string;
}

char *PostfixCalculator::readToSpace() {
    char *value = new char[25];
    for (int i = 0; i < 25; i++)
        value[i] = 0;
    int counter = 0;
    while (*expression != ' ' && *expression != '\0') {
        value[counter] = *expression;
        counter++;
        expression++;
    }
    if (*expression != '\0')
        expression++;
    return value;
}

int state(string ch) {
    if (ch == "+")
        return 2;
    if (ch == "-")
        return 3;
    if (ch == "*")
        return 4;
    if (ch == "/")
        return 5;
    return 1;
}

double PostfixCalculator::calculate() {
    if (!isExpression) {
        return (DBL_MAX);
    }
    char *ch = readToSpace();   
    while (true) {
        switch (state(ch)) {
            case pls: {
                double value1 = stack->top();
                stack->pop();
                double value2 = stack->top();
                stack->pop();
                double result = value2 + value1;
                stack->push(result);
                break;
            }
            case mns: {
                double value1 = stack->top();
                stack->pop();
                double value2 = stack->top();
                stack->pop();
                double result = value2 - value1;
                stack->push(result);
                break;
            }
            case mlt: {
                double value1 = stack->top();
                stack->pop();
                double value2 = stack->top();
                stack->pop();
                double result = value2 * value1;
                stack->push(result);
                break;
            }
            case dvn: {
                double value1 = stack->top();
                stack->pop();
                double value2 = stack->top();
                stack->pop();
                double result = value2 / value1;
                stack->push(result);
                break;
            }
            case num: {
                stack->push(atoi(ch));
                break;
            }
        }
        if (*expression == '\0')
            return (stack->top());
        ch = readToSpace();
    }
}

PostfixCalculator::~PostfixCalculator() {
    delete stack;
}
