#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    QPushButton* button = new QPushButton("C");
    connect(button, SIGNAL(clicked()),
             this, SLOT(reset()));
    ui->gridLayout->addWidget(button, 0, 3);

    button = new QPushButton("=");
    connect(button, SIGNAL(clicked()),
            this, SLOT(calculate()));
    ui->gridLayout->addWidget(button, 4, 2);

    signalMapper = new QSignalMapper(this);
    for (int i = 1; i <= 9; ++i)
    {
        button = new QPushButton(QString::number(i));
        connect(button, SIGNAL(clicked()), signalMapper, SLOT(map()));
        signalMapper->setMapping(button, QString::number(i));
        ui->gridLayout->addWidget(button, (i - 1) / 3 + 1, (i -1) % 3);
    }

    button = new QPushButton(QString::number(0));
    connect(button, SIGNAL(clicked()), signalMapper, SLOT(map()));
    signalMapper->setMapping(button, QString::number(0));
    ui->gridLayout->addWidget(button, 4, 0);

    button = new QPushButton(".");
    connect(button, SIGNAL(clicked()),
            signalMapper, SLOT(map()));
    signalMapper->setMapping(button, ".");
    ui->gridLayout->addWidget(button, 4, 1);

    const int operatorsNum = 4;
    const char operators[operatorsNum] = {'+', '-', '*', '/'};
    for (int i = 0; i < operatorsNum; ++i)
    {
        QString bName = QChar(operators[i]);
        button = new QPushButton(bName);
        connect(button, SIGNAL(clicked()), signalMapper, SLOT(map()));
        signalMapper->setMapping(button, bName);
        ui->gridLayout->addWidget(button, i + 1 , 3);
    }

    connect(signalMapper, SIGNAL(mapped(const QString &)),
            this, SLOT(clicked(const QString &)));
}

Widget::~Widget()
{
    delete signalMapper;
    delete ui;
}

void Widget::reset()
{
    calculator.reset();
    ui->lineEdit->setText(calculator.returnExpression());
}

void Widget::clicked(const QString &str)
{
    calculator.changeExpresion(str);
    ui->lineEdit->setText(calculator.returnExpression());
}

void Widget::calculate()
{
    calculator.calculate();
    ui->lineEdit->setText(calculator.returnExpression());
}
