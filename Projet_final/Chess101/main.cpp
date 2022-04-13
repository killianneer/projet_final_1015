#include "mainwindow.h"
#include "Piece.h"
#include "Case.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // make a grid
    QGridLayout *gridLayout = new QGridLayout;


    // create buttons
    int compteur = 0;
    for (int i = 0; i < 8; ++i){
    for (int j = 0; j < 8; ++j){
         QString coordonee = QString("%1 %2").arg(i).arg(j);
         QPushButton *place = new QPushButton(coordonee);
         if (compteur % 2 == 0){
            place->setStyleSheet("color : black ; background-color: white");
            }
         else
            place->setStyleSheet("color : white ; background-color: black");
         gridLayout->addWidget(place,i,j,1,1);
         gridLayout->itemAtPosition(i, j)->widget()->setMaximumHeight(100);
         gridLayout->itemAtPosition(i,j)->widget()->setMinimumHeight(100);
         gridLayout->itemAtPosition(i, j)->widget()->setMaximumWidth(100);
         gridLayout->itemAtPosition(i,j)->widget()->setMinimumWidth(100);
         gridLayout->setVerticalSpacing(0);
         gridLayout->setHorizontalSpacing(0);
         compteur++;

         Case c = Case(i, j, place);


    }
    compteur--;
    }



    QWidget *carre = new QWidget;
    carre->setLayout(gridLayout);
    carre->setMaximumHeight(800);
    carre->setMaximumWidth(800);
    QBoxLayout *echequier = new QBoxLayout((QBoxLayout::LeftToRight));
    echequier->addWidget(carre);

    // Create a widget
    QWidget *window = new QWidget();

    // Set the grid layout as a main layout
    window->setLayout(echequier);

    // Window title
    window->setWindowTitle("Grid Layouts (8x8)");

    // Display
    window->show();

    return a.exec();
}
