#include "Piece.h"


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


//Faire des pieces

vector <Piece> Piece::piecesCreer(){
    Roi roiBlanc = Roi(false, 0, 3);
    Roi roiNoir = Roi(true, 7, 3);
    Reine reineNoir = Reine(true, 7, 4);
    vector <Piece> piecesAPlacer;
    piecesAPlacer.push_back(roiBlanc);
    piecesAPlacer.push_back(roiNoir);
    piecesAPlacer.push_back(reineNoir);
    return piecesAPlacer;
};

//Roi


//Reine
//Fou
//Tour
//Cheval
//Pion
