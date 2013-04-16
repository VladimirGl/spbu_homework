#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget),
    btnMapper(new QSignalMapper(this))
{

    ui->setupUi(this);

    createButtons();
    connectButtons();
}

Widget::~Widget()
{
    delete[] ticTacBtn;
    delete btnMapper;
    delete ui;
}

void Widget::createButtons()
{
    int const btnMinSize = 30;
    int const btnMaxSize = 145;
    int const colRowCount = 3;

    ui->pushButton->setVisible(false);
    ui->pushButton_2->setVisible(false);

    for (int i = 0; i < numOfButtons; i++)
    {
        ticTacBtn[i] = new QPushButton(" ", this);
        ticTacBtn[i]->setMaximumSize(QSize(btnMaxSize, btnMaxSize));
        ticTacBtn[i]->setMinimumSize(QSize(btnMinSize, btnMinSize));
        ticTacBtn[i]->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        ui->gridLayout->addWidget(ticTacBtn[i], i / colRowCount, (i % colRowCount) + 2);
    }
}

void Widget::connectButtons()
{
    for (int i = 0; i < numOfButtons; i++)
    {
        btnMapper->setMapping(ticTacBtn[i], QString::number(i));
        connect(ticTacBtn[i], SIGNAL(clicked()), btnMapper, SLOT(map()));
    }

    connect(btnMapper, SIGNAL(mapped(QString)), this, SLOT(putSign(QString)));
    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(reset()));
    connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(reset()));

}

void Widget::putSign(QString newChar)
{
    ticTacBtn[newChar.toInt()]->setText(ticTac.setSign(newChar.toInt()));
    ticTacBtn[newChar.toInt()]->setEnabled(false);
    if (ticTac.isWin() != 0)
    {
        if (ticTac.isWin() == 1)
        {
            ui->pushButton->setVisible(true);
        }
        if (ticTac.isWin() == -1)
        {
            ui->pushButton_2->setVisible(true);
        }
    }
}

void Widget::reset()
{
    // do later.
}
