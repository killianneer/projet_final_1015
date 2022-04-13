#include <iostream>
#include <QApplication>
#include <QPushButton>
#include <QObject>
#include "Case.h"

using namespace std;

Case::Case(int posX, int posY, QWidget* parent): QPushButton(parent){
    posX_ = posX;
    posY_ = posY;

    connect(this, SIGNAL(clicked()), this, SLOT(handleButton()));
};

void Case::handleButton() {
    // change the text
    this->setText("test");
};

