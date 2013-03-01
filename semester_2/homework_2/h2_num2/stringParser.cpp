#include <iostream>

#include "stringParser.h"

Parser::Parser(char *ch) {
    string = ch;
    brCounter = 0;
}

bool isSign(char ch) {
    return (ch == '-') || (ch == '+');
}

bool Parser::isCorrectExpression() {
    if (isSign(*string))
        string++;
    return addition();
}

bool Parser::isNumber() {
    bool isNum = false;
    if (isdigit(*string))
        isNum = true;
    while (isdigit(*string))
        string++;
    return isNum;
}

bool Parser::addition() {
    if (!multiplication())
        return false;
    while (*string == '+' || *string == '-') {
        string++;
        if (!multiplication())
            return false;
    }
    if (brCounter > 0) {
        if (*string != ')')
            return false;
    } else
         if (*string != 0)
         return false;	        
    return true;
}

bool Parser::bracket() {
    if (*string == '(') {
        brCounter++;
        string++;
        if (isSign(*string))
            string++;
        if (!addition())
            return false;
        if (*string == 0)
            return false;
        if (*string == ')')
            brCounter--;
        else
            return false;
        string++;
        return true;
    } else
        return isNumber();
}

bool Parser::multiplication() {
    if (!bracket())
        return false;
    while (*string == '*' || *string == '/') {
        string++;
        if (!bracket())
            return false;
    }
    return true;
}


     
