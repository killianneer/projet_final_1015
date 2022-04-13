#ifndef CASE_H
#define CASE_H

#include <iostream>
#include <QApplication>
#include <QPushButton>

using namespace std;

class Case{
    Q_OBJECT
public :
    Case(int posX, int posY, QPushButton boutton){
        posX_ = posX;
        posY_ = posY;
        placeBoutton_ = &boutton;

        QAbstractButton::connect(placeBoutton_, &QPushButton::released, this, &Case::handleButton);
    };
    ~Case();
private slots:
    void handleButton() {
        // change the text
          placeBoutton_->setText("test");
    };
private :
    int posX_, posY_;
    QPushButton *placeBoutton_;
};
#endif // CASE_H
