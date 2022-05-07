#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <QApplication>
#include <QtCore>
#include <QtGui>
#include <QBoxLayout>
#include "EtatJeu.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QWidget* getWindow() const;
    void init();
    std::vector<Piece*> jeuDeBase();
    std::vector<Piece*> test1();
    std::vector<Piece*> test2();

public slots:
    void nouveauJeuBase();
    void jeuTest1();
    void jeuTest2();

private:
    Echequier* echequier_;
    QWidget* window_;
};
#endif // MAINWINDOW_H
