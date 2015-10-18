#ifndef MESSAGE_H
#define MESSAGE_H

#include <QWidget>
#include <QSize>
#include <iostream>
#include <QtGui>
#include <QTextEdit>
#include "canvasview.h"
#include "canvas.h"

class message : public QWidget
{
    Q_OBJECT

public:
    message(QWidget *parent = 0);
    void setText(const QString& text);
    void paintEvent(QPaintEvent *event);

public slots:
    void showme(statetype state, int x_co, int y_co, shapetype sh);

private:
    QString coordinates;
    QString x_point, y_point;
    int width,height;
    canvas tempC;
};

#endif
