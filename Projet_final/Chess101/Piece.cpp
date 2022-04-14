#include "Piece.h"

using namespace std;

Piece::Piece(bool couleur, int posX, int posY){
    couleur_ = couleur;
    posX_ = posX;
    posY_ = posY;
};

QString Piece::getNomPiece(){return nom_;};
void Piece::setNomPiece(QString nom) {nom_ = nom;};

int Piece::getPosX(){return posX_;};
int Piece::getPosY(){return posY_;};
