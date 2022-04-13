#ifndef CASE_H
#define CASE_H

#include <iostream>
#include <QApplication>
#include <QPushButton>
#include <QObject>


class Case : public QPushButton{
    Q_OBJECT
public :
    Case(int posX, int posY, QWidget* parent = nullptr);
    ~Case();

public slots:
    void handleButton();

private :
    int posX_, posY_;
};
#endif // CASE_H
