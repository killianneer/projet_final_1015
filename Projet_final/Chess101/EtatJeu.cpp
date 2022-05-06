#include "EtatJeu.h"
#include "QMessageBox"

/*
QMessageBox messageErreur;
messageErreur.critical(0,"Titre","Texte");
messageErreur.setFixedSize(500,200);
*/

using namespace std;

namespace couleurs {
QString bleuFonce = "background-color: rgba(0, 30, 120, 0.7)";
QString bleuPale = "background-color: rgba(0, 30, 120, 0.5)";

QString vertFonce = "background-color: rgba(0, 120, 30, 0.7)";
QString vertPale = "background-color: rgba(0, 120, 30, 0.5)";

QString rougeFonce = "background-color: rgba(200, 30, 60, 0.7)";
QString rougePale = "background-color: rgba(200, 30, 60, 0.5)";

QString violetFonce = "background-color: rgba(200, 0, 255, 0.7)";
QString violetPale = "background-color: rgba(200, 0, 255, 0.5)";
}

EtatJeu::EtatJeu(bool tourEquipe, bool roiEnEchec) : tourEquipe_(tourEquipe), roiEnEchec_(roiEnEchec){};

void EtatJeu::setCaseAppuye(Case* caseAppuye){caseAppuye_ = caseAppuye;};

void EtatJeu::setEchequier(Echequier* echequier){echequier_ = echequier;};

void EtatJeu::setPieceAppuye(Piece* pieceAppuye){pieceAppuye_ = pieceAppuye;};

void EtatJeu::caseClicker(Case* caseClicker){
    using namespace couleurs;
    if (caseClicker->getPiece() != nullptr && pieceAppuye_ == nullptr){
        if(caseClicker->getPiece()->getCouleur() == tourEquipe_){
            caseAppuye_ = caseClicker;
            pieceAppuye_ = caseClicker->getPiece();

            casesPossibles_ = pieceAppuye_->mouvementsPossibles(echequier_->getCases());
            filtrerObstruction(casesPossibles_, pieceAppuye_);
            if(pieceAppuye_->estPion())
                filtrerPion(casesPossibles_, pieceAppuye_);
            else
                filtrerEquipe(casesPossibles_, pieceAppuye_);
            filtrerEchecs(casesPossibles_, pieceAppuye_, caseAppuye_);

            echequier_->changerCouleurCase(caseClicker, bleuFonce, bleuPale);
            couleurCasesPossibles(casesPossibles_);
        }
    }
    else if (pieceAppuye_ != nullptr){
        for (Case* caseEchequier : casesPossibles_) {
            caseEchequier->setStyleSheet(caseEchequier->getCouleurBase());
            if (caseClicker == caseEchequier) {
                caseAppuye_->enleverPiece();
                pieceAppuye_->deplacerPiece(caseClicker);
                roiEnEchec_ = verifierEchec(tourEquipe_);
                tourEquipe_ = !tourEquipe_;
            }
        }
        if (roiEnEchec_)
            if (verifierMat(tourEquipe_)) {
                if(tourEquipe_) {
                    QMessageBox messageErreur;
                    messageErreur.critical(0,"Partie Finie!","Les blancs ont gagné");
                    messageErreur.setFixedSize(500,200);
                }
                else {
                    QMessageBox messageErreur;
                    messageErreur.critical(0,"Partie Finie!","Les noirs ont gagné");
                    messageErreur.setFixedSize(500,200);
                }
            }
        roiEnEchec_ = false;
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

void EtatJeu::setCasesPiecesEnemies(std::vector<Case*>& cases, Piece* pieceVerifier){
    for (Case* caseEchequier : cases) {
        if (caseEchequier->getPiece() != nullptr)
            if (caseEchequier->getPiece()->getCouleur() != pieceVerifier->getCouleur())
                casesPiecesEnemiesTemp_.push_back(caseEchequier);
    }
};

void EtatJeu::enleverCaseObstacle(vector<Case*>::iterator it, std::vector<Case*>& cases, bool& premierePiece, Piece* pieceVerifier){
    if (it != cases.end()){
        if (premierePiece){
            cases.erase(it);
        }
        else if((*it)->getPiece() != nullptr){
            premierePiece = true;

            if (pieceVerifier->estPion() && (*it)->getPiece()->getCouleur() == pieceVerifier->getCouleur())
                cases.erase(it);
        }
    }
};

void EtatJeu::filtrerObstruction(std::vector<Case*>& cases, Piece* pieceVerifier){

    bool premierePiece = false;
    //X-enBas
    for (int i = pieceVerifier->getPosX(); i < 8; i++){
        vector<Case*>::iterator it = find_if(cases.begin(), cases.end(), [&] (Case* c) {return c->getPosX() == i && c->getPosY() == pieceVerifier->getPosY();});
        enleverCaseObstacle(it, cases, premierePiece, pieceVerifier);
    }

    premierePiece = false;
    //X-enHaut
    for (int i = pieceVerifier->getPosX(); i > -1; i--){
        vector<Case*>::iterator it = find_if(cases.begin(), cases.end(), [&] (Case* c) {return c->getPosX() == i && c->getPosY() == pieceVerifier->getPosY();});
        enleverCaseObstacle(it, cases, premierePiece, pieceVerifier);
    }

    premierePiece = false;
    //Y-aGauche
    for (int i = pieceVerifier->getPosY(); i > -1; i--){
        vector<Case*>::iterator it = find_if(cases.begin(), cases.end(), [&] (Case* c) {return c->getPosY() == i && c->getPosX() == pieceVerifier->getPosX();});
        enleverCaseObstacle(it, cases, premierePiece, pieceVerifier);
    }

    premierePiece = false;
    //Y-aDroite
    for (int i = pieceVerifier->getPosY(); i < 8; i++){
        vector<Case*>::iterator it = find_if(cases.begin(), cases.end(), [&] (Case* c) {return c->getPosY() == i && c->getPosX() == pieceVerifier->getPosX();});
        enleverCaseObstacle(it, cases, premierePiece, pieceVerifier);
    }


    //*********************** diagonales


    premierePiece = false;
    //aGaucheBas
    int cptY = 0;
    for (int i = pieceVerifier->getPosX(); i < 8; i++){
        vector<Case*>::iterator it = find_if(cases.begin(), cases.end(), [&] (Case* c) {return c->getPosX() == i && c->getPosY() == pieceVerifier->getPosY() - cptY;});
        enleverCaseObstacle(it, cases, premierePiece, pieceVerifier);
        cptY++;
    }

    premierePiece = false;
    //aDroiteBas
    cptY = 0;
    for (int i = pieceVerifier->getPosX(); i < 8; i++){
        vector<Case*>::iterator it = find_if(cases.begin(), cases.end(), [&] (Case* c) {return c->getPosX() == i && c->getPosY() == pieceVerifier->getPosY() + cptY;});
        enleverCaseObstacle(it, cases, premierePiece, pieceVerifier);
        cptY++;
    }

    premierePiece = false;
    //aGaucheHaut
    cptY = 0;
    for (int i = pieceVerifier->getPosX(); i > -1; i--){
        vector<Case*>::iterator it = find_if(cases.begin(), cases.end(), [&] (Case* c) {return c->getPosX() == i && c->getPosY() == pieceVerifier->getPosY() - cptY;});
        enleverCaseObstacle(it, cases, premierePiece, pieceVerifier);
        cptY++;
    }

    premierePiece = false;
    //aDroiteHaut
    cptY = 0;
    for (int i = pieceVerifier->getPosX(); i > -1; i--){
        vector<Case*>::iterator it = find_if(cases.begin(), cases.end(), [&] (Case* c) {return c->getPosX() == i && c->getPosY() == pieceVerifier->getPosY() + cptY;});
        enleverCaseObstacle(it, cases, premierePiece, pieceVerifier);
        cptY++;
    }

};

void EtatJeu::filtrerEquipe(std::vector<Case*>& cases, Piece* pieceVerifier){
    cases.erase(remove_if(cases.begin(), cases.end(), [&](Case* c) {
        if (c->getPiece() == nullptr)
            return false;
        return c->getPiece()->getCouleur() == pieceVerifier->getCouleur();
    }), cases.end());
};

void EtatJeu::filtrerPion(std::vector<Case*>& cases, Piece* pieceVerifier) {
    cases.erase(remove_if(cases.begin(), cases.end(), [&](Case* c) {
        return (c->getPiece() == nullptr && c->getPosY() != pieceVerifier->getPosY())
                ||
               (c->getPiece() != nullptr && c->getPosY() == pieceVerifier->getPosY());
    }), cases.end());
};

bool EtatJeu::verifierEchec(bool couleur){
    casesPiecesEnemiesTemp_ = {};

    for(Case* caseEchequier : echequier_->getCases()) {
        Piece* piece = caseEchequier->getPiece();
        if (piece != nullptr)
            if (piece->getCouleur() == couleur) {
                casesPossiblesTemp_ = piece->mouvementsPossibles(echequier_->getCases());
                filtrerObstruction(casesPossiblesTemp_, piece);
                if(piece->estPion())
                    filtrerPion(casesPossiblesTemp_, piece);
                else
                    filtrerEquipe(casesPossiblesTemp_, piece);

                setCasesPiecesEnemies(casesPossiblesTemp_, piece);

                for (Case* caseEnemie : casesPiecesEnemiesTemp_)
                    if (caseEnemie->getPiece()->estRoi())
                        return true;
            }
    }

    return false;
};

void EtatJeu::filtrerEchecs(std::vector<Case*>& cases, Piece* pieceVerifier, Case* caseDepart) {
    cases.erase(remove_if(cases.begin(), cases.end(), [&](Case* c) {
        Piece* pieceMemoire = pieceVerifier->deplacerPieceSimulation(c);
        caseDepart->setPiece(nullptr);
        bool verif = verifierEchec(!pieceVerifier->getCouleur());

        pieceVerifier->deplacerPieceSimulation(caseDepart);
        if(pieceMemoire == nullptr)
            c->setPiece(nullptr);
        else
            pieceMemoire->deplacerPieceSimulation(c);

        return verif;
    }), cases.end());
};

bool EtatJeu::verifierMat(bool couleur){
    vector<Case*> casesAVerif = {};

    for(Case* caseEchequier : echequier_->getCases()) {
        Piece* piece = caseEchequier->getPiece();
        if (piece != nullptr)
            if (piece->getCouleur() == couleur) {
                casesAVerif = piece->mouvementsPossibles(echequier_->getCases());
                filtrerObstruction(casesAVerif, piece);
                if(piece->estPion())
                    filtrerPion(casesAVerif, piece);
                else
                    filtrerEquipe(casesAVerif, piece);
                filtrerEchecs(casesAVerif, piece, caseEchequier);

                if(!casesAVerif.empty())
                    return false;
            }
    }
    return true;
};

