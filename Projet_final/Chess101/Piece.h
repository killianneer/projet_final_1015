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
    virtual ~Piece() = default;

    QString getNomPiece() const;
    void setNomPiece(QString nom);

    void deplacerPiece(Case* caseADeplacer);
    Piece* deplacerPieceSimulation(Case* caseADeplacer);
    std::vector<Case*> mouvementsPossibles(std::vector<Case*> cases);
    virtual bool critereMouvement(Case* caseEchequier);
    bool estCaseDePiece(Case* caseEchequier);

    int getPosX() const;
    int getPosY() const;
    bool getCouleur() const;

    QString getImagePath() const;
    //Source des images des pieces: Les icones trouves a wikipedia
    void setImagePath(QString imagePath);
    virtual bool estRoi();
    virtual bool estPion();

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
    bool estRoi();
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
    bool estPion();
private :
};
#endif // PIECE_H
