#include "EtatJeu.h"

using namespace std;

EtatJeu::EtatJeu(){
};

void EtatJeu::setCaseAppuye(Case* caseAppuye){caseAppuye_ = caseAppuye;};

void EtatJeu::setEchequier(Echequier* echequier){echequier_ = echequier;};

void EtatJeu::setPieceAppuye(Piece* pieceAppuye){pieceAppuye_ = pieceAppuye;};

void EtatJeu::caseClicker(Case* caseClicker){
    if (caseClicker->getPiece() != nullptr && pieceAppuye_ == nullptr){
        if (caseClicker->getNomCouleurBase() == "noir")
            caseClicker->setStyleSheet("background-color: rgba(0, 30, 120, 0.7)");
        else
            caseClicker->setStyleSheet("background-color: rgba(0, 30, 120, 0.5)");
        caseAppuye_ = caseClicker;
        pieceAppuye_ = caseClicker->getPiece();
        casesPossibles_ = pieceAppuye_->mouvementsPossibles(echequier_->getCases());
        filtrerObstruction(casesPossibles_);
        filtrerEquipe(casesPossibles_);
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

void EtatJeu::casesVertes(vector<Case*>& cases) {
    for (Case* caseEchequier : cases) {
        if (caseEchequier->getPiece() != nullptr){
            if (caseEchequier->getNomCouleurBase() == "noir")
                caseEchequier->setStyleSheet("background-color: rgba(150, 120, 30, 0.7)");
            else
                caseEchequier->setStyleSheet("background-color: rgba(150, 120, 30, 0.5)");
        }
        else{
            if (caseEchequier->getNomCouleurBase() == "noir")
                caseEchequier->setStyleSheet("background-color: rgba(0, 120, 30, 0.7)");
            else
                caseEchequier->setStyleSheet("background-color: rgba(0, 120, 30, 0.5)");
        }

    }
};

void EtatJeu::enleverCaseObstacle(vector<Case*>::iterator it, std::vector<Case*>& cases, bool& premierePiece){
    if (it != cases.end()){
        if (premierePiece){
            cases.erase(it);
        }
        else if((*it)->getPiece() != nullptr){
            premierePiece = true;
        }
    }
};

void EtatJeu::filtrerObstruction(std::vector<Case*>& cases){

    bool premierePiece = false;
    //X-enBas
    for (int i = pieceAppuye_->getPosX(); i < 8; i++){
        vector<Case*>::iterator it = find_if(cases.begin(), cases.end(), [&] (Case* c) {return c->getPosX() == i && c->getPosY() == pieceAppuye_->getPosY();});
        enleverCaseObstacle(it, cases, premierePiece);
    }

    premierePiece = false;
    //X-enHaut
    for (int i = pieceAppuye_->getPosX(); i > -1; i--){
        vector<Case*>::iterator it = find_if(cases.begin(), cases.end(), [&] (Case* c) {return c->getPosX() == i && c->getPosY() == pieceAppuye_->getPosY();});
        enleverCaseObstacle(it, cases, premierePiece);
    }

    premierePiece = false;
    //Y-aGauche
    for (int i = pieceAppuye_->getPosY(); i > -1; i--){
        vector<Case*>::iterator it = find_if(cases.begin(), cases.end(), [&] (Case* c) {return c->getPosY() == i && c->getPosX() == pieceAppuye_->getPosX();});
        enleverCaseObstacle(it, cases, premierePiece);
    }

    premierePiece = false;
    //Y-aDroite
    for (int i = pieceAppuye_->getPosY(); i < 8; i++){
        vector<Case*>::iterator it = find_if(cases.begin(), cases.end(), [&] (Case* c) {return c->getPosY() == i && c->getPosX() == pieceAppuye_->getPosX();});
        enleverCaseObstacle(it, cases, premierePiece);
    }


    //*********************** diagonales


    premierePiece = false;
    //aGaucheBas
    int cptY = 0;
    for (int i = pieceAppuye_->getPosX(); i < 8; i++){
        vector<Case*>::iterator it = find_if(cases.begin(), cases.end(), [&] (Case* c) {return c->getPosX() == i && c->getPosY() == pieceAppuye_->getPosY() - cptY;});
        enleverCaseObstacle(it, cases, premierePiece);
        cptY++;
    }

    premierePiece = false;
    //aDroiteBas
    cptY = 0;
    for (int i = pieceAppuye_->getPosX(); i < 8; i++){
        vector<Case*>::iterator it = find_if(cases.begin(), cases.end(), [&] (Case* c) {return c->getPosX() == i && c->getPosY() == pieceAppuye_->getPosY() + cptY;});
        enleverCaseObstacle(it, cases, premierePiece);
        cptY++;
    }

    premierePiece = false;
    //aGaucheHaut
    cptY = 0;
    for (int i = pieceAppuye_->getPosX(); i > -1; i--){
        vector<Case*>::iterator it = find_if(cases.begin(), cases.end(), [&] (Case* c) {return c->getPosX() == i && c->getPosY() == pieceAppuye_->getPosY() - cptY;});
        enleverCaseObstacle(it, cases, premierePiece);
        cptY++;
    }

    premierePiece = false;
    //aDroiteHaut
    cptY = 0;
    for (int i = pieceAppuye_->getPosX(); i > -1; i--){
        vector<Case*>::iterator it = find_if(cases.begin(), cases.end(), [&] (Case* c) {return c->getPosX() == i && c->getPosY() == pieceAppuye_->getPosY() + cptY;});
        enleverCaseObstacle(it, cases, premierePiece);
        cptY++;
    }

};

void EtatJeu::filtrerEquipe(std::vector<Case*>& cases){
    cases.erase(remove_if(cases.begin(), cases.end(), [=](Case* c) {
        if (c->getPiece() == nullptr)
            return false;
        return c->getPiece()->getCouleur() == pieceAppuye_->getCouleur();
    }), cases.end());
};
