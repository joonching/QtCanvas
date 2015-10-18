#include "circle.h"
#include <QLineF>


circle::circle(QPointF p1, QPointF p2)
{
    point1 = p1;
    point2 = p2;

    length_line.setP1(point1);
    length_line.setP2(point2);
    length = length_line.length();

    hs = 10;
    center = point1;
    cright = QPointF(point1.rx()+length,point1.ry());
    cleft = QPointF(point1.rx()-length,point1.ry());
    cbot = QPointF(point1.rx(),point1.ry()+length);
    ctop = QPointF(point1.rx(),point1.ry()-length);
    snapper = false;
}

void circle::draw(QPainter *painter, bool active)
{

    painter->drawEllipse(point1, length, length);


        if(active)
        {
            painter->save();
            painter->setBrush(Qt::yellow);
            painter->setPen(Qt::blue);

            //center point;
            painter->drawEllipse(center, hs,hs);
            //my right point
            painter->drawEllipse(cright, hs,hs);
            //my left point
            painter->drawEllipse(cleft, hs, hs);
            //my bottom point
            painter->drawEllipse(cbot, hs, hs);
            //my top point
            painter->drawEllipse(ctop, hs, hs);

            painter->restore();
        }

        if(snapper)
        {
            painter->save();
            painter->setBrush(Qt::blue);
            painter->setPen(Qt::blue);
            painter->drawEllipse(this->highlight_point, hs,hs);
            painter->restore();
            painter->drawEllipse(this->highlight_point, hs+8, hs+8);

        }
}

bool circle::snap(QPointF &point, QString &where)
{
    //if point distance is less than hs then its inside the circle so switch points
    //and return a string
    if (distance(point, this->center) < hs)
    {
        point = this->center;
        highlight_point = this->center;
        where = "Circle's center";
        snapper = true;
        return true;
    }
    else if(distance(point, this->ctop) < hs)
    {
        point = this->ctop;
        highlight_point = this->ctop;
        where = "Circle's top";
        snapper = true;
        return true;
    }
    else if(distance(point, this->cbot) < hs)
    {
        point = this->cbot;
        highlight_point = this->cbot;
        where = "Circle's bottom";
        snapper = true;
        return true;
    }
    else if(distance(point, this->cright) < hs)
    {
        point = this->cright;
        highlight_point = this->cright;
        where = "Circle's right";
        snapper = true;
        return true;
    }
    else if(distance(point, this->cleft) < hs)
    {
        point = this->cleft;
        highlight_point = this->cleft;
        where = "Circle's left";
        snapper = true;
        return true;
    }

    else
    {
        snapper = false;
        return false;
    }
}

void circle::set_snap(bool snap)
{
    snapper = snap;
}



qreal circle::distance(QPointF st, QPointF end)
{
    point_distance.setP1(st);
    point_distance.setP2(end);
    return point_distance.length();
}

