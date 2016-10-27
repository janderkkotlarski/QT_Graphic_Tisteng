#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    QWidget window;

    window.resize(300, 300);
    //window.

    window.show();

    w.show();



    return a.exec();
}
