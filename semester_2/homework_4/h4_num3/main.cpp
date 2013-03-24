#include <QtGui/QApplication>

#include "widget.h"
#include "calculatorTest.h"

 /**
 * @file main.cpp
 *
 * @section DESCRIPTION
 *
 * Advanced button calculator.
 */

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
/*
    CalculatorTest test;
    QTest::qExec(&test);
*/
    Widget w;
    w.show();

    return a.exec();
}
