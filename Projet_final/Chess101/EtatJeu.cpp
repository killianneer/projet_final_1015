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
        if (caseEchequier->getNomCouleurBase() == "noir")
            caseEchequier->setStyleSheet("background-color: rgba(0, 120, 30, 0.7)");
        else
            caseEchequier->setStyleSheet("background-color: rgba(0, 120, 30, 0.5)");
    }
};

void EtatJeu::filtrerObstruction(std::vector<Case*>& cases){
    //int direction = pieceAppuye_->getDirectionX(caseEchequier);

    for (int i = 0; i < 5; i++) {
        bool premierePiece = false;
        for (int j = pieceAppuye_->getPosX(); j < 8; j++){
            vector<Case*>::iterator it = find_if(cases.begin(), cases.end(), [&] (Case* c) {return c->getPosX() == j && c->getPosY() == pieceAppuye_->getPosY();});
            if (it != cases.end()){
                if (premierePiece){
                    cases.erase(it);
                }
                else if((*it)->getPiece() != nullptr){
                    premierePiece = true;
                }
            }
        }
    }



    /*
    bool premierePiece = false;
    //X-enBas
    for (int i = pieceAppuye_->getPosX(); i < 8; i++){
        vector<Case*>::iterator it = find_if(cases.begin(), cases.end(), [&] (Case* c) {return c->getPosX() == i && c->getPosY() == pieceAppuye_->getPosY();});
        if (it != cases.end()){
            if (premierePiece){
                cases.erase(it);
            }
            else if((*it)->getPiece() != nullptr){
                premierePiece = true;
            }
        }
    }

    premierePiece = false;
    //X-enHaut
    for (int i = pieceAppuye_->getPosX(); i > -1; i--){
        vector<Case*>::iterator it = find_if(cases.begin(), cases.end(), [&] (Case* c) {return c->getPosX() == i && c->getPosY() == pieceAppuye_->getPosY();});
        if (it != cases.end()){
            if (premierePiece){
                cases.erase(it);
            }
            else if((*it)->getPiece() != nullptr){
                premierePiece = true;
            }
        }
    }

    premierePiece = false;
    //Y-aGauche
    for (int i = pieceAppuye_->getPosY(); i > -1; i--){
        vector<Case*>::iterator it = find_if(cases.begin(), cases.end(), [&] (Case* c) {return c->getPosY() == i && c->getPosX() == pieceAppuye_->getPosX();});
        if (it != cases.end()){
            if (premierePiece){
                cases.erase(it);
            }
            else if((*it)->getPiece() != nullptr){
                premierePiece = true;
            }
        }
    }

    premierePiece = false;
    //Y-aGauche
    for (int i = pieceAppuye_->getPosY(); i < 8; i++){
        vector<Case*>::iterator it = find_if(cases.begin(), cases.end(), [&] (Case* c) {return c->getPosY() == i && c->getPosX() == pieceAppuye_->getPosX();});
        if (it != cases.end()){
            if (premierePiece){
                cases.erase(it);
            }
            else if((*it)->getPiece() != nullptr){
                premierePiece = true;
            }
        }
    }


    //*********************** diagonales


    premierePiece = false;
    //aGaucheBas
    int cptY = 0;
    for (int i = pieceAppuye_->getPosX(); i < 8; i++){
        vector<Case*>::iterator it = find_if(cases.begin(), cases.end(), [&] (Case* c) {return c->getPosX() == i && c->getPosY() == pieceAppuye_->getPosY() - cptY;});
        if (it != cases.end()){
            if (premierePiece){
                cases.erase(it);
            }
            else if((*it)->getPiece() != nullptr){
                premierePiece = true;
            }
        }
        cptY++;
    }

    premierePiece = false;
    //aDroiteBas
    cptY = 0;
    for (int i = pieceAppuye_->getPosX(); i < 8; i++){
        vector<Case*>::iterator it = find_if(cases.begin(), cases.end(), [&] (Case* c) {return c->getPosX() == i && c->getPosY() == pieceAppuye_->getPosY() + cptY;});
        if (it != cases.end()){
            if (premierePiece){
                cases.erase(it);
            }
            else if((*it)->getPiece() != nullptr){
                premierePiece = true;
            }
        }
        cptY++;
    }

    premierePiece = false;
    //aGaucheHaut
    cptY = 0;
    for (int i = pieceAppuye_->getPosX(); i > -1; i--){
        vector<Case*>::iterator it = find_if(cases.begin(), cases.end(), [&] (Case* c) {return c->getPosX() == i && c->getPosY() == pieceAppuye_->getPosY() - cptY;});
        if (it != cases.end()){
            if (premierePiece){
                cases.erase(it);
            }
            else if((*it)->getPiece() != nullptr){
                premierePiece = true;
            }
        }
        cptY++;
    }

    premierePiece = false;
    //aDroiteHaut
    cptY = 0;
    for (int i = pieceAppuye_->getPosX(); i > -1; i--){
        vector<Case*>::iterator it = find_if(cases.begin(), cases.end(), [&] (Case* c) {return c->getPosX() == i && c->getPosY() == pieceAppuye_->getPosY() + cptY;});
        if (it != cases.end()){
            if (premierePiece){
                cases.erase(it);
            }
            else if((*it)->getPiece() != nullptr){
                premierePiece = true;
            }
        }
        cptY++;
    }
    */
};
