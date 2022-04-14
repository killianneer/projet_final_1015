#ifndef PIECE_H
#define PIECE_H

#include <iostream>
#include <QString>
#include <vector>

class Piece{
public :
    Piece() = default;
    Piece(bool couleur, int posX, int posY);
    ~Piece() = default;

    QString getNomPiece();
    void setNomPiece(QString nom);

    std::vector <Piece> piecesCreer();

    void deplacerPiece(); // A implementer
    void capturerPiece(); // A implementer
    void mouvementsPossibles(); // A implementer

    int getPosX();
    int getPosY();

private:
    QString nom_ ;
    bool couleur_;
    int posX_, posY_;
};

class Roi : public Piece{
public :
    Roi() = default;
    Roi(bool couleur, int posX, int posY): Piece(couleur, posX, posY) {this->setNomPiece("♚");};

private :
};

class Reine : public Piece{
public :
    Reine() = default;
    Reine(bool couleur, int posX, int posY): Piece(couleur, posX, posY) {this->setNomPiece("♕");};
private :
};

class Tour : public Piece{
public :
    Tour() = default;
    Tour(bool couleur, int posX, int posY): Piece(couleur, posX, posY) {this->setNomPiece("Tour");};
private :
};

class Fou : public Piece{
public :
    Fou() = default;
    Fou(bool couleur, int posX, int posY): Piece(couleur, posX, posY) {this->setNomPiece("Fou");};
private :
};

class Cheval : public Piece{
public :
    Cheval() = default;
    Cheval(bool couleur, int posX, int posY): Piece(couleur, posX, posY) {this->setNomPiece("Cheval");};
private :
};

class Pion : public Piece{
public :
    Pion() = default;
    Pion(bool couleur, int posX, int posY): Piece(couleur, posX, posY) {this->setNomPiece("Pion");};
private :
};
#endif // PIECE_H
