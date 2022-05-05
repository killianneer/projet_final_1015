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
    setMaximumHeight(100);
    setMinimumHeight(100);
    setMaximumWidth(100);
    setMinimumWidth(100);
    setIconSize(QSize(100, 100));
    connect(this, SIGNAL(clicked()), this, SLOT(clickEvent()));
}

int Case::getPosX(){return posX_;};

int Case::getPosY(){return posY_;};

Piece* Case::getPiece(){return piece_;};

QString Case::getCouleurBase() {return couleurBase_;};

string Case::getNomCouleurBase() {return nomCouleurBase_;};

void Case::setCouleurBase(QString couleurBase) {couleurBase_ = couleurBase;};

void Case::setNomCouleurBase(string nomCouleurBase) {nomCouleurBase_ = nomCouleurBase;};

void Case::setEtatJeu(EtatJeu* etatJeu){etatJeu_ = etatJeu;};

void Case::setPiece(Piece* piece) { piece_ = piece; };

void Case::clickEvent() {etatJeu_->caseClicker(this);};

void Case::ajouterPiece(Piece* piece){
    piece_ = piece;
    setIcon(QIcon(piece->getImagePath()));
}

void Case::enleverPiece(){
    piece_ = nullptr;
    setIcon(QIcon());
}

