#include "widget.h"
#include "ui_widget.h"

#include <QtGui>
#include <iostream>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget),
    alarm("ALARME.WAV")
{
    ui->setupUi(this);
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    connect(ui->dial, SIGNAL(valueChanged(int)), this, SLOT(update()));
    connect(timer, SIGNAL(timeout()), this, SLOT(playSound()));
    timer->start(1000);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    QTime time = QTime::currentTime();

    int side = qMin(width(), height());

    painter.setRenderHint(QPainter::Antialiasing);
    painter.translate(width() / 2 + 50, height() / 2);
    painter.scale(side / 200.0, side / 200.0);


    static const QPoint hourHand[3] = {
        QPoint(7, 8),
        QPoint(-7, 8),
        QPoint(0, -40)
    };
    static const QPoint minuteHand[3] = {
        QPoint(7, 8),
        QPoint(-7, 8),
        QPoint(0, -70)
    };

    QColor alarmColor(184, 134, 11);
    QColor backgroundColor(245, 245, 220);
    QColor hourColor(127, 0, 127);
    QColor minuteColor(0, 127, 127, 191);

    QPen pen(Qt::black, 5);

    painter.save();
    pen.setWidth(5);
    pen.setColor(Qt::black);
    painter.setPen(pen);
    painter.setBrush(backgroundColor);
    painter.drawEllipse(-90, -90, 180, 180);
    painter.restore();

    // Drow alarm hand.
    painter.save();
    pen.setWidth(3);
    pen.setColor(alarmColor);
    painter.setPen(pen);
    painter.rotate(ui->dial->value() * 6);
    painter.drawLine(0, 0, 0, -70);
    painter.restore();

    // Drow the hour hand.
    painter.save();
    painter.setBrush(hourColor);
    painter.rotate(30.0 * ((time.hour() + time.minute() / 60.0)));
    painter.drawConvexPolygon(hourHand, 3);
    painter.restore();


    // Drow the minute hand.
    painter.save();
    painter.setBrush(minuteColor);
    painter.rotate(6.0 * (time.minute() + time.second() / 60.0));
    painter.drawConvexPolygon(minuteHand, 3);
    painter.restore();

    // Establish characteristics of a seconds hand.
    pen.setWidth(1);
    pen.setColor(Qt::black);
    painter.setPen(pen);

    // Drow the seconds hand.
    painter.save();
    painter.rotate(6.0 * ((time.second())));
    painter.drawLine(0, 0, 0, -76);
    painter.restore();

    // Drow minute divisions.
    pen.setWidth(2);
    pen.setColor(minuteColor);
    painter.setPen(pen);
    for (int i = 0; i < 60; ++i)
    {
        if ((i % 5) != 0)
        painter.drawLine(87, 0, 83, 0);
        painter.rotate(6.0);
    }

    // Drow hour divisions.
    pen.setWidth(5);
    pen.setColor(Qt::black);
    painter.setPen(pen);
    for (int i = 0; i < 12; ++i)
    {
        painter.drawLine(88, 0, 80, 0);
        painter.rotate(30.0);
    }

    painter.drawEllipse(-1, -1, 2, 2);
}

double currentHourRotate(QTime time)
{
    if (time.hour() >= 12)
        return (30.0 * ((time.hour() + time.minute() / 60.0)) - 360);
    return (30.0 * ((time.hour() + time.minute() / 60.0)));
}

void Widget::playSound()
{
    QTime time = QTime::currentTime();
    if (ui->checkBox->isChecked())
        if ((currentHourRotate(time) == (ui->dial->value() * 6)))
        {
            alarm.setLoops(3);
            alarm.play();
            ui->checkBox->setChecked(false);
        }
}
