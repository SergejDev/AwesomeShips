#include "baza.h"

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
#include "menuwindow.h"
#include <QStringList>
#include <QMessageBox>
#include <QSqlQueryModel>
#include "WINDOW.h"

QObject* textEdit;
//QObject* comboBox;
//

using namespace std;
Baza::Baza(QMainWindow *parent) :
    QMainWindow(parent)
   // ui(new Ui::Baza)
{
    //ui->setupUi(this);
    //Включаем QML

    ui = new QDeclarativeView();
    ui->setSource(QUrl("qrc:/baza.qml"));
    ui->setResizeMode(QDeclarativeView::SizeRootObjectToView);
    setCentralWidget(ui);

    //Находим корневой элемент
    Root = ui->rootObject();
    //Соединяем C++ и QML, делая видимым функции С++ через элемент window
    ui->rootContext()->setContextProperty("window", this);
    textEdit = Root->findChild<QObject*>("textEdit");
    setWindowFlags(Qt::CustomizeWindowHint | Qt::WindowTitleHint);
    //setWindowTitle("Awesome ships");

    connect(this, SIGNAL(ButtonBack()), this, SLOT(on_pushButton_clicked()));
     connect(this, SIGNAL(ButtonOpen()), this, SLOT(on_pushButton_2_clicked()));
     connect(this, SIGNAL(ButtonImport()),this, SLOT(on_pushButton_3_clicked()));
    _topicID = Root->findChild<QObject*>("combo_topic");


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
      textEdit->setProperty("text",s);

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

                topicId = (_topicID->property("selectedIndex")).toInt();
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
                    QString queryString="INSERT INTO MultiLanguage(topicId,Russian,English) VALUES("+ QString::number(topicId+1) +",'"+worlds[0]+"','"+worlds[1]+"');";
                    query.exec(queryString);

                }
            }
            QMessageBox message;
            message.setWindowTitle("Awesome ships");
            message.setText("New words added.");
            message.exec();
            file.close();
        }
        db.close();
    }
}

