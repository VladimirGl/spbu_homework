#include <QtGui/QApplication>
#include "widget.h"

/**
 * @file main.cpp
 *
 * @author  Vladimir Glazachev <glazachev.vladimir@gmail.com>
 *
 * @brief Implementation of an analog clock with alarm.
 */

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Widget w;
    w.show();

    return a.exec();
}
