#include "message.h"
#include <QPainter>

#include <QDebug>
message::message(QWidget *parent) : QWidget(parent)
{
    width = tempC.get_width()/2;
    height = tempC.get_height()/2;
    QSize size(900,65);
    setMinimumSize(size);
    setMaximumSize(size);
    setSizePolicy(QSizePolicy(QSizePolicy::Maximum,QSizePolicy::Maximum));
}

void message::paintEvent(QPaintEvent *event)
{
    QPainter *paint = new QPainter(this);
    paint->drawText(0,0,900,65,Qt::AlignCenter, coordinates);
    update();
}

void message::showme(statetype state, int x_co, int y_co, shapetype sh)
{


    if(state == FIRSTCLICK)
    {
        QString x_point2 = QString::number(x_co-width);
        QString y_point2 = QString::number(height-y_co);
        if (sh == LINE)
        {
            coordinates = "Draw line from (" + x_point + ", " + y_point +") to (" + x_point2 + ", "+ y_point2 + ")";

        }

        if (sh == CIRCLE)
        {
            coordinates = "Draw circle` centered at " + x_point + ", " + y_point +") and passing through (" + x_point2 + ", "+ y_point2 + ")";
        }
    }

    if(state == PRESSX)
    {
        x_point = QString::number(x_co-width);
        y_point = QString::number(height-y_co);
        coordinates = "Draw line from (" + x_point + ", " + y_point +") to ...";
    }

    if(state == PRESSC)
    {
        x_point = QString::number(x_co-width);
        y_point = QString::number(height-y_co);
        coordinates = "Draw circle centered at (" + x_point + ", " + y_point +") to ...";
    }


   emit this->update();
}
