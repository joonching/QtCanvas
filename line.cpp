#include "line.h"
#include <QBrush>
#include <QDebug>
line::line()
{

}

line::line(QPointF p1, QPointF p2)
{
    point1 = p1;
    point2 = p2;
    hs = 6;
}

void line::draw(QPainter *painter, bool active)
{
    painter->drawLine(this->point1, this->point2);
    if(active)
    {
        painter->save();
        painter->setBrush(Qt::yellow);
        painter->setPen(Qt::blue);

        painter->drawEllipse(this->point1, hs,hs);
        painter->drawEllipse(this->point2, hs,hs);

        painter->restore();
    }
}

bool line::snap(QPointF &point, QString &where)
{
    //if point distance is less than hs then its inside the circle so switch points
    //and return a string
    if (distance(point, this->point1) < hs)
    {
        point = this->point1;
        where = "hello";
        qDebug() << "work";
        return true;
    }
    else
        return false;
}


qreal line::distance(QPointF st, QPointF end)
{
    point_distance.setP1(st);
    point_distance.setP2(end);
    return point_distance.length();
}

