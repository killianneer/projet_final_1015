#include "mainwindow.h"

using namespace std;

// TD6 :: QUESTION 3
class PieceTempo{
public :
    PieceTempo(Piece& piece, Case* caseEchequier) : caseTempo_(caseEchequier), pieceTempo_(piece){
        caseTempo_->ajouterPiece(&pieceTempo_);
    };
    ~PieceTempo(){
        caseTempo_->enleverPiece();
    };
private :
    Case* caseTempo_;
    Piece& pieceTempo_;
};

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Va dans classe Echequier --> pas clean
    EtatJeu* etatJeu = new EtatJeu;
    Echequier echequier = Echequier(etatJeu);
    echequier.creerEchequier();

    {
        Reine* reineBlanc = new Reine(false, 0, 0);
        PieceTempo pieceTempo_ = PieceTempo(*reineBlanc, echequier.getCases()[0]);
    }

    // Create a widget
    QWidget *window = new QWidget();

    // Set the grid layout as a main layout
    window->setLayout(echequier.getBoite());

    // Window title
    window->setWindowTitle("Grid Layouts (8x8)");

    // Display
    window->show();

    return a.exec();
}
