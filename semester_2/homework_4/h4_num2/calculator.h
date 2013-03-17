#ifndef CALCULATOR_H
#define CALCULATOR_H


/**
 * @file calculator.h
 *
 * @section DESCRIPTION
 *
 * This is implementation of Calculator class.
 */

enum Operators
{
    plus = 0,
    minus,
    mult,
    dvn
};

class Calculator
{
public:
    Calculator():
        leftValue(0),
        rightValue(0),
        operation(plus),
        answer(0)
    {}

    float calculate(int newLeftValue, int newRightValue, Operators newOperation);

protected:
    int leftValue;
    int rightValue;
    Operators operation;
    float answer;

    void getAnswer();
};

#endif // CALCULATOR_H
