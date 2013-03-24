#ifndef TESTCALCULATE_H
#define TESTCALCULATE_H

#include <QObject>
#include <QtTest/QtTest>

#include "stackCalculate.h"

class TestCalculate : public QObject
{
    Q_OBJECT
public:
    TestCalculate()
    {}
    
private slots:

    void testIsCorrectExpression()
    {
        Parser *string = new Parser("2+2*2");
        QVERIFY(string->isCorrectExpression());
        delete string;
    }

    void testTranslteIntoPolish()
    {
        TranslateIntoPolish *object = new TranslateIntoPolish(array, "2+2*2");
        delete object;
    }

    void testCalculateSimple()
    {
        PostfixCalculator *object = new PostfixCalculator(array, "2+2*2");
        QVERIFY(object->calculate() == 6);
        delete object;
    }

    void testCalculateBigExpression()
    {
        PostfixCalculator *object = new PostfixCalculator(array, "2+2*2-3*(5+6/3-12)+13-6*3+(2+2*2+(2+2*2+(2+2*2)))");
        QVERIFY(object->calculate() == 34);
        delete object;
    }

};

#endif // TESTCALCULATE_H
