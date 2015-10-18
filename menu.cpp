#include "menu.h"
#include <QFont>
#include <QPoint>
#include <QPointF>


menu::menu(QWidget *parent) : QWidget(parent)
{
    c_char = false;
    x_char = false;
    esc_char = false;

    QSize size(100,720);
    setMinimumSize(size);
    setMaximumSize(size);
    setSizePolicy(QSizePolicy(QSizePolicy::Maximum,QSizePolicy::Maximum));
}

void menu::paintEvent(QPaintEvent *event)
{
    QPointF draw = QPointF(0,100);
    QPointF line = QPointF(0,150);
    QPointF circle = QPointF(0,200);
    QPointF abort = QPointF(0,250);
    QPainter *paint = new QPainter(this);
    QFont font;
    font.setBold(true);
    font.setPixelSize(20);
    font.setUnderline(true);
    paint->setFont(font);
    paint->drawText(draw, tr("Draw"));
    font.setUnderline(false);
    font.setBold(x_char);
    paint->setFont(font);
    paint->drawText(line, tr("Line x"));
    font.setBold(c_char);
    paint->setFont(font);
    paint->drawText(circle, tr("Circle c"));
    font.setBold(esc_char);
    paint->setFont(font);
    paint->drawText(abort, tr("Abort esc"));
    update();
}

void menu::receive_highlights(bool c, bool x, bool e)
{
    c_char = c;
    x_char = x;
    esc_char = e;
    emit this->update();
}
