#ifndef CALCULATETEST_H
#define CALCULATETEST_H

#include <QObject>
#include <QtTest/QtTest>
#include "calculator.h"

class CalculateTest : public QObject
{
    Q_OBJECT
public:
    explicit CalculateTest(QObject *parent = 0):
        QObject(parent) {}
    
private slots:
    void init()
    {
        calc = new Calculator;
    }

    void cleanup()
    {
        delete calc;
    }

    void testCreate() {};

    void testSum()
    {
        QVERIFY(calc->calculate(3, 5, plus) == 8);
    }

    void testSubtraction()
    {
        QVERIFY(calc->calculate(5, 9, minus) == -4);
    }

    void testMult()
    {
        QVERIFY(calc->calculate(2,7, mult) == 14);
    }

    void testDev()
    {
        QVERIFY(calc->calculate(8,4, dvn) == 2);
    }

private:
    Calculator *calc;
};


#endif // CALCULATETEST_H
