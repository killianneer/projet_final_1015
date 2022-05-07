#include "mainwindow.h"

//Source des images des pieces: Les icones trouves a wikipedia
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow* mainWindow = new MainWindow();
    mainWindow->getWindow()->show();

    return a.exec();
}
