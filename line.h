#ifndef LINE_H
#define LINE_H

#include "object.h"
#include <QPainter>
#include <QPointF>
#include <QLineF>



class line : public object
{
public:
    line();
    line(QPointF p1, QPointF p2);
    virtual void draw(QPainter *painter, bool active);
    virtual bool snap(QPointF &point, QString &where);
    virtual qreal distance(QPointF st, QPointF end);
    virtual void set_snap(bool snap);

private:
    QPointF point1, point2;
    QPointF highlight_point;
    QPointF botPoint;
    QPointF topPoint;
    int hs;
    bool snapped;
    QLineF point_distance;
};


#endif

