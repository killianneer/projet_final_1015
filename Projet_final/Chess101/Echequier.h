#ifndef ECHEQUIER_H
#define ECHEQUIER_H

#include <QGridLayout>
#include "Case.h"

class EtatJeu;
class Echequier : public QGridLayout{
public :
Echequier(EtatJeu* etatJeu);

std::vector <Piece*> getPieces() const;
std::vector <Case*> getCases() const;
QBoxLayout* getBoite() const;
void changerCouleurCase(Case* caseEchequier, QString couleurFonce, QString couleurPale);
void messageBox(QString titre, QString texte);

void piecesCreer(std::vector <Piece*> pieces);
void creerEchequier(std::vector <Piece*> pieces);
void recreerEchequier(std::vector <Piece*> pieces);
void creerUi();

private :
std::vector <Piece*> pieces_;
std::vector <Case*> cases_;
QBoxLayout* boite_;
EtatJeu* etatJeu_;
};
#endif // ECHEQUIER_H
