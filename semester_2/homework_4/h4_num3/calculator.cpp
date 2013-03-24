#include "calculator.h"

Calculator::Calculator()
{
    reset();
}

void Calculator::reset()
{
    expression = "";
    leftNumb = "";
    rightNumb = "";
    currentOpr = "";
    isHaveDot = false;
    needToChangeNumb = false;
}

QString Calculator::returnExpression()
{
    return expression;
}

void Calculator::changeExpresion(QString str)
{
    if ((str == "+") || (str == "-") || (str == "/") || (str == "*"))
    {
        calculate();
        needToChangeNumb = true;
        currentOpr = str;
    }
    else
    {
        if (str == ".")
        {
            if (!isHaveDot)
            {
                isHaveDot = true;
                rightNumb = rightNumb + ".";
                expression = rightNumb;
            }
        }
        else
        {
            if (needToChangeNumb)
            {
                needToChangeNumb = false;
                isHaveDot = false;
                leftNumb = rightNumb;
                rightNumb = str;
                expression = rightNumb;
            }
            else
            {
                rightNumb = rightNumb + str;
                expression = rightNumb;
            }
        }
    }
}

bool Calculator::isClear()
{
    return (((leftNumb != "") && (rightNumb != "") && (currentOpr != "")));
}

void Calculator::calculate()
{
    if (!isClear())
        return;

    float leftValue = leftNumb.toFloat();
    float rightValue = rightNumb.toFloat();
    char operation = (char)*currentOpr.toLatin1();
    float result = 0;

    switch (operation)
    {
    case '+':
    {
        result = leftValue + rightValue;
        break;
    }
    case '-':
    {
        result = leftValue - rightValue;
        break;
    }
    case '*':
    {
        result = leftValue * rightValue;
        break;
    }
    case '/':
    {
        result = leftValue / rightValue;
        break;
    }
    }

    if (result == (int)result)
        isHaveDot = false;
    else
        isHaveDot = true;

    rightNumb = QString::number(result);
    leftNumb = "";
    expression = rightNumb;
}
