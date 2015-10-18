#ifndef CIRCLE_H
#define CIRCLE_H

#include "object.h"

#include <QPainter>
#include <QPointF>
#include <QLineF>


class circle: public object
{
public:
    circle(){}
    circle(QPointF p1, QPointF p2);
    virtual void draw(QPainter *painter, bool active);
    virtual qreal distance(QPointF st, QPointF end);
    virtual bool snap(QPointF &point, QString &where);
    virtual void set_snap(bool snapped);

private:
    QPointF point1, point2;
    QPointF highlight_point;
    QPointF ctop, cleft, cbot, cright, center;
    QLineF point_distance, length_line;
    int length;
    int hs;
    bool snapper;

};

#endif
