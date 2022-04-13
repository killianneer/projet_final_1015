#ifndef PIECE_H
#define PIECE_H

#include <iostream>

class Piece{
public :
    Piece() = default;
    Piece(bool couleur, int posX, int posY){
        couleur_ = couleur;
        posX_ = posX;
        posY_ = posY;
    };
    ~Piece() = default;

    std::string getNomPiece(){
        return nom_;
    };

    void deplacerPiece(); // A implementer
    void capturerPiece(); // A implementer
    void mouvementsPossibles(); // A implementer

    int getPosX(){
        return posX_;
    }

    int getPosY(){
        return posY_;
    }

private:
    std::string nom_;
    bool couleur_;
    int posX_, posY_;
};

class Roi : public Piece{
public :
    Roi() = default;
    Roi(bool couleur, int posX, int posY): Piece(couleur, posX, posY) {};
private :
    std::string nom_ = "Roi";
};

class Reine : public Piece{
public :
    Reine() = default;
    Reine(bool couleur, int posX, int posY): Piece(couleur, posX, posY) {};
private :
    std::string nom_ = "Reine";
};

class Tour : public Piece{
public :
    Tour() = default;
    Tour(bool couleur, int posX, int posY): Piece(couleur, posX, posY) {};
private :
    std::string nom_ = "Tour";
};

class Fou : public Piece{
public :
    Fou() = default;
    Fou(bool couleur, int posX, int posY): Piece(couleur, posX, posY) {};
private :
    std::string nom_ = "Fou";
};

class Cheval : public Piece{
public :
    Cheval() = default;
    Cheval(bool couleur, int posX, int posY): Piece(couleur, posX, posY) {};
private :
    std::string nom_ = "Cheval";
};

class Pion : public Piece{
public :
    Pion() = default;
    Pion(bool couleur, int posX, int posY): Piece(couleur, posX, posY) {};
private :
    std::string nom_ = "Pion";
};
#endif // PIECE_H
