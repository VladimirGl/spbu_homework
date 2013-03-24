#pragma once

#include <QtGui/QWidget>
#include <QtGui/QPushButton>
#include <QtCore/QSignalMapper>

#include "calculator.h"

namespace Ui {
class Widget;
}

/// Widget class.
class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    
private:
    Calculator calculator;

    QSignalMapper* signalMapper;

    Ui::Widget *ui;

private slots:

    void reset();

    void clicked(const QString& str);
    void calculate();
};
