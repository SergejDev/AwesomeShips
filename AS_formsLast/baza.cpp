#include "baza.h"
#include "ui_baza.h"
#include <QFile>
#include <QFileDialog>
#include <QtSql>
#include<QtSql/QSqlDatabase>
#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QMainWindow>
#include <QtGui/QPushButton>
#include <QString>
#include "QTextStream"
#include <QTextCodec>
#include <iostream>
#include <menuwindow.h>

Baza::Baza(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Baza)
{
    ui->setupUi(this);
    setWindowFlags(Qt::CustomizeWindowHint | Qt::WindowTitleHint);
    //setModal(true);
    SetWindowStyle();

}

Baza::~Baza()
{
    delete ui;
}

void Baza::on_pushButton_clicked()
{
    this->hide();
    emit ButtonBackClicked();
}
void Baza::SetWindowStyle()
{
    QString str;
    QString fileName=":/Style.txt";
    QFile inputFile(fileName);
    QTextStream ts(&inputFile);
    if(!inputFile.open(QFile::ReadOnly | QFile::Text))
    {
        return;
    }
    str=ts.readAll();
    inputFile.close();
    this->setStyleSheet(str);
}

void Baza::on_pushButton_2_clicked()
{

    s = QFileDialog::getOpenFileName(this,QString::fromLocal8Bit("Открыть"),
  "/home","DB File(*.txt)");

}

void Baza::on_pushButton_3_clicked()
{

}
