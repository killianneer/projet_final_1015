#include "mainwindow.h"

using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // make a grid
    QGridLayout *gridLayout = new QGridLayout;

    //Faire des pieces
    Roi roiBlanc = Roi(false, 0, 3);
    Roi roiNoir = Roi(true, 7, 3);
    vector <Piece> piecesAPlacer;
    piecesAPlacer.push_back(roiBlanc);
    piecesAPlacer.push_back(roiNoir);

    // Va dans classe Echequier --> pas clean
    int compteur = 0;
    for (int i = 0; i < 8; ++i){
    for (int j = 0; j < 8; ++j){
         Case* caseEchequier = new Case(i, j);
         if (compteur % 2 == 0){
            caseEchequier->setStyleSheet("color : black ; background-color: white");
            }
         else
            caseEchequier->setStyleSheet("color : white ; background-color: black");
         gridLayout->addWidget(caseEchequier,i,j,1,1);
         gridLayout->setVerticalSpacing(0);
         gridLayout->setHorizontalSpacing(0);
         compteur++;
         //placer piece
         for (Piece p : piecesAPlacer){
             if (p.getPosX() == i && p.getPosY() == j)
                caseEchequier->ajouterPiece(p);
         }

    }
    compteur--;
    }

    // A changer
    QWidget *carre = new QWidget;
    carre->setLayout(gridLayout);
    carre->setMaximumHeight(800);
    carre->setMaximumWidth(800);
    QBoxLayout *echequier = new QBoxLayout((QBoxLayout::LeftToRight));
    echequier->addWidget(carre);

    // Create a widget
    QWidget *window = new QWidget();

    // Set the grid layout as a main layout
    window->setLayout(echequier);

    // Window title
    window->setWindowTitle("Grid Layouts (8x8)");

    // Display
    window->show();

    return a.exec();
}
