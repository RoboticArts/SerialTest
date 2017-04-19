#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "masterthread.h"
#include "portwindow.h"

#include <QDialog>

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
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
     PortWindow MiPuertoSerie;


private:
    Ui::MainWindow *ui;private:


    void setControlsEnabled(bool enable);

    int transactionCount;

    MasterThread thread;


private slots:
   /* void transaction();
    void showResponse(const QString &s);
    void processError(const QString &s);
    void processTimeout(const QString &s);
*/
    void on_ButtonSerialPort_clicked();
    void on_ReadButton_clicked();
};

#endif // MAINWINDOW_H
