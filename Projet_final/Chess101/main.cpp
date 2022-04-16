#include "mainwindow.h"

using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Va dans classe Echequier --> pas clean
    EtatJeu* etatJeu = new EtatJeu;
    Echequier echequier = Echequier(etatJeu);
    echequier.creerEchequier();

    // Create a widget
    QWidget *window = new QWidget();

    // Set the grid layout as a main layout
    window->setLayout(echequier.getBoite());

    // Window title
    window->setWindowTitle("Grid Layouts (8x8)");

    // Display
    window->show();

    return a.exec();
}
