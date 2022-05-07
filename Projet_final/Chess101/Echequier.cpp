#include "Echequier.h"
#include "EtatJeu.h"
#include "QMessageBox"
//Faire des pieces
using namespace std;

namespace constantes {
const QString couleurCaseNoir = "background-color: rgba(174, 102, 66, 1)";
const QString couleurCaseBlanc = "background-color: rgba(200, 50, 50, 0.1)";

const int tailleEchequier = 800;
const int grosseurMessageBox = 500;
const int longueurMessageBox = 200;
}

Echequier::Echequier(EtatJeu* etatJeu){
    etatJeu_ = etatJeu;
    etatJeu_->setEchequier(this);
};

vector <Piece*> Echequier::getPieces() const {return pieces_;};

vector <Case*> Echequier::getCases() const {return cases_;};

QBoxLayout* Echequier::getBoite() const {return boite_;};

void Echequier::piecesCreer(vector<Piece*> pieces){
    pieces_ = {};
    for(Piece* piece : pieces)
        pieces_.push_back(piece);
};

void Echequier::creerEchequier(vector<Piece*> pieces){
    using namespace constantes;
    //faire les pieces
    piecesCreer(pieces);

    //for(Case* caseEchequier : cases_)
    //    caseEchequier->~Case();
    cases_ = {};
    //placer les cases
    int compteur = 0;
    for (int i = 0; i < 8; ++i){
        for (int j = 0; j < 8; ++j){
             Case* caseEchequier = new Case(i, j, tailleEchequier/8, etatJeu_);
             cases_.push_back(caseEchequier);
             if (compteur % 2 == 0) {
                 caseEchequier->setCouleurBase(couleurCaseNoir);
                 caseEchequier->setNomCouleurBase("noir");
             }
             else {
                 caseEchequier->setCouleurBase(couleurCaseBlanc);
                 caseEchequier->setNomCouleurBase("blanc");
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

    creerUi();
};

void Echequier::recreerEchequier(vector<Piece*> pieces){
    piecesCreer(pieces);
    for(Case* caseEchequier : cases_) {
        caseEchequier->enleverPiece();
        for (Piece* p : pieces_){
            if (p->getPosX() == caseEchequier->getPosX() && p->getPosY() == caseEchequier->getPosY())
               caseEchequier->ajouterPiece(p);
        }
    }
    etatJeu_->reset();
};

void Echequier::creerUi() {
    using namespace constantes;

    QWidget *carre = new QWidget;
    carre->setLayout(this);
    carre->setMaximumHeight(tailleEchequier);
    carre->setMaximumWidth(tailleEchequier);
    QBoxLayout* boiteEchequier = new QBoxLayout((QBoxLayout::LeftToRight));
    boite_ = boiteEchequier;
    boite_->addWidget(carre);
};

void Echequier::changerCouleurCase(Case* caseEchequier, QString couleurFonce, QString couleurPale) {
    if (caseEchequier->getNomCouleurBase() == "noir")
        caseEchequier->setStyleSheet(couleurFonce);
    else
        caseEchequier->setStyleSheet(couleurPale);
};

void Echequier::messageBox(QString titre, QString texte) {
    using namespace constantes;
    QMessageBox message;
    message.critical(0,titre,texte);
    message.setFixedSize(grosseurMessageBox,longueurMessageBox);
};
