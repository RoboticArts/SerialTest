#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "portwindow.h"

#include <QtSerialPort/QSerialPortInfo>




MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


 //   PortWindow MiPuertoSerie;
 //   ui -> LabelPort -> setText(MiPuertoSerie.getSerialPort());


}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_ButtonSerialPort_clicked()
{
    //PortWindow d;
    //d.show();
    //d.exec();
    MiPuertoSerie.show();
    MiPuertoSerie.exec();



}

void MainWindow::on_ReadButton_clicked()
{

    ui -> LabelPort -> setText(MiPuertoSerie.getSerialPort());
}

