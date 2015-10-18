#ifndef OBJECT_H
#define OBJECT_H

#include <QPainter>
#include <QPointF>
#include <QString>



class object
{
public:
    object(){}
    virtual void draw(QPainter* painter, bool active) = 0;
    virtual qreal distance(QPointF st, QPointF end) = 0;
    virtual bool snap(QPointF &point, QString &where) = 0;
    virtual void set_snap(bool set_snap) = 0;

private:


};
#endif
