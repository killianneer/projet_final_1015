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

//Roi


//Reine
//Fou
//Tour
//Cheval
//Pion
