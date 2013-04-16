#ifndef WIDGET_H
#define WIDGET_H

#include <QtGui/QWidget>
#include <QtGui/QPushButton>
#include <QtGui/QLineEdit>
#include <QtCore/QSignalMapper>
#include <QtGui/QFont>

#include "ticTacToePlay.h"

/**
 * @file widget.h
 *
 * Widget class to play tic-tac with graphics.
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
    
private:
    QSignalMapper *btnMapper;

    QPushButton *ticTacBtn[numOfButtons];
    QPushButton *endGame;
    Ui::Widget *ui;

    TicTacToePlay ticTac;

    void createButtons();
    void connectButtons();

    void setBtnStyle(int numOfBtn);

    QFont font;

private slots:
    void putSign(QString newChar);

    void reset();
};

#endif // WIDGET_H
