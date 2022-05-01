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
        nom_ = "Roi Noir";
        imagePath_ = ":/pieces/pieces_png/roiNoir.png";
    }
    else{
        nom_ = "Roi Blanc";
        imagePath_ = ":/pieces/pieces_png/roiBlanc.png";
    }
};

bool Roi::critereMouvement(Case* caseEchequier) {
    if (estCaseDePiece(caseEchequier))
        return false;

    //Toutes les cases autour de la piece
    return (caseEchequier->getPosX() >= posX_ - 1
         && caseEchequier->getPosX() <= posX_ + 1)
         &&
           (caseEchequier->getPosY() >= posY_ - 1
         && caseEchequier->getPosY() <= posY_ + 1);
};


//Reine
Reine::Reine(bool couleur, int posX, int posY): Piece(couleur, posX, posY) {
    if (couleur){
        nom_ = "Reine Noir";
        imagePath_ = ":/pieces/pieces_png/reineNoir.png";
    }
    else{
        nom_ = "Reine Blanc";
        imagePath_ = ":/pieces/pieces_png/reineBlanc.png";
    }
};

bool Reine::critereMouvement(Case* caseEchequier) {
    if (estCaseDePiece(caseEchequier))
        return false;

    return caseEchequier->getPosX() == posX_ // Cases horizontales
        || caseEchequier->getPosY() == posY_ // Cases verticales
        || (abs(caseEchequier->getPosX() - posX_) == abs(caseEchequier->getPosY() - posY_)); // Cases diagonales
};

//Fou
Fou::Fou(bool couleur, int posX, int posY): Piece(couleur, posX, posY) {
    if (couleur){
        nom_ = "Fou Noir";
        imagePath_ = ":/pieces/pieces_png/fouNoir.png";
    }
    else{
        nom_ = "Fou Blanc";
        imagePath_ = ":/pieces/pieces_png/fouBlanc.png";
    }
};

bool Fou::critereMouvement(Case* caseEchequier) {
    if (estCaseDePiece(caseEchequier))
        return false;

    return (abs(caseEchequier->getPosX() - posX_) == abs(caseEchequier->getPosY() - posY_)); // Cases diagonales
};

//Tour
Tour::Tour(bool couleur, int posX, int posY): Piece(couleur, posX, posY) {
    if (couleur){
        nom_ = "Tour Noir";
        imagePath_ = ":/pieces/pieces_png/tourNoir.png";
    }
    else{
        nom_ = "Tour Blanc";
        imagePath_ = ":/pieces/pieces_png/tourBlanc.png";
    }
};

bool Tour::critereMouvement(Case* caseEchequier) {
    if (estCaseDePiece(caseEchequier))
        return false;

    return caseEchequier->getPosX() == posX_ // Cases horizontales
        || caseEchequier->getPosY() == posY_; // Cases verticales
};

//Cheval
Cheval::Cheval(bool couleur, int posX, int posY): Piece(couleur, posX, posY) {
    if (couleur){
        nom_ = "Cheval Noir";
        imagePath_ = ":/pieces/pieces_png/chevalNoir.png";
    }
    else{
        nom_ = "Cheval Blanc";
        imagePath_ = ":/pieces/pieces_png/chevalBlanc.png";
    }
};

bool Cheval::critereMouvement(Case* caseEchequier) {
    if (estCaseDePiece(caseEchequier))
        return false;

    return (abs(caseEchequier->getPosX() - posX_) == 2 || abs(caseEchequier->getPosX() - posY_) == 2)
            &&
           (abs(caseEchequier->getPosX() - posX_) == 1 || abs(caseEchequier->getPosX() - posY_) == 1);
};

//Pion
Pion::Pion(bool couleur, int posX, int posY): Piece(couleur, posX, posY) {
    if (couleur){
        nom_ = "Pion Noir";
        imagePath_ = ":/pieces/pieces_png/pionNoir.png";
    }
    else{
        nom_ = "Pion Blanc";
        imagePath_ = ":/pieces/pieces_png/pionBlanc.png";
    }
};

bool Pion::critereMouvement(Case* caseEchequier) {
    if (estCaseDePiece(caseEchequier))
        return false;

    return true;
};
