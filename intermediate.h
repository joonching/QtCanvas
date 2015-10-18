#ifndef INTERMEDIATE_H
#define INTERMEDIATE_H

#include "canvas.h"
#include "object.h"
#include <QVector>
#include "canvasview.h"


class object;

class intermediate
{
public :
    intermediate();
    void i_Draw(QPainter *painter, bool active);
    void add_shape(shapetype add_shape, QPointF p1, QPointF p2);
    bool snap_point(QPointF &st_point, QString &where);
    void set_bool_snap(bool snapper);

private:
    QVector <object *> my_vector;
};


#endif
