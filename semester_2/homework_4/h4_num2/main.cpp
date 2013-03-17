#include <QtGui/QApplication>
#include "widget.h"
#include "calculateTest.h"


/**
 * @file main.cpp
 * @author  Vladimir Glazachev <glazachev.vladimir@gmail.com>
 *
 * @section DESCRIPTION
 *
 * This is a simple calculator program.
 */

int main(int argc, char *argv[])
{
    CalculateTest test;
    QTest::qExec(&test);
    QApplication a(argc, argv);
    Widget w;
    w.show();
    
    return a.exec();
}
