#ifndef ECHEQUIER_H
#define ECHEQUIER_H

#include <QGridLayout>
#include "Case.h"

class EtatJeu;
class Echequier : public QGridLayout{
public :
Echequier(EtatJeu* etatJeu);

std::vector <Piece*> getPieces();
std::vector <Case*> getCases();
QBoxLayout* getBoite();

void piecesCreer();
void creerEchequier();

private :
std::vector <Piece*> pieces_;
std::vector <Case*> cases_;
QBoxLayout* boite_;
EtatJeu* etatJeu_;
};
#endif // ECHEQUIER_H
