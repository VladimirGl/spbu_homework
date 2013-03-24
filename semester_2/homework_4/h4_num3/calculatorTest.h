#pragma once

#include <QtCore/QObject>
#include <QtTest/QtTest>

#include "calculator.h"

class CalculatorTest : public QObject
{
    Q_OBJECT
public:
    explicit CalculatorTest(QObject*parent = 0)
        : QObject(parent) {}

private slots:
    void init()
    {
        calculator = new Calculator;
    }

    void cleanup()
    {
        delete calculator;
    }

    void testChangeExpresion()
    {
        calculator->changeExpresion("2");
        QVERIFY(calculator->returnExpression() == "2");
        calculator->changeExpresion("+");
        calculator->changeExpresion("3");
        calculator->changeExpresion("4");
        QVERIFY(calculator->returnExpression() == "34");
    }

    void testClearAndChange()
    {
        calculator->changeExpresion("3");
        calculator->changeExpresion("4");
        QVERIFY(calculator->returnExpression() == "34");
        calculator->reset();
        QVERIFY(calculator->returnExpression() == "");
    }

    void testCalculateAndChange()
    {
        calculator->changeExpresion("2");
        calculator->changeExpresion("*");
        calculator->changeExpresion("3");
        calculator->changeExpresion("4");
        calculator->calculate();
        QVERIFY(calculator->returnExpression() == "68");
    }

private:
    Calculator* calculator;
};
