#ifndef ETATJEU_H
#define ETATJEU_H

#include "Echequier.h"

class EtatJeu{
public :
    EtatJeu();
    ~EtatJeu() = default;

    void setEchequier(Echequier* echequier);
    void setCaseAppuye(Case* caseAppuye);
    void setPieceAppuye(Piece* pieceAppuye);

    void caseClicker(Case* caseClicker);
    //void deplacerPiece();

private :
    Echequier* echequier_;
    Case* caseAppuye_ = nullptr;
    Piece* pieceAppuye_ = nullptr;
};
#endif // ETATJEU_H
