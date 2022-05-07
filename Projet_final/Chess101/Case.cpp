#include "Case.h"
#include "EtatJeu.h"

using namespace std;

Case::Case(int posX, int posY, int taille, EtatJeu* etatJeu, QWidget* parent): QPushButton(parent){
    posX_ = posX;
    posY_ = posY;
    taille_ = taille;
    etatJeu_ = etatJeu;
    init();
};

void Case::init(){
    setFixedSize(QSize(taille_, taille_));
    setIconSize(QSize(taille_, taille_));
    connect(this, SIGNAL(clicked()), this, SLOT(clickEvent()));
}

int Case::getPosX() const {return posX_;};

int Case::getPosY() const {return posY_;};

Piece* Case::getPiece() const {return piece_;};

QString Case::getCouleurBase() const {return couleurBase_;};

string Case::getNomCouleurBase() const {return nomCouleurBase_;};

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

