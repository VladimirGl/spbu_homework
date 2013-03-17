#include "calculator.h"

void Calculator::getAnswer()
{
    switch (operation)
    {
    case (plus):
    {
        answer = leftValue + rightValue;
        break;
    }
    case (minus):
    {
        answer = leftValue - rightValue;
        break;
    }
    case (mult):
    {
        answer = leftValue * rightValue;
        break;
    }
    case (dvn):
    {
        if (rightValue == 0)
            answer = 0;
        else
            answer = (float) leftValue / rightValue;
        break;
    }
    }
}

float Calculator::calculate(int newLeftValue, int newRightValue, Operators newOperation)
{
    leftValue = newLeftValue;
    rightValue = newRightValue;
    operation = newOperation;
    getAnswer();
    return answer;
}
