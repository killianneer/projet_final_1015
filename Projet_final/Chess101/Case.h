#ifndef CASE_H
#define CASE_H

#include <QApplication>
#include <QPushButton>
#include <QObject>
#include <QFont>
#include "Piece.h"

class Case : public QPushButton{
    Q_OBJECT
public :
    Case(int posX, int posY, QWidget* parent = nullptr);
    ~Case() = default;
    void ajouterPiece(Piece* piece);
    int getPosX();
    int getPosY();
    QString getCouleurBase();
    void setCouleurBase(QString couleurBase);

public slots:
    void clickEvent();

private :
    int posX_, posY_;
    Piece* piece_ = nullptr;
    QString couleurBase_ ;
};
#endif // CASE_H
