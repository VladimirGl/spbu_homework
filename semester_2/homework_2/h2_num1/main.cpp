#include <QtCore/QCoreApplication>

#include "testList.h"

int main()
{
    TestList test;
    QTest::qExec(&test);
    return 0;
}
