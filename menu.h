#ifndef MENU_H
#define MENU_H

#include <QWidget>
#include <QSize>
#include <iostream>
#include <QtGui>
#include <QTextEdit>
#include <QString>

class menu : public QWidget
{
    Q_OBJECT
public:
    menu(QWidget *parent = 0);
    void paintEvent(QPaintEvent *event);

public slots:
    void receive_highlights(bool c, bool x, bool e);

private:
    bool c_char, x_char, esc_char;
};
#endif
