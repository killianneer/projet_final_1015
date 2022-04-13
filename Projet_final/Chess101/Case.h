#ifndef CASE_H
#define CASE_H

#include <iostream>
#include <QApplication>
#include <QPushButton>
#include <QObject>

using namespace std;

class Case : public QObject{
    Q_OBJECT
public :
    Case(int posX, int posY, QPushButton* boutton){
        posX_ = posX;
        posY_ = posY;
        placeBoutton_ = boutton;

        QObject::connect(placeBoutton_, SIGNAL(clicked()), this, SLOT(handleButton()));
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
