#include "mainwindow.h"

#include <QApplication>
#include <QPainter>

void paintEvent(){
    QPainter painter;

}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    paintEvent();
    w.show();
    return a.exec();
}
