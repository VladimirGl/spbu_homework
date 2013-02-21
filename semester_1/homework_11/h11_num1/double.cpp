#include <iostream>

#include "double.h"

bool isSign(char ch) {
    if (ch == '+' || ch == '-')
        return true;
    return false;
}

bool isExponent(char ch) {
     if (ch == 'e' || ch == 'E')
         return true;
     return false;
}

bool isDouble(char *&ch) {
    States state = start;
    while (true) {
        switch (state) {
            case start: {
                if (isSign(*ch))
                    state = sign;
                    else if (isdigit(*ch))
                        state = intPart;
                else
                    return false;
                break;
            }
            case sign:{
                if (isdigit(*ch))
                    state = intPart;
                else
                    return false; 
                break;
            }
            case intPart: {
                if (isdigit(*ch))
                    break;
                else if (*ch == '.')
                    state = point;
                else if (isExponent(*ch))
                    state = exponent;
                else
                    return true;
                break;
            }
            case point: {
                if (isdigit(*ch))
                    state = frctPart;
                else
                    return false;
                break; 
            }
            case frctPart: {
                if (isdigit(*ch))
                    break;
                else if (isExponent(*ch))
                    state = exponent;
                else
                    return true;
                break;
            }
            case exponent:  {
                if (isSign(*ch))
                    state = expSign;
                else if (isdigit(*ch))
                    state = expValue;
                else
                    return false;
                break;
            }
            case expSign: {
                if (isdigit(*ch))
                    state = expValue;
                else
                    return false;
                break;
            }
            case expValue: {
                if (isdigit(*ch))
                    break;
                else
                    return true;
                break;
            }
        }
        ch++;
    }
}
