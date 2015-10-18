#include "canvas.h"
#include <QDebug>

canvas::canvas()
{
    topl = QPointF(width*0, height*0);
    width = 870;
    height = 700;
    hl = 12;
    active = false;
}

void canvas::draw(QPainter *painter, bool active)
{
    painter->fillRect(0,0,width, height, QBrush(Qt::white,Qt::SolidPattern));
    painter->drawRect(0,0,width,height);

    if (active)
    {
        painter->save();
        painter->setBrush(Qt::yellow);
        painter->setPen(Qt::blue);

        painter->drawEllipse(width*0-5, height*0-5, hl, hl);
        painter->drawEllipse(width/2, height*0-5, hl, hl);
        painter->drawEllipse(width-7, height*0-5,hl, hl);

        painter->drawEllipse(width*0-5, height/2, hl, hl);
        painter->drawEllipse(width/2, height/2, hl+2, hl+2);
        painter->drawEllipse(width-7, height/2, hl, hl);

        painter->drawEllipse(width*0-5, height-7, hl, hl);
        painter->drawEllipse(width/2, height-7, hl, hl);
        painter->drawEllipse(width-7, height-7, hl, hl);
        painter->restore();
    }
}


int canvas::get_height()
{
    return height;
}

int canvas::get_width()
{
    return width;
}

