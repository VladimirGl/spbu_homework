#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    QObject::connect(ui->firstValue,
                     SIGNAL (valueChanged(int)),
                     this,
                     SLOT (showAnswer()));
    QObject::connect(ui->secondValue,
                     SIGNAL (valueChanged(int)),
                     this,
                     SLOT (showAnswer()));
    QObject::connect(ui->operation,
                     SIGNAL (currentIndexChanged(int)),
                     this,
                     SLOT (showAnswer()));
}

void Widget::showAnswer()
{
    ui->answer->setText(QString::number(calcIt.calculate(
        ui->firstValue->value(),
        ui->secondValue->value(),
        Operators(ui->operation->currentIndex())
    )));
}

Widget::~Widget()
{
    delete ui;
}
