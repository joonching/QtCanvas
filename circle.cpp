#include "circle.h"
#include <QLineF>


circle::circle(QPointF p1, QPointF p2)
{
    point1 = p1;
    point2 = p2;
    hs = 10;
}

void circle::draw(QPainter *painter, bool active)
{
    QLineF length_line;
    length_line.setP1(point1);
    length_line.setP2(point2);
    int length = length_line.length();
    painter->drawEllipse(point1, length, length);

    if (active)
    {
        if(active)
        {
            painter->save();
            painter->setBrush(Qt::yellow);
            painter->setPen(Qt::blue);

            painter->drawEllipse(this->point1, hs-10,hs-10);
            //my right point
            painter->drawEllipse(point1.rx()+length-5,point1.ry()-4, hs,hs);
            //my left point
            painter->drawEllipse(point1.rx()-length-5,point1.ry()-2, hs, hs);
            //my bottom point
            painter->drawEllipse(point1.rx()-2,point1.ry()+length-5, hs, hs);
            //my top point
            painter->drawEllipse(point1.rx()-3,point1.ry()-length-5, hs, hs);

            painter->restore();
        }
    }
}
