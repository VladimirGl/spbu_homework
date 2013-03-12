#include <QtGui/QApplication>
#include "widget.h"

/**
 * @file main.cpp
 * @author  Vladimir Glazachev <glazachev.vladimir@gmail.com>
 *
 * @section DESCRIPTION
 *
 * This is a program, in that you can play with a slider.
 */

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();
    
    return a.exec();
}
