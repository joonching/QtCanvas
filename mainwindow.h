#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QSize>
#include <iostream>
#include <QtGui>
#include <QTextEdit>
#include <QString>

#include "menu.h"
#include "message.h"
#include "canvasview.h"

class canvasview;
class menu;
class message;
class mainwindow : public QWidget
{
    Q_OBJECT
public:
    mainwindow(QWidget *parent = 0);

private:
    canvasview *my_canvas;
    menu *menu_text;
    message *message_text;
};


#endif
