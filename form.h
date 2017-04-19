#ifndef FORM_H
#define FORM_H

#include <QWidget>
#include <QString>
#include <QDialog>

namespace Ui {
class Form;
}

class Form : public QWidget
{
    Q_OBJECT

public:
    explicit Form(QWidget *parent = 0);
    ~Form();

private:
    Ui::Form *ui;

public:

 QString getSerialPort();


};

#endif // FORM_H
