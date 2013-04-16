#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget),
    btnMapper(new QSignalMapper(this)),
    ticTac(new Compyter)
{

    ui->setupUi(this);

    createButtons();
    connectButtons();
}

Widget::~Widget()
{
    delete[] ticTacBtn;
    delete endGame;
    delete btnMapper;
    delete ticTac;
    delete ui;
}

void Widget::createButtons()
{
    int const btnMinSize = 30;
    int const btnMaxSize = 145;
    int const colRowCount = 3;

    endGame = new QPushButton(" ", this);
    endGame->setMinimumSize(QSize(200, 80));
    endGame->setMaximumSize(QSize(200, 80));

    endGame->move(100, 110);

    endGame->setVisible(false);

    font.setPointSize(20);
    font.setBold(true);

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
    connect(endGame, SIGNAL(clicked()), this, SLOT(reset()));
}

void Widget::putSign(QString newChar)
{
    setBtnStyle(newChar.toInt());

    isEndGame();

    setBtnStyle(ticTac->doStep());

    isEndGame();
}

void Widget::isEndGame()
{
    if (ticTac->isWin() == 0)
        return;
    if (ticTac->isWin() == 1)
    {
        endGame->setText("X WIN!");
        endGame->setStyleSheet("color:#0000FF");
    }
    if (ticTac->isWin() == -1)
    {
        endGame->setText("O WIN!");
        endGame->setStyleSheet("color:#FF0000");
    }
    if (ticTac->isWin() == 2)
    {
        endGame->setText("DRAW!");
        endGame->setStyleSheet("color:#00FF00");
    }

    for (int i = 0; i < numOfButtons; i++)
        ticTacBtn[i]->setEnabled(false);

    endGame->setVisible(true);
    endGame->setFont(font);
}

void Widget::setBtnStyle(int numOfBtn)
{
    QString sign = ticTac->setSign(numOfBtn);
    ticTacBtn[numOfBtn]->setText(sign);
    if (sign == "X")
    {
        ticTacBtn[numOfBtn]->setFont(font);
        ticTacBtn[numOfBtn]->setStyleSheet("color:#0000FF");
    }
    if (sign == "O")
    {
        ticTacBtn[numOfBtn]->setFont(font);
        ticTacBtn[numOfBtn]->setStyleSheet("color:#FF0000");
    }

    ticTacBtn[numOfBtn]->setEnabled(false);
}

void Widget::reset()
{
    ticTac->reset();
    for (int i = 0; i < numOfButtons; i++)
    {
        ticTacBtn[i]->setText(" ");
        ticTacBtn[i]->setEnabled(true);
    }

    endGame->setVisible(false);
}
