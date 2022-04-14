#include "Case.h"

using namespace std;

Case::Case(int posX, int posY, QWidget* parent): QPushButton(parent){
    posX_ = posX;
    posY_ = posY;
    this->setMaximumHeight(100);
    this->setMinimumHeight(100);
    this->setMaximumWidth(100);
    this->setMinimumWidth(100);
    QFont font = this->font();
    font.setPointSize(40);
    this->setFont(font);
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
    //this->setStyleSheet("color : white ; background-color: red");
};

void Case::ajouterPiece(Piece piece){
    piece_ = piece;
    this->setText(piece.getNomPiece());
}


