#include "Echequier.h"
#include "EtatJeu.h"
#include <QMessageBox>
//Faire des pieces
using namespace std;

namespace valeursInitialesEchequier {
    QString couleurCaseNoir = "background-color: rgba(174, 102, 66, 1)";
    QString couleurCaseBlanc = "background-color: rgba(200, 50, 50, 0.1)";
    string nomCaseNoir = "noir";
    string nomCaseBlanc = "blanc";

    int maxBoxHeight = 800;
    int maxBoxWidth = 800;
}

Echequier::Echequier(EtatJeu* etatJeu){
    etatJeu_ = etatJeu;
    etatJeu_->setEchequier(this);
};

vector <Piece*> Echequier::getPieces(){return pieces_;};
vector <Case*> Echequier::getCases(){return cases_;};

QBoxLayout* Echequier::getBoite(){return boite_;};

void Echequier::piecesCreer(){
    try {
        Roi* roiBlanc = new Roi(false, 0, 3);
        pieces_.push_back(roiBlanc);

        Roi* roiNoir = new Roi(true, 7, 3);
        pieces_.push_back(roiNoir);

        Roi* roiNoir2 = new Roi(true, 0, 0);
        pieces_.push_back(roiNoir2);
    }
    catch (int e) {
        cout << e;
        QMessageBox messageErreur;
        messageErreur.critical(0,"Error","Un troisieme roi ne peux pas etre cree");
        messageErreur.setFixedSize(500,200);
    }

    Reine* reineNoir = new Reine(true, 7, 4);
    pieces_.push_back(reineNoir);
};

void Echequier::creerEchequier(){
    using namespace valeursInitialesEchequier;
    //faire les pieces
    piecesCreer();

    //placer les cases
    int compteur = 0;
    for (int i = 0; i < 8; ++i){
        for (int j = 0; j < 8; ++j){
             Case* caseEchequier = new Case(i, j, etatJeu_);
             cases_.push_back(caseEchequier);
             if (compteur % 2 == 0) {
                 caseEchequier->setCouleurBase(couleurCaseNoir);
                 caseEchequier->setNomCouleurBase(nomCaseNoir);
             }
             else {
                 caseEchequier->setCouleurBase(couleurCaseBlanc);
                 caseEchequier->setNomCouleurBase(nomCaseBlanc);
             }


             caseEchequier->setStyleSheet(caseEchequier->getCouleurBase());

             addWidget(caseEchequier,i,j,1,1);
             compteur++;
             //placer piece
             for (Piece* p : pieces_){
                 if (p->getPosX() == i && p->getPosY() == j)
                    caseEchequier->ajouterPiece(p);

             }
        }
    compteur--;
    }

    // Caracteristiques du board
    QWidget *carre = new QWidget;
    carre->setLayout(this);
    carre->setMaximumHeight(maxBoxHeight);
    carre->setMaximumWidth(maxBoxWidth);
    QBoxLayout* boite = new QBoxLayout((QBoxLayout::LeftToRight));
    boite_ = boite;
    boite_->addWidget(carre);
};
