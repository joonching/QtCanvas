#ifndef CANVAS_H
#define CANVAS_H


#include <QPainter>
#include <QPointF>
#include "object.h"


class canvas : public object
{

public:
    canvas();
    virtual void draw(QPainter *painter, bool active);
    virtual qreal distance(QPointF st, QPointF end){}
    virtual bool snap(QPointF &point, QString &where){}
    int get_width();
    int get_height();
private:
    QPointF topl, topm, topr;
    QPointF midl, midm, midr;
    QPointF botl, botm, botr;
    int width, height;
    int hl;
    bool active;

};
#endif
