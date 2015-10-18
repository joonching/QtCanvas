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
    snapped = false;
    botPoint = p1;
    topPoint = p2;
    hs = 10;
}

void line::draw(QPainter *painter, bool active)
{
    //botPoint = this->point1;
    //topPoint = this->point2;
    painter->drawLine(this->point1, this->point2);
    if(active)
    {
        painter->save();
        painter->setBrush(Qt::yellow);
        painter->setPen(Qt::blue);

        painter->drawEllipse(this->point1, hs,hs);
        botPoint = this->point1;
        painter->drawEllipse(this->point2, hs,hs);

        painter->restore();
    }

    if(snapped)
    {
        painter->save();
        painter->setBrush(Qt::blue);
        painter->setPen(Qt::blue);
        painter->drawEllipse(this->highlight_point, hs,hs);
        painter->restore();
        painter->drawEllipse(this->highlight_point, hs+8, hs+8);

    }
}

bool line::snap(QPointF &point, QString &where)
{
    //if point distance is less than hs then its inside the circle so switch points
    //and return a string
    if (distance(point, this->botPoint) < hs)
    {
        point = this->botPoint;
        highlight_point = this->botPoint;
        where = "end of line";
        snapped = true;
        return true;
    }
    else if(distance(point, this->topPoint) < hs)
    {
        point = this->topPoint;
        highlight_point = this->topPoint;
        where = "end of line";
        snapped = true;
        return true;
    }
    else
    {
        snapped = false;
        return false;
    }
}

void line::set_snap(bool snap)
{
    snapped = snap;
}



qreal line::distance(QPointF st, QPointF end)
{
    point_distance.setP1(st);
    point_distance.setP2(end);
    return point_distance.length();
}

