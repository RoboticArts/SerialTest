#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "portwindow.h"
#include <QMessageBox>
#include <QKeyEvent>

#include <QtSerialPort/QSerialPortInfo>


// Accessing UI components from another file: https://forum.qt.io/topic/14397/solved-accessing-ui-components-from-another-file/14
// http://www.qtcentre.org/threads/64945-access-to-another-ui-object-from-mainwindow

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);

    //Set Setial Port
     connect(ui->ButtonSerialPort , SIGNAL(clicked(bool)),this, SLOT(SettingSerialPort()));

     //Comunication
     connect(&thread, &MasterThread::response, this, showResponse);
     connect(&thread, &MasterThread::error, this, processError);
     connect(&thread, &MasterThread::timeout, this,processTimeout);


}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_ButtonSerialPort_clicked()
{

    MiPuertoSerie.show();
    MiPuertoSerie.exec();

}



void MainWindow::SettingSerialPort() { // Is SLOT

  port = MiPuertoSerie.getSerialPort();
  timeout = MiPuertoSerie.getWaitTimeOut();
  ui -> LabelPort -> setText(port);
  ui -> LabelTime-> setNum(timeout);

}

void MainWindow::on_SendButton_clicked()
{
    if(port.isEmpty())
    {
        QMessageBox::information(this,"COM","Puerto COM no detectado");
        return;
    }

    request = ui -> EditStringData -> text();
    transaction();
}


//    Methods for communicating through serial port

void MainWindow::transaction()
{
   // setControlsEnabled(false);
    ui->statusBar->showMessage(tr("Status: Running, connected to port %1.")
                         .arg(port));
    thread.transaction(port,
                       timeout,
                       request);
}

void MainWindow::showResponse(const QString &s)
{
  //  setControlsEnabled(true);
    ui->statusBar->showMessage(tr("Traffic, transaction #%1:"
                             "\n\r-request: %2"
                             "\n\r-response: %3")
                          .arg(++transactionCount).arg(ui-> statusBar->currentMessage()).arg(s));
}

void MainWindow::processError(const QString &s)
{
   // setControlsEnabled(true);
    ui -> statusBar->showMessage(tr("Status: Not running, %1.").arg(s));
    ui -> statusBar -> showMessage(tr("No traffic."));
}

void MainWindow::processTimeout(const QString &s)
{
   // setControlsEnabled(true);
    ui ->statusBar->showMessage(tr("Status: Running, %1.").arg(s));
   // trafficLabel->setText(tr("No traffic."));
}

/*
void MainWindow::setControlsEnabled(bool enable)
{
    runButton->setEnabled(enable);
    serialPortComboBox->setEnabled(enable);
    waitResponseSpinBox->setEnabled(enable);
    requestLineEdit->setEnabled(enable);
}
*/



void MainWindow::on_SliderX_valueChanged(int)
{
    if(port.isEmpty())
    {
        QMessageBox::information(this,"COM","Puerto COM no detectado");
        return;
    }

    int n = ui->SliderX-> value();

    ui-> DisplayX -> display(n); //Set LCDNumber
    request = QString::number(n); // Store value in "request"
    transaction();
}


void MainWindow::on_SliderY_valueChanged(int)
{
    if(port.isEmpty())
    {
        QMessageBox::information(this,"COM","Puerto COM no detectado");
        return;
    }

    int n = ui->SliderY-> value();

    ui-> DisplayY -> display(n); //Set LCDNumber
    request = QString::number(n); // Store value in "request"
    transaction();

}


void MainWindow::keyPressEvent(QKeyEvent *event)
{

    if(event -> key() == Qt::Key_A)
    {
        int x = ui -> SliderX -> value();
        if(x>=0)
            ui->SliderX->setValue(x-5);
    }


    if(event -> key() == Qt::Key_D)
    {
        int x = ui -> SliderX -> value();
        if(x<=255)
            ui->SliderX->setValue(x+5);
    }


    if(event -> key() == Qt::Key_W)
    {
        int y = ui -> SliderY -> value();
        if(y<=255)
            ui->SliderY->setValue(y+5);
    }


    if(event -> key() == Qt::Key_S)
    {
        int y = ui -> SliderY -> value();
        if(y>=0)
            ui->SliderY->setValue(y-5);
    }


}
