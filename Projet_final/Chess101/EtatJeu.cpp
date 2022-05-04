#include "EtatJeu.h"

using namespace std;

namespace couleurs {
QString bleuFonce = "background-color: rgba(0, 30, 120, 0.7)";
QString bleuPale = "background-color: rgba(0, 30, 120, 0.5)";

QString vertFonce = "background-color: rgba(0, 120, 30, 0.7)";
QString vertPale = "background-color: rgba(0, 120, 30, 0.5)";

QString rougeFonce = "background-color: rgba(200, 30, 60, 0.7)";
QString rougePale = "background-color: rgba(200, 30, 60, 0.5)";
}

EtatJeu::EtatJeu(bool tourEquipe, bool roiEnEchec) : tourEquipe_(tourEquipe), roiEnEchec_(roiEnEchec){};

void EtatJeu::setCaseAppuye(Case* caseAppuye){caseAppuye_ = caseAppuye;};

void EtatJeu::setEchequier(Echequier* echequier){echequier_ = echequier;};

void EtatJeu::setPieceAppuye(Piece* pieceAppuye){pieceAppuye_ = pieceAppuye;};

void EtatJeu::caseClicker(Case* caseClicker){
    using namespace couleurs;
    if (caseClicker->getPiece() != nullptr && pieceAppuye_ == nullptr){
        if(caseClicker->getPiece()->getCouleur() == tourEquipe_){
            echequier_->changerCouleurCase(caseClicker, bleuFonce, bleuPale);

            caseAppuye_ = caseClicker;
            pieceAppuye_ = caseClicker->getPiece();

            casesPossibles_ = pieceAppuye_->mouvementsPossibles(echequier_->getCases());
            filtrerObstruction(casesPossibles_);
            if(pieceAppuye_->estPion())
                filtrerPion(casesPossibles_);
            else
                filtrerEquipe(casesPossibles_);

            couleurCasesPossibles(casesPossibles_);
        }
    }
    else if (pieceAppuye_ != nullptr){
        for (Case* caseEchequier : casesPossibles_) {
            caseEchequier->setStyleSheet(caseEchequier->getCouleurBase());
            if (caseClicker == caseEchequier) {
                caseAppuye_->enleverPiece();
                pieceAppuye_->deplacerPiece(caseClicker);
                tourEquipe_ = !tourEquipe_;
            }
        }
        caseAppuye_->setStyleSheet(caseAppuye_->getCouleurBase());
        caseAppuye_ = nullptr;
        pieceAppuye_ = nullptr;
    }
};

void EtatJeu::couleurCasesPossibles(vector<Case*>& cases) {
    using namespace couleurs;
    for (Case* caseEchequier : cases) {
        if (caseEchequier->getPiece() != nullptr)
            echequier_->changerCouleurCase(caseEchequier, rougeFonce, rougePale);
        else
            echequier_->changerCouleurCase(caseEchequier, vertFonce, vertPale);
    }
};

void EtatJeu::enleverCaseObstacle(vector<Case*>::iterator it, std::vector<Case*>& cases, bool& premierePiece){
    if (it != cases.end()){
        if (premierePiece){
            cases.erase(it);
        }
        else if((*it)->getPiece() != nullptr){
            premierePiece = true;

            if (pieceAppuye_->estPion() && (*it)->getPiece()->getCouleur() == pieceAppuye_->getCouleur())
                cases.erase(it);
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
    cases.erase(remove_if(cases.begin(), cases.end(), [&](Case* c) {
        if (c->getPiece() == nullptr)
            return false;
        return c->getPiece()->getCouleur() == pieceAppuye_->getCouleur();
    }), cases.end());
};

void EtatJeu::filtrerPion(std::vector<Case*>& cases) {
    cases.erase(remove_if(cases.begin(), cases.end(), [&](Case* c) {
        return (c->getPiece() == nullptr && c->getPosY() != pieceAppuye_->getPosY())
                ||
               (c->getPiece() != nullptr && c->getPosY() == pieceAppuye_->getPosY());
    }), cases.end());
};
