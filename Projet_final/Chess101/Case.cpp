#include "Case.h"
#include "EtatJeu.h"

using namespace std;

Case::Case(int posX, int posY, EtatJeu* etatJeu, QWidget* parent): QPushButton(parent){
    posX_ = posX;
    posY_ = posY;
    etatJeu_ = etatJeu;
    init();
};

void Case::init(){
    // faire attention au variable imaginaire
    this->setMaximumHeight(100);
    this->setMinimumHeight(100);
    this->setMaximumWidth(100);
    this->setMinimumWidth(100);
    QFont font = this->font();
    font.setPointSize(40);
    this->setFont(font);
    connect(this, SIGNAL(clicked()), this, SLOT(clickEvent()));
}

int Case::getPosX(){return posX_;};

int Case::getPosY(){return posY_;};

Piece* Case::getPiece(){return piece_;};

QString Case::getCouleurBase() {return couleurBase_;};

void Case::setCouleurBase(QString couleurBase) {couleurBase_ = couleurBase;};

void Case::setEtatJeu(EtatJeu* etatJeu){etatJeu_ = etatJeu;};

void Case::clickEvent() {etatJeu_->caseClicker(this);};

void Case::ajouterPiece(Piece* piece){
    piece_ = piece;
    this->setText(piece->getNomPiece());
}

void Case::enleverPiece(){
    piece_ = nullptr;
    this->setText("");
}

