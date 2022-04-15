#ifndef ECHEQUIER_H
#define ECHEQUIER_H

#include <QGridLayout>
#include "Piece.h"
#include "Case.h"


class Echequier : public QGridLayout{
public :
Echequier();

std::vector <Piece*> getPiecesAPlacer();
void piecesCreer(std::vector <Piece*> piecesAPlacer_);
QBoxLayout* creerEchequier(Echequier echequier, QBoxLayout* boite);

private :
std::vector <Piece*> piecesAPlacer_;
};
#endif // ECHEQUIER_H
