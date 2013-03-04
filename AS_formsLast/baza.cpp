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
#include <QSqlQueryModel>

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

    s = QFileDialog::getOpenFileName(this,QString::fromLocal8Bit("Открыть"), "/home","DB File(*.txt)");
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
        QString temp;
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
            QSqlQueryModel model;

            while(!out.atEnd())
            {
                int j=0;
                temp = out.readLine();
                QStringList worlds = temp.split("-");
                int topicId=ui->comboBox->currentIndex()+1;
                model.setQuery("SELECT * FROM MultiLanguage");
                for(int i=0; i<model.rowCount(); i++)
                {
                    QString eng = model.record(i).value("English").toString();
                    if(eng == worlds[1])
                    {
                        j++;
                    }
                }
                if(j==0)
                {
                    QString queryString="INSERT INTO MultiLanguage(topicId,Russian,English) VALUES("+ QString::number(topicId) +",'"+worlds[0]+"','"+worlds[1]+"');";
                    query.exec(queryString);

                }
            }
            QMessageBox message;
            message.setWindowTitle("Awesomeships");
            message.setText("words added.");
            message.exec();
            file.close();
        }
        db.close();
    }
}
