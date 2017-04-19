#include "portwindow.h"
#include "ui_portwindow.h"

#include <QtSerialPort/QSerialPortInfo>
#include <QSerialPort>

PortWindow::PortWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PortWindow)
{
    ui->setupUi(this);

    const auto infos = QSerialPortInfo::availablePorts();
    for (const QSerialPortInfo &info : infos)
        ui -> comboBox -> addItem(info.portName());

}

PortWindow::~PortWindow()
{
    delete ui;
}



QString PortWindow::getSerialPort()
{
   return ui -> comboBox -> currentText();
}


void PortWindow::on_ConnectButton_clicked()
{


}
