#ifndef CANVASVIEW_H
#define CANVASVIEW_H

typedef enum statetype{INITIAL, ACTIVE, PAUSE, PRESSX, PRESSC, FIRSTCLICK,
                       SECONDCLICK, RESET} statetype;
typedef enum shapetype{CIRCLE,LINE,UNDEFINED} shapetype;

#include <QWidget>
#include <QSize>
#include <QPointF>
#include <QPoint>
#include <QMouseEvent>
#include <QKeyEvent>
#include "object.h"
#include "canvas.h"
#include "intermediate.h"
#include "mainwindow.h"
#include <QLineF>

class intermediate;

class canvasview : public QWidget
{
  Q_OBJECT

  public:

    canvasview(QWidget *parent = 0);

    void paintEvent(QPaintEvent * event);
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void keyPressEvent(QKeyEvent *event);

signals:
    void send_highlight(bool c, bool x, bool e);
    void send_points(statetype state, int x, int y, shapetype sh);

  private:
    statetype state;
    shapetype shape;
    static const int width = 900;
    static const int height = 720; //sqrt(2)/2
    intermediate *inter;
    QPointF st, end;
    QPointF snap_points;
    int pointx, pointy;
    int p1,p2;
    QLineF my_line;
    bool start, show_points;

  };


#endif
