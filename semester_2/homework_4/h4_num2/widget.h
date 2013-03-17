#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "calculator.h"

/**
 * @file widget.h
 *
 * @section DESCRIPTION
 *
 * This is implementation of Widget class.
 */

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT
    
public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

public slots:
    void showAnswer();

private:
    Ui::Widget *ui;
    Calculator calcIt;
};

#endif // WIDGET_H
