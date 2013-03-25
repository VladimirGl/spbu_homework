#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPainter>
#include <QSound>

/**
 * @file widget.h
 *
 * @brief Implementation of Widget class.
 */

/// @namespace Ui
/// @brief Namespace for Widget class.
namespace Ui {
    class Widget;
}

/**
 * @class Widget
 *
 * Contained form and alarm sound.
 * Can paint all the graphics on the form.
 * Can play the sound (for alarm).
 */
class Widget : public QWidget
{
    Q_OBJECT
    
public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

    /// Paint clock background, hands and divisions. Also paint alarm hand.
    void paintEvent(QPaintEvent *);

public slots:
    /// Played sound 3 times, if the alarm hand at the same place that the hour hand.
    void playSound();

private:
    Ui::Widget *ui;

    /// Sound of the alarm clock.
    QSound alarm;
};

#endif // WIDGET_H
