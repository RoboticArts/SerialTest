#include "mainwindow.h"
#include "portwindow.h"
#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    PortWindow d;


    w.show();
    return a.exec();


}
