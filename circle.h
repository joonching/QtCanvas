#ifndef CIRCLE_H
#define CIRCLE_H

#include "object.h"

#include <QPainter>
#include <QPointF>


class circle: public object
{
public:
    circle(){}
    circle(QPointF p1, QPointF p2);
    virtual void draw(QPainter *painter, bool active);
    virtual qreal distance(QPointF st, QPointF end){}
    virtual bool snap(QPointF &point, QString &where){}

private:
    QPointF point1, point2;
    int hs;
};

#endif
