#include "mainwindow.h"

using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Va dans classe Echequier --> pas clean
    Echequier echequier = Echequier();
    QBoxLayout* boite = new QBoxLayout((QBoxLayout::LeftToRight));
    boite = echequier.creerEchequier(echequier, boite);

    // Create a widget
    QWidget *window = new QWidget();

    // Set the grid layout as a main layout
    window->setLayout(boite);

    // Window title
    window->setWindowTitle("Grid Layouts (8x8)");

    // Display
    window->show();

    return a.exec();
}
