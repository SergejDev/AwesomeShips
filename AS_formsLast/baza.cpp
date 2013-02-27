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
#include <QtGui/QTextEdit>
#include <QString>
#include "QTextStream"
#include <QTextCodec>
#include <iostream>
#include <menuwindow.h>
#include <QStringList>
#include <QMessageBox>

using namespace std;
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

    s = QFileDialog::getOpenFileName(this,QString::fromLocal8Bit("�������"), "/home","DB File(*.txt)");
    ui->textEdit->setText(s);

}
void Baza::on_pushButton_3_clicked()
{
    QSqlDatabase db;
    db=QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("Words.s3db");
    db.setPassword("");
    if (!db.open())
    {
        qDebug() << db.lastError().text();
    }
    else
    {

        QFile file(s);
        QString temp,temp2,str,str2;
        QTextStream out (&file);
        if (!file.open(QIODevice::ReadOnly ))
        {
            QMessageBox message;
            message.setWindowTitle("Error");
            message.setText("Wrong file name.");
            message.exec();
            return;
        }
        else
        {
            QSqlQuery query;
            while(!out.atEnd())
            {
                temp = out.readLine();
                QStringList worlds = temp.split("-");
                if(ui->comboBox->currentIndex()==0)
                {
                    query.exec("INSERT INTO MultiLanguage(topicId,Russian,English) VALUES(1,'"+worlds[0]+"','"+worlds[1]+"');");
                }
                if(ui->comboBox->currentIndex()==1)
                {
                    query.exec("INSERT INTO MultiLanguage(topicId,Russian,English) VALUES(2,'"+worlds[0]+"','"+worlds[1]+"');");
                }
                if(ui->comboBox->currentIndex()==2)
                {
                    query.exec("INSERT INTO MultiLanguage(topicId,Russian,English) VALUES(3,'"+worlds[0]+"','"+worlds[1]+"');");
                }
            }
            file.close();
        }
        db.close();
    }
}
