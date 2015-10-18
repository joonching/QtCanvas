#include "intermediate.h"
#include "canvas.h"
#include "object.h"
#include "line.h"
#include "circle.h"
#include <QDebug>
intermediate::intermediate()
{
    my_vector.push_back(new canvas);//this pushes in canvas
}

void intermediate::i_Draw(QPainter *painter, bool active)
{
    for (int i = 0; i < my_vector.size(); i++)
    {
        my_vector[i]->draw(painter, active);
    }
}

//this is to finally push in the final points -- double click
void intermediate::add_shape(shapetype add_shape, QPointF p1, QPointF p2)
{
    if(add_shape == LINE)
    {
        my_vector.push_back(new line(p1,p2));
    }

    if (add_shape == CIRCLE)
        my_vector.push_back(new circle(p1,p2));
}

bool intermediate::snap_point(QPointF &st_point, QString &where)
{
    bool temp = false;
    for(int i = 0; i < my_vector.size(); i++)
    {

       if(my_vector[i]->snap(st_point, where))
       {
            temp = true;
       }
    }

    if(temp)
        return true;
    else
        return false;
}

void intermediate::set_bool_snap(bool snapper)
{
    for (int i = 0; i < my_vector.size(); i++)
    {
        my_vector[i]->set_snap(snapper);
    }
}

