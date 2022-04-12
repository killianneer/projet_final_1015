#ifndef PIECE_H
#define PIECE_H

#include <iostream>

using namespace std;

class Piece{
public :
    Piece(string nom, bool couleur, int posX, int posY){
        nom_ = nom;
        couleur_ = couleur;
        posX_ = posX;
        posY_ = posY;
    };
    ~Piece();

    //string getNomPiece();

    void deplacerPiece();
    void capturerPiece();
    void mouvementsPossibles();

private:
    string nom_;
    bool couleur_;
    int posX_, posY_;
};





#endif // PIECE_H
