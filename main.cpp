#include <QApplication>

#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication application(argc, argv);

    mainwindow view;
    view.show();
    return application.exec();
}
