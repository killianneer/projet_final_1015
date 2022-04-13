#include <iostream>
#include <QApplication>
#include <QPushButton>
#include <QObject>
#include <QString>
#include "Case.h"

using namespace std;

Case::Case(int posX, int posY, QWidget* parent): QPushButton(parent){
    posX_ = posX;
    posY_ = posY;
    this->setMaximumHeight(100);
    this->setMinimumHeight(100);
    this->setMaximumWidth(100);
    this->setMinimumWidth(100);
    connect(this, SIGNAL(clicked()), this, SLOT(clickEvent()));
};

int Case::getPosX(){
    return posX_;
}

int Case::getPosY(){
    return posY_;
}

void Case::clickEvent() {
    // change the text
    this->setText("Test");
};

void Case::ajouterPiece(Piece piece){
    piece_ = piece;
    // A implementer
    //QString nomPiece = QString::fromStdString(piece.getNomPiece());
    //this->setText(nomPiece);
    this->setText("Roi");
}


