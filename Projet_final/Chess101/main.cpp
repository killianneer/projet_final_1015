#include "mainwindow.h"

#include <QApplication>
#include <QtCore>
#include <QtGui>
#include <QPushButton>
#include <QGridLayout>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // make a grid
    QGridLayout *gridLayout = new QGridLayout;
    gridLayout->setHorizontalSpacing(10);
    gridLayout->setVerticalSpacing(10);

    // create buttons
    for (int i = 0; i < 8; ++i){
    for (int j = 0; j < 8; ++j){
         QPushButton *piece = new QPushButton("case");
         piece->setStyleSheet("color : white ; background-color: black");
         gridLayout->addWidget(piece,j,i,1,1);
    }
    }


    // Create a widget
    QWidget *w = new QWidget();

    // Set the grid layout as a main layout
    w->setLayout(gridLayout);

    // Window title
    w->setWindowTitle("Grid Layouts (8x8)");

    // Display
    w->show();

    return a.exec();
}
