#include "form.h"
#include "ui_form.h"


#include <QtSerialPort/QSerialPortInfo>
#include <QSerialPort>


Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);


    const auto infos = QSerialPortInfo::availablePorts();
    for (const QSerialPortInfo &info : infos)
        ui -> comboBox -> addItem(info.portName());

}

Form::~Form()
{
    delete ui;
}


QString Form::getSerialPort()
{
   return ui -> comboBox -> currentText();
}
