#include "canvas.h"
#include <QDebug>

canvas::canvas()
{
    topl = QPointF(width*0, height*0);
    width = 870;
    height = 700;
    hl = 10;
    snapped = false;

    topl = QPointF(width*0, height*0);
    topm = QPointF(width/2, height*0-5);
    topr = QPointF(width-7, height*0-5);

    midl = QPointF(width*0-5, height/2);
    midm = QPointF(width/2, height/2);
    midr = QPointF(width-7, height/2);

    botl = QPointF(width*0-5, height-7);
    botm = QPointF(width/2, height-7);
    botr = QPointF(width-7, height-7);



    active = false;
}

void canvas::draw(QPainter *painter, bool active)
{
    painter->fillRect(0,0,width-10, height-10, QBrush(Qt::white,Qt::SolidPattern));
    painter->drawRect(0,0,width-10,height-10);

    if (active)
    {
        painter->save();
        painter->setBrush(Qt::yellow);
        painter->setPen(Qt::blue);

        painter->drawEllipse(topl, hl, hl);
        painter->drawEllipse(topm, hl, hl);
        painter->drawEllipse(topr,hl, hl);

        painter->drawEllipse(midl, hl, hl);
        painter->drawEllipse(midm, hl, hl);
        painter->drawEllipse(midr, hl, hl);

        painter->drawEllipse(botl, hl, hl);
        painter->drawEllipse(botm, hl, hl);
        painter->drawEllipse(botr, hl, hl);
        painter->restore();
    }

    if (snapped)
    {
        painter->save();
        painter->setBrush(Qt::blue);
        painter->setPen(Qt::blue);
        painter->drawEllipse(this->highlight_point, hl,hl);
        painter->restore();
        painter->drawEllipse(this->highlight_point, hl+8, hl+8);
    }
}


int canvas::get_height()
{
    return height;
}

int canvas::get_width()
{
    return width;
}


bool canvas::snap(QPointF &point, QString &where)
{

    if(top_points(point, where))
    {
        point = highlight_point;
        where = point_desc;
        return true;
    }

    else if(mid_points(point,where))
    {
        point = highlight_point;
        where = point_desc;
        return true;
    }


    else if(bot_points(point, where))
    {
        point = highlight_point;
        where = point_desc;
        return true;
    }

    else
    {
        snapped = false;
        return false;
    }
}

qreal canvas::distance(QPointF st, QPointF end)
{
    point_distance.setP1(st);
    point_distance.setP2(end);
    return point_distance.length();
}

bool canvas::top_points(QPointF &point_inside, QString &where_inside)
{
    if (distance(point_inside, topl) < hl)
    {
        point_inside = this->topl;
        highlight_point = this->topl;
        point_desc = "Canvas's top-left corner";
        snapped = true;
        return true;
    }

    else if (distance(point_inside, topm) < hl)
    {
        point_inside = this->topm;
        highlight_point = this->topm;
        point_desc = "Canvas's top-edge";
        snapped = true;
        return true;
    }


    else if (distance(point_inside, topr) < hl)
    {
        point_inside = this->topr;
        highlight_point = this->topr;
        point_desc = "Canvas's top-right corner";
        snapped = true;
        return true;
    }
    else
        return false;
}

bool canvas::mid_points(QPointF &point_inside, QString &where_inside)
{
    if (distance(point_inside, midl) < hl)
    {
        point_inside = this->midl;
        highlight_point = this->midl;
        point_desc = "Canvas's left edge";
        snapped = true;
        return true;
    }

    else if (distance(point_inside, midm) < hl)
    {
        point_inside = this->midm;
        highlight_point = this->midm;
        point_desc = "Canvas's center";
        snapped = true;
        return true;
    }


    else if (distance(point_inside, midr) < hl)
    {
        point_inside = this->midr;
        highlight_point = this->midr;
        point_desc = "Canvas's right edge";
        snapped = true;
        return true;
    }
    else
        return false;
}

bool canvas::bot_points(QPointF &point_inside, QString &where_inside)
{
    if(distance(point_inside, botl) < hl)
    {
        point_inside = this->botl;
        highlight_point = this->botl;
        point_desc = "Canvas's bottom-left corner";
        snapped = true;
        return true;
    }
    else if(distance(point_inside, botm) < hl)
    {
        point_inside = this->botm;
        highlight_point = this->botm;
        point_desc = "Canvas's bottom edge";
        snapped = true;
        return true;
    }
    else if(distance(point_inside, botl) < hl)
    {
        point_inside = this->botl;
        highlight_point = this->botl;
        point_desc = "Canvas's bottom-right corner";
        snapped = true;
        return true;
    }
    else
        return false;
}

void canvas::set_snap(bool set_snap)
{
    snapped = set_snap;
}
