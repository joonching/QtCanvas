#ifndef CANVAS_H
#define CANVAS_H


#include <QPainter>
#include <QPointF>
#include <QString>
#include "object.h"


class canvas : public object
{

public:
    canvas();
    virtual void draw(QPainter *painter, bool active);
    virtual qreal distance(QPointF st, QPointF end);
    virtual bool snap(QPointF &point, QString &where);
    virtual void set_snap(bool set_snap);
    bool top_points(QPointF& point_inside, QString &where_inside);
    bool mid_points(QPointF& point_inside, QString &where_inside);
    bool bot_points(QPointF& point_inside, QString &where_inside);
    void set_snapped(bool set_snap);
    int get_width();
    int get_height();
private:
    QPointF topl, topm, topr;
    QPointF midl, midm, midr;
    QPointF botl, botm, botr;
    QLineF point_distance;
    QPointF highlight_point;
    QString point_desc;
    int width, height;
    int hl;
    bool active, snapped;

};
#endif
