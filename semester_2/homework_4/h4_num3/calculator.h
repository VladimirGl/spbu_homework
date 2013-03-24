#pragma once
#include <QString>

/**
* @file widget.h
*
* @section DESCRIPTION
*
* Implementation of calculator class.
*/

class Calculator {
public:
    Calculator();

    /// Reset the calculator.
    void reset();

    void changeExpresion(QString expr);
    void calculate();

    QString returnExpression();
private:
    bool isClear();

    bool isHaveDot;
    bool needToChangeNumb;

    QString expression;

    QString rightNumb;
    QString leftNumb;

    QString currentOpr;
};
