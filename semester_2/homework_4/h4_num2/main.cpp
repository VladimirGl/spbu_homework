#include <QtGui/QApplication>
#include "widget.h"
#include "calculateTest.h"

int main(int argc, char *argv[])
{
    CalculateTest test;
    QTest::qExec(&test);
    QApplication a(argc, argv);
    Widget w;
    w.show();
    
    return a.exec();
}
