#ifndef _ISDOUBLE_H_
#define _ISDOUBLE_H_

enum States {
    start,
    sign,
    intPart,
    point,
    frctPart,
    exponent,
    expSign,
    expValue
};

bool isDouble(char *&ch);


#endif
