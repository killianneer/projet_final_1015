#include "Echequier.h"
//Faire des pieces
using namespace std;

Echequier::Echequier(){
};

vector <Piece*> Echequier::getPiecesAPlacer(){
    return piecesAPlacer_;
};

void Echequier::piecesCreer(vector <Piece*> piecesAPlacer_){
    Roi* roiBlanc = new Roi(false, 0, 3);
    Roi* roiNoir = new Roi(true, 7, 3);
    Reine* reineNoir = new Reine(true, 7, 4);
    piecesAPlacer_.push_back(roiBlanc);
    piecesAPlacer_.push_back(roiNoir);
    piecesAPlacer_.push_back(reineNoir);
};

QBoxLayout* creerEchequier(Echequier* echequier, QBoxLayout* boite){
    //faire les pieces
    echequier->piecesCreer(echequier->getPiecesAPlacer());

    int compteur = 0;
    for (int i = 0; i < 8; ++i){
    for (int j = 0; j < 8; ++j){
         Case* caseEchequier = new Case(i, j);
         if (compteur % 2 == 0){
            caseEchequier->setStyleSheet("color : black ; background-color: white");
            }
         else
            caseEchequier->setStyleSheet("color : white ; background-color: black");
         echequier->addWidget(caseEchequier,i,j,1,1);
         echequier->setVerticalSpacing(0);
         echequier->setHorizontalSpacing(0);
         compteur++;
         //placer piece
         for (Piece* p : echequier->getPiecesAPlacer()){
             if (p->getPosX() == i && p->getPosY() == j)
                caseEchequier->ajouterPiece(p);
         }

    }
    compteur--;
    }

    // A changer
    QWidget *carre = new QWidget;
    carre->setLayout(echequier);
    carre->setMaximumHeight(800);
    carre->setMaximumWidth(800);
    boite->addWidget(carre);
    return boite;
};
