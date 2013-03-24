#include <QtCore/QCoreApplication>

#include "testSorter.h"


/**
 * @file main.cpp
 * @author  Vladimir Glazachev <glazachev.vladimir@gmail.com>
 *
 * @section DESCRIPTION
 *
 * This is a program, in that impelented various sorting.
 */

int main()
{
    TestSorter test;
    QTest::qExec(&test);
    return 0;
}
