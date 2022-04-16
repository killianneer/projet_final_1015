#include "EtatJeu.h"

using namespace std;

EtatJeu::EtatJeu(){
};

void EtatJeu::setCaseAppuye(Case* caseAppuye){caseAppuye_ = caseAppuye;};

void EtatJeu::setEchequier(Echequier* echequier){echequier_ = echequier;};

void EtatJeu::setPieceAppuye(Piece* pieceAppuye){pieceAppuye_ = pieceAppuye;};

void EtatJeu::caseClicker(Case* caseClicker){
    if (caseClicker->getPiece() != nullptr && pieceAppuye_ == nullptr){
        caseClicker->setStyleSheet("background-color: blue");
        caseAppuye_ = caseClicker;
        pieceAppuye_ = caseClicker->getPiece();
    }
    else if (pieceAppuye_ != nullptr){
        caseAppuye_->setStyleSheet(caseAppuye_->getCouleurBase());
        caseAppuye_->enleverPiece();
        pieceAppuye_->deplacerPiece(caseClicker);
        caseAppuye_ = nullptr;
        pieceAppuye_ = nullptr;
    }
};
