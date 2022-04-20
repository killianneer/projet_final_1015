#ifndef CASE_H
#define CASE_H

#include <QPushButton>
#include <QObject>
#include <QFont>
#include "Piece.h"

class EtatJeu;
class Case : public QPushButton{
    Q_OBJECT
public :
    Case(int posX, int posY, EtatJeu* etatJeu, QWidget* parent = nullptr);
    ~Case() = default;
    void init();

    void ajouterPiece(Piece* piece);
    void enleverPiece();

    int getPosX();
    int getPosY();
    std::string getNomCouleurBase();
    Piece* getPiece();
    QString getCouleurBase();
    void setCouleurBase(QString couleurBase);
    void setNomCouleurBase(std::string nomCouleurBase);
    void setEtatJeu(EtatJeu* etatJeu);

public slots:
    void clickEvent();

private :
    int posX_, posY_;
    Piece* piece_ = nullptr;
    QString couleurBase_ ;
    std::string nomCouleurBase_;
    EtatJeu* etatJeu_;
};
#endif // CASE_H
