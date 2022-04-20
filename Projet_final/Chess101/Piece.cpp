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

QString Piece::getImagePath(){return imagePath_;};
void Piece::setImagePath(QString imagePath){imagePath_ = imagePath;};

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
Roi::Roi(bool couleur, int posX, int posY): Piece(couleur, posX, posY) {
    if (couleur){
        this->setNomPiece("Roi Noir");
        this->setImagePath(":/pieces/pieces_png/roiNoir.png");
    }
    else{
        this->setNomPiece("Roi Blanc");
        this->setImagePath(":/pieces/pieces_png/roiBlanc.png");
    }
};

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
Reine::Reine(bool couleur, int posX, int posY): Piece(couleur, posX, posY) {
    if (couleur){
        this->setNomPiece("Reine Noir");
        this->setImagePath(":/pieces/pieces_png/reineNoir.png");
    }
    else{
        this->setNomPiece("Reine Blanc");
        this->setImagePath(":/pieces/pieces_png/reineBlanc.png");
    }
};

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
