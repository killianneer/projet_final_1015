#ifndef PIECE_H
#define PIECE_H

#include <iostream>
#include <QString>
#include <vector>
#include <QIcon>

class Case;
class Piece{
public :
    Piece() = default;
    Piece(bool couleur, int posX, int posY);
    ~Piece() = default;

    QString getNomPiece();
    void setNomPiece(QString nom);

    void deplacerPiece(Case* caseADeplacer); // A implementer
    void capturerPiece(); // A implementer
    std::vector<Case*> mouvementsPossibles(std::vector<Case*> cases);
    virtual bool critereMouvement(Case* caseEchequier);
    bool estCaseDePiece(Case* caseEchequier);

    int getPosX();
    int getPosY();
    bool getCouleur();

    QString getImagePath();
    void setImagePath(QString imagePath);

    int getDirectionX(Case* caseComparer);
    int getDirectionY(Case* caseComparer);

protected:
    QString nom_ ;
    bool couleur_;
    int posX_, posY_;
    QString imagePath_;
};

class Roi : public Piece{
public :
    Roi() = default;
    Roi(bool couleur, int posX, int posY);
    bool critereMouvement(Case* caseEchequier);
private :
};

class Reine : public Piece{
public :
    Reine() = default;
    Reine(bool couleur, int posX, int posY);
    bool critereMouvement(Case* caseEchequier);
private :
};

class Tour : public Piece{
public :
    Tour() = default;
    Tour(bool couleur, int posX, int posY);
    bool critereMouvement(Case* caseEchequier);
private :
};

class Fou : public Piece{
public :
    Fou() = default;
    Fou(bool couleur, int posX, int posY);
    bool critereMouvement(Case* caseEchequier);
private :
};

class Cheval : public Piece{
public :
    Cheval() = default;
    Cheval(bool couleur, int posX, int posY);
    bool critereMouvement(Case* caseEchequier);
private :
};

class Pion : public Piece{
public :
    Pion() = default;
    Pion(bool couleur, int posX, int posY);
    bool critereMouvement(Case* caseEchequier);
private :
};
#endif // PIECE_H
