#include <QWidget>
#include "mainwindow.h"

mainwindow::mainwindow(QWidget *parent) : QWidget(parent)
{


    menu_text = new menu(this);
    message_text = new message(this);
    my_canvas = new canvasview(this);
    my_canvas->setFocus();
    my_canvas->grabMouse();


    QObject::connect(my_canvas, SIGNAL(send_highlight(bool,bool,bool)), menu_text, SLOT(receive_highlights(bool,bool,bool)));
    QObject::connect(my_canvas, SIGNAL(send_points(statetype, int, int, shapetype, QString, bool)), message_text, SLOT(showme(statetype, int, int, shapetype, QString, bool)));
    QVBoxLayout *layout = new QVBoxLayout;
    QHBoxLayout *layoutH = new QHBoxLayout;
    layoutH->addWidget(my_canvas);
    layoutH->addWidget(menu_text);
    layout->addWidget(message_text);
    layout->addLayout(layoutH);

    setLayout(layout);
}

