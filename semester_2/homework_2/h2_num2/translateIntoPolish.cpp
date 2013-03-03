#include <iostream>

#include <string.h>

#include "translateIntoPolish.h"

using namespace std;

TranslateIntoPolish::TranslateIntoPolish(StackType type, char *ch) {
    switch (type) {
        case (array): {
            stack = new ArrayStack;
            break;
        }
        case (pointer): {
//            stack = new PointerStack;
            break;
        }
    }
    inString = ch;
}

int TranslateIntoPolish::priority(int a) const {
    char ch = (char)a;
    if (ch == '*') return 4;
    if (ch == '/') return 4;
    if (ch == '+') return 2;
    if (ch == '-') return 3;
    if (ch == '(') return 1; 
    if (ch == ')') return 1;
    return 0;
}

bool TranslateIntoPolish::isOperator() const {
    if (*inString == '*') return true;
    if (*inString == '/') return true;
    if (*inString == '+') return true;
    if (*inString == '-') return true;
    return false;
}

void addSign(char *&inString, char *&outString, int &counter) {    
   if (*inString == '+')
        inString++;
    else if (*inString == '-') {
            outString[counter] = '-';
            counter++;
            inString++;
    }
}

char *TranslateIntoPolish::translator() {
    char *outString = new char[500];
    for (int i = 0; i < 500; i++) 
        outString[i] = 0;
    int counter = 0;
    addSign(inString, outString, counter);
    while (*inString != '\0') {
        if (*inString == '(') {
            stack->push((int)*inString);
            inString++;
            addSign(inString, outString, counter);
        } else {
            if (isOperator()) {
                while (!(stack->isEmpty()) && (priority(stack->top()) > priority((int)*inString))) {
                    outString[counter] = (char)stack->top();
                    counter++;
                    outString[counter] = ' ';
                    counter++;
                    stack->pop();
                }
                stack->push((int)*inString);
                inString++;
            } else {
                if (*inString == ')') {
                    while (!(stack->isEmpty()) && (char)(stack->top()) != '(') {
                        outString[counter] = (char)stack->top();
                        counter++;
                        outString[counter] = ' ';
                        counter++;
                        stack->pop();
                    }
                    stack->pop();
                    inString++;
                } else {
                    while (isdigit(*inString)) {
                        outString[counter] = *inString;
                        counter++;
                        inString++;
                    }
                    outString[counter] = ' ';
                    counter++;
                }
            }
        }
    }
    while (!(stack->isEmpty())) {
        outString[counter] = (char)stack->top();
        counter++;
        outString[counter] = ' ';
        counter++;
        stack->pop();
    }
    return outString;
}

TranslateIntoPolish::~TranslateIntoPolish() {
    delete stack;
}
