#ifndef ETATJEU_H
#define ETATJEU_H

#include "Echequier.h"

class EtatJeu{
public :
    EtatJeu(bool tourEquipe, bool roiEnEchec);
    ~EtatJeu() = default;

    void setEchequier(Echequier* echequier);
    void setCaseAppuye(Case* caseAppuye);
    void setPieceAppuye(Piece* pieceAppuye);

    void caseClicker(Case* caseClicker);
    void couleurCasesPossibles(std::vector<Case*>& cases);
    void filtrerObstruction(std::vector<Case*>& cases);
    void enleverCaseObstacle(std::vector<Case*>::iterator it, std::vector<Case*>& cases, bool& premierePiece);
    void filtrerEquipe(std::vector<Case*>& cases);
    void filtrerPion(std::vector<Case*>& cases);
    void verifierEchec();

private :
    Echequier* echequier_ = nullptr;
    Case* caseAppuye_ = nullptr;
    Piece* pieceAppuye_ = nullptr;
    std::vector<Case*> casesPossibles_;
    bool tourEquipe_ = false;
    bool roiEnEchec_ = false;
};
#endif // ETATJEU_H
