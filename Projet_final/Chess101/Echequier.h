#ifndef ECHEQUIER_H
#define ECHEQUIER_H

#include <QGridLayout>
#include "Piece.h"
#include "Case.h"


class Echequier : public QGridLayout{
public :
Echequier();

std::vector <Piece*> getPiecesAPlacer();
QBoxLayout* getBoite();

void piecesCreer();
void creerEchequier();

private :
std::vector <Piece*> piecesAPlacer_;
QBoxLayout* boite_;
};
#endif // ECHEQUIER_H
