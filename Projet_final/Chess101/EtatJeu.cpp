#include "EtatJeu.h"

using namespace std;

namespace valeursInitialesEtatJeu {
    QString couleurCaseAppuyeeFonce = "background-color: rgba(0, 30, 120, 0.7)";
    QString couleurCaseAppuyeePale = "background-color: rgba(0, 30, 120, 0.5)";

    QString couleurCaseADeplacerFonce = "background-color: rgba(0, 120, 30, 0.7)";
    QString couleurCaseADeplacerpale = "background-color: rgba(0, 120, 30, 0.5)";
}

EtatJeu::EtatJeu(){
};

void EtatJeu::setCaseAppuye(Case* caseAppuye){caseAppuye_ = caseAppuye;};

void EtatJeu::setEchequier(Echequier* echequier){echequier_ = echequier;};

void EtatJeu::setPieceAppuye(Piece* pieceAppuye){pieceAppuye_ = pieceAppuye;};

void EtatJeu::caseClicker(Case* caseClicker){
    using namespace valeursInitialesEtatJeu;
    if (caseClicker->getPiece() != nullptr && pieceAppuye_ == nullptr){
        if (caseClicker->getNomCouleurBase() == "noir")
            caseClicker->setStyleSheet(couleurCaseAppuyeeFonce);
        else
            caseClicker->setStyleSheet(couleurCaseAppuyeePale);
        caseAppuye_ = caseClicker;
        pieceAppuye_ = caseClicker->getPiece();
        casesPossibles_ = pieceAppuye_->mouvementsPossibles(echequier_->getCases());
        casesVertes(casesPossibles_);
    }
    else if (pieceAppuye_ != nullptr){
        for (Case* caseEchequier : casesPossibles_) {
            caseEchequier->setStyleSheet(caseEchequier->getCouleurBase());
            if (caseClicker == caseEchequier) {
                caseAppuye_->enleverPiece();
                pieceAppuye_->deplacerPiece(caseClicker);
            }
        }
        caseAppuye_->setStyleSheet(caseAppuye_->getCouleurBase());
        caseAppuye_ = nullptr;
        pieceAppuye_ = nullptr;
    }
};

void EtatJeu::casesVertes(vector<Case*> cases) {
    using namespace valeursInitialesEtatJeu;
    for (Case* caseEchequier : cases) {
        if (caseEchequier->getNomCouleurBase() == "noir")
            caseEchequier->setStyleSheet(couleurCaseADeplacerFonce);
        else
            caseEchequier->setStyleSheet(couleurCaseADeplacerpale);
    }
}
