#include "canvasview.h"
#include <QPainter>
#include <QDebug>

canvasview::canvasview(QWidget * parent): QWidget(parent)
{
  state = INITIAL;
  shape = UNDEFINED;
  inter = new intermediate();
  start = true;
  show_points = false;

  setMouseTracking(true);

  QSize size(width,height);
  setMinimumSize(size);
  setMaximumSize(size);
  setSizePolicy(QSizePolicy(QSizePolicy::Maximum,QSizePolicy::Maximum));

}

void canvasview::paintEvent(QPaintEvent * event)
{
  QPainter *painter = new QPainter(this);
  inter->i_Draw(painter, false); //this prints everything out

  if(state == ACTIVE)
  {
        inter->i_Draw(painter, true);
        if (shape == LINE)
        {
            state = PRESSX;
        }

        if (shape == CIRCLE)
        {
            state = PRESSC;
        }
  }

  if (state == PRESSX || state == PRESSC)
  {
      inter->i_Draw(painter, true);
  }

  if(state == FIRSTCLICK)
  {

      inter->i_Draw(painter, true);
      if (shape == LINE)
      {
        painter->drawLine(st,end);
      }

      if (shape == CIRCLE)
      {
        int length = my_line.length();
        painter->drawEllipse(st, length,length);
      }
  }

  if (state == SECONDCLICK)
  {
      state = RESET;
  }

  if(state == RESET)
  {
    start = false;
    show_points = false;
    emit this->send_highlight(false,false,false);
    state = INITIAL;
    shape = UNDEFINED;
  }

  update();
}


void canvasview::keyPressEvent(QKeyEvent *event)
{

    if (state == INITIAL)//this means nothin has been pressed
    {
        if (event->key() == Qt::Key_C)
        {
            emit this->send_highlight(true,false,false);
            state = ACTIVE;
            shape = CIRCLE;
            start = true;
            show_points = true;
        }

        else if (event->key() == Qt::Key_X)
        {
            emit this->send_highlight(false,true,false);
            shape = LINE;
            state = ACTIVE;
            start = true;
            show_points = true;
        }

        else if (event->key() == Qt::Key_Escape)
        {
            emit this->send_highlight(false,false,true);
            state = PAUSE;
            start = true;
            show_points = true;
        }

        else
        {
            event->ignore();
        }
    }

    update();
}


void canvasview::mousePressEvent(QMouseEvent *event)
{
    if (start)
    {
        if(state == PRESSX || state == PRESSC)
        {
            state = FIRSTCLICK;
            st = QPointF(pointx, pointy);
            my_line.setP1(st);
        }

        else if(state == FIRSTCLICK)
        {
            state = SECONDCLICK;
            start = false;
            end = QPointF(pointx, pointy);

            inter->add_shape(shape, st, end);
        }
    }

}

void canvasview::mouseMoveEvent(QMouseEvent *event)
{
    QString temp;
    pointx = event->x();
    pointy = event->y();
    end = QPointF(pointx,pointy);
    my_line.setP2(end);
    if(show_points)
    {

        if (state == FIRSTCLICK)
        {
            emit this->send_points(FIRSTCLICK,pointx, pointy, shape);
        }
        else if(state == PRESSX)
        {
            snap_points = QPointF(pointx, pointy);
            if (inter->snap_point(snap_points, temp))
            {
                qDebug() << "work2";
            }

            emit this->send_points(PRESSX, pointx, pointy, shape);
        }

        else if(state == PRESSC)
        {
            emit this->send_points(PRESSC, pointx, pointy, shape);
        }
    }


    update();
}
