#include "mainwindow.h"
#include "ui_mainwindow.h"

std::vector<Piece*> MainWindow::jeuDeBase(){
    std::vector<Piece*> pieces = {};

    Roi* roiBlancBase = new Roi(false, 7, 4);
    Roi* roiNoirBase = new Roi(true, 0, 4);

    Reine* reineBlancBase = new Reine(false, 7, 3);
    Reine* reineNoirBase = new Reine(true, 0, 3);

    Fou* fouBlanc0Base = new Fou(false, 7, 2);
    Fou* fouBlanc1Base = new Fou(false, 7, 5);
    Fou* fouNoir0Base = new Fou(true, 0, 2);
    Fou* fouNoir1Base = new Fou(true, 0, 5);

    Cheval* chevalBlanc0Base = new Cheval(false, 7, 1);
    Cheval* chevalBlanc1Base = new Cheval(false, 7, 6);
    Cheval* chevalNoir0Base = new Cheval(true, 0, 1);
    Cheval* chevalNoir1Base = new Cheval(true, 0, 6);

    Tour* tourBlanc0Base = new Tour(false, 7, 0);
    Tour* tourBlanc1Base = new Tour(false, 7, 7);
    Tour* tourNoir0Base = new Tour(true, 0, 0);
    Tour* tourNoir1Base = new Tour(true, 0, 7);


    Pion* pionBlanc0Base = new Pion(false, 6, 0);
    Pion* pionBlanc1Base = new Pion(false, 6, 1);
    Pion* pionBlanc2Base = new Pion(false, 6, 2);
    Pion* pionBlanc3Base = new Pion(false, 6, 3);
    Pion* pionBlanc4Base = new Pion(false, 6, 4);
    Pion* pionBlanc5Base = new Pion(false, 6, 5);
    Pion* pionBlanc6Base = new Pion(false, 6, 6);
    Pion* pionBlanc7Base = new Pion(false, 6, 7);
    Pion* pionNoir0Base = new Pion(true, 1, 0);
    Pion* pionNoir1Base = new Pion(true, 1, 1);
    Pion* pionNoir2Base = new Pion(true, 1, 2);
    Pion* pionNoir3Base = new Pion(true, 1, 3);
    Pion* pionNoir4Base = new Pion(true, 1, 4);
    Pion* pionNoir5Base = new Pion(true, 1, 5);
    Pion* pionNoir6Base = new Pion(true, 1, 6);
    Pion* pionNoir7Base = new Pion(true, 1, 7);

    pieces.push_back(roiBlancBase);
    pieces.push_back(roiNoirBase);

    pieces.push_back(reineBlancBase);
    pieces.push_back(reineNoirBase);

    pieces.push_back(fouBlanc0Base);
    pieces.push_back(fouBlanc1Base);
    pieces.push_back(fouNoir0Base);
    pieces.push_back(fouNoir1Base);

    pieces.push_back(chevalBlanc0Base);
    pieces.push_back(chevalBlanc1Base);
    pieces.push_back(chevalNoir0Base);
    pieces.push_back(chevalNoir1Base);

    pieces.push_back(tourBlanc0Base);
    pieces.push_back(tourBlanc1Base);
    pieces.push_back(tourNoir0Base);
    pieces.push_back(tourNoir1Base);

    pieces.push_back(pionBlanc0Base);
    pieces.push_back(pionBlanc1Base);
    pieces.push_back(pionBlanc2Base);
    pieces.push_back(pionBlanc3Base);
    pieces.push_back(pionBlanc4Base);
    pieces.push_back(pionBlanc5Base);
    pieces.push_back(pionBlanc6Base);
    pieces.push_back(pionBlanc7Base);
    pieces.push_back(pionNoir0Base);
    pieces.push_back(pionNoir1Base);
    pieces.push_back(pionNoir2Base);
    pieces.push_back(pionNoir3Base);
    pieces.push_back(pionNoir4Base);
    pieces.push_back(pionNoir5Base);
    pieces.push_back(pionNoir6Base);
    pieces.push_back(pionNoir7Base);

    return pieces;
}

std::vector<Piece*> MainWindow::test1(){
    std::vector<Piece*> pieces = {};

    Roi* roiBlancTest1 = new Roi(false, 7, 4);
    Roi* roiNoirTest1 = new Roi(true, 0, 4);

    Reine* reineBlancTest1 = new Reine(false, 7, 3);
    Reine* reineNoirTest1 = new Reine(true, 0, 3);

    Fou* fouBlanc0Test1 = new Fou(false, 7, 2);
    Fou* fouBlanc1Test1 = new Fou(false, 7, 5);
    Fou* fouNoir0Test1 = new Fou(true, 0, 2);
    Fou* fouNoir1Test1 = new Fou(true, 0, 5);

    Cheval* chevalBlanc0Test1 = new Cheval(false, 7, 1);
    Cheval* chevalBlanc1Test1 = new Cheval(false, 7, 6);
    Cheval* chevalNoir0Test1 = new Cheval(true, 0, 1);
    Cheval* chevalNoir1Test1 = new Cheval(true, 0, 6);

    Tour* tourBlanc0Test1 = new Tour(false, 7, 0);
    Tour* tourBlanc1Test1 = new Tour(false, 7, 7);
    Tour* tourNoir0Test1 = new Tour(true, 0, 0);
    Tour* tourNoir1Test1 = new Tour(true, 0, 7);


    Pion* pionBlanc0Test1 = new Pion(false, 6, 0);
    Pion* pionNoir0Test1 = new Pion(true, 1, 0);

    pieces.push_back(roiBlancTest1);
    pieces.push_back(roiNoirTest1);

    pieces.push_back(reineBlancTest1);
    pieces.push_back(reineNoirTest1);

    pieces.push_back(fouBlanc0Test1);
    pieces.push_back(fouBlanc1Test1);
    pieces.push_back(fouNoir0Test1);
    pieces.push_back(fouNoir1Test1);

    pieces.push_back(chevalBlanc0Test1);
    pieces.push_back(chevalBlanc1Test1);
    pieces.push_back(chevalNoir0Test1);
    pieces.push_back(chevalNoir1Test1);

    pieces.push_back(tourBlanc0Test1);
    pieces.push_back(tourBlanc1Test1);
    pieces.push_back(tourNoir0Test1);
    pieces.push_back(tourNoir1Test1);

    pieces.push_back(pionBlanc0Test1);
    pieces.push_back(pionNoir0Test1);

    return pieces;
}

std::vector<Piece*> MainWindow::test2(){
    std::vector<Piece*> pieces = {};

    Roi* roiBlancTest2 = new Roi(false, 7, 4);
    Roi* roiNoirTest2 = new Roi(true, 0, 4);

    Fou* fouBlanc0Test2 = new Fou(false, 7, 2);
    Fou* fouNoir1Test2 = new Fou(true, 0, 5);

    Cheval* chevalBlanc0Test2 = new Cheval(false, 7, 1);
    Cheval* chevalNoir1Test2 = new Cheval(true, 0, 6);

    Tour* tourBlanc0Test2 = new Tour(false, 7, 0);
    Tour* tourNoir1Test2 = new Tour(true, 0, 7);

    Pion* pionBlanc0Test2 = new Pion(false, 6, 0);
    Pion* pionNoir0Test2 = new Pion(true, 1, 0);

    pieces.push_back(roiBlancTest2);
    pieces.push_back(roiNoirTest2);

    pieces.push_back(fouBlanc0Test2);
    pieces.push_back(fouNoir1Test2);

    pieces.push_back(chevalBlanc0Test2);
    pieces.push_back(chevalNoir1Test2);

    pieces.push_back(tourBlanc0Test2);
    pieces.push_back(tourNoir1Test2);

    pieces.push_back(pionBlanc0Test2);
    pieces.push_back(pionNoir0Test2);

    return pieces;
}


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) { init(); }

MainWindow::~MainWindow() = default;

void MainWindow::init() {
    const int lageurBouton = 200;
    const int hauteurBoutton = 50;

    EtatJeu* etatJeu = new EtatJeu(false, false);
    echequier_ = new Echequier(etatJeu);
    echequier_->creerEchequier(jeuDeBase());

    QBoxLayout* boiteBouttons = new QBoxLayout((QBoxLayout::TopToBottom));

    QPushButton* nouveauJeuBoutton = new QPushButton("Nouveau Jeu");
    nouveauJeuBoutton->setFixedSize(QSize(lageurBouton, hauteurBoutton));

    QPushButton* jeuTest1Boutton = new QPushButton("Jeu Test1");
    jeuTest1Boutton->setFixedSize(QSize(lageurBouton, hauteurBoutton));

    QPushButton* jeuTest2Boutton = new QPushButton("Jeu Test2");
    jeuTest2Boutton->setFixedSize(QSize(lageurBouton, hauteurBoutton));

    boiteBouttons->addWidget(nouveauJeuBoutton);
    boiteBouttons->addWidget(jeuTest1Boutton);
    boiteBouttons->addWidget(jeuTest2Boutton);

    connect(nouveauJeuBoutton, SIGNAL(clicked()), this, SLOT(nouveauJeuBase()));
    connect(jeuTest1Boutton, SIGNAL(clicked()), this, SLOT(jeuTest1()));
    connect(jeuTest2Boutton, SIGNAL(clicked()), this, SLOT(jeuTest2()));

    echequier_->getBoite()->addLayout(boiteBouttons);

    window_ = new QWidget();
    window_->setLayout(echequier_->getBoite());
    window_->setWindowTitle("Chess");
};

QWidget* MainWindow::getWindow() const {
    return window_;
};

void MainWindow::nouveauJeuBase() { echequier_->recreerEchequier(jeuDeBase()); };
void MainWindow::jeuTest1() { echequier_->recreerEchequier(test1()); };
void MainWindow::jeuTest2() { echequier_->recreerEchequier(test2()); };
