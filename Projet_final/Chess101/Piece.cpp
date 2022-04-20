#include "Piece.h"
#include "Case.h"


using namespace std;

//Piece General
Piece::Piece(bool couleur, int posX, int posY){
    couleur_ = couleur;
    posX_ = posX;
    posY_ = posY;
};

QString Piece::getNomPiece(){return nom_;};
void Piece::setNomPiece(QString nom) {nom_ = nom;};

int Piece::getPosX(){return posX_;};
int Piece::getPosY(){return posY_;};

void Piece::deplacerPiece(Case* caseADeplacer){
    posX_ = caseADeplacer->getPosX();
    posY_ = caseADeplacer->getPosY();
    caseADeplacer->ajouterPiece(this);
};

vector<Case*> Piece::mouvementsPossibles(vector<Case*> cases) {
    vector<Case*> casesPossibles;
    for(Case* caseEchequier : cases) {
        if(critereMouvement(caseEchequier))
            casesPossibles.push_back(caseEchequier);
    }
    return casesPossibles;
};

bool Piece::critereMouvement(Case* caseEchequier) {
    return caseEchequier->getPosX() == 0;
};

bool Piece::estCaseDePiece(Case* caseEchequier){
    if (caseEchequier->getPosX() == posX_ && caseEchequier->getPosY() == posY_)
        return true;
    return false;
};


//Roi
bool Roi::critereMouvement(Case* caseEchequier) {
    if (estCaseDePiece(caseEchequier))
        return false;

    //Toutes les cases autour de la piece
    return (caseEchequier->getPosX() >= getPosX() - 1
         && caseEchequier->getPosX() <= getPosX() + 1)
         &&
           (caseEchequier->getPosY() >= getPosY() - 1
         && caseEchequier->getPosY() <= getPosY() + 1);
};


//Reine
bool Reine::critereMouvement(Case* caseEchequier) {
    if (estCaseDePiece(caseEchequier))
        return false;

    return caseEchequier->getPosX() == getPosX() // Cases horizontales
        || caseEchequier->getPosY() == getPosY() // Cases verticales
        || (abs(caseEchequier->getPosX() - getPosX()) == abs(caseEchequier->getPosY() - getPosY())); // Cases diagonales
};
//Fou
//Tour
//Cheval
//Pion
