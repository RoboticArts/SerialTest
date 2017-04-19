#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "masterthread.h"
#include "portwindow.h"

#include <QDialog>
#include <QString>

class QLabel;
class QLineEdit;
class QSpinBox;
class QPushButton;
class QComboBox;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    QString port;// Store COM port and wait-timeout introduced on the PortWindow
    int timeout; //
    QString request; // Store request introduced on the MainWindow

    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
     PortWindow MiPuertoSerie;




private:

      Ui::MainWindow *ui;
      void keyPressEvent(QKeyEvent * event); //Para detectar el teclado

private:

    //void setControlsEnabled(bool enable);

    int transactionCount;

    MasterThread thread;

public slots:
    void SettingSerialPort();


private slots:

    void transaction();
    void showResponse(const QString &s);
    void processError(const QString &s);
    void processTimeout(const QString &s);

    void on_ButtonSerialPort_clicked();
    void on_SendButton_clicked();
    void on_SliderX_valueChanged(int value);
    void on_SliderY_valueChanged(int value);
};

#endif // MAINWINDOW_H
