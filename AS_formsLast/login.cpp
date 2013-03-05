#include "login.h"
#include "ui_login.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <menuwindow.h>
#include <QString>
#include <QTcpSocket>
#include "user.h"
#include <QHostAddress>

MenuWindow *menuWindow;

LoginDialog::LoginDialog(QWidget *parent) :
    QDialog(parent),
    uiL(new Ui::LoginDialog)
{
    uiL->setupUi(this);

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

    connect(this->uiL->RegisterButton,SIGNAL(clicked()),this,SLOT(GetUserData()));
    connect(this->uiL->RegisterButton,SIGNAL(clicked()),this,SIGNAL(RegisterButtonPressed()));

    connect(this->uiL->LoginButton,SIGNAL(clicked()),this,SLOT(GetUserData()));
    connect(this->uiL->LoginButton,SIGNAL(clicked()),this,SIGNAL(StartButtonPressed()));
}

LoginDialog::~LoginDialog()
{
    delete uiL;
    //delete menuWindow;
}

void LoginDialog::on_LoginButton_clicked()
{
  /*  client = new QTcpSocket(this);
    QHostAddress addr(menuWindow->addr);
    client->connectToHost(addr, 9485);

    QStringList list;
    list.append(menuWindow->UserName);
    list.append(menuWindow->PassWord);
    QDataStream out(client);
    out << list;
    connect(client, SIGNAL(readyRead()), this, SLOT(StartRead()));
    */
}

void LoginDialog::GetUserData()
{

    menuWindow = new MenuWindow();
    if(Validate())
    {
        menuWindow->credentialsValid=true;
        menuWindow->UserName = uiL->Username->text();
        menuWindow->PassWord = uiL->Password->text();
        menuWindow->addr = uiL->serverAddressEdit->text();
    }
    else
    {
        menuWindow->credentialsValid=false;
    }
    //this->hide();
}

bool LoginDialog::Validate()
{
    bool isValid=true;
    if(uiL->Username->text()=="")
    {
        QMessageBox message;
        message.setWindowTitle("Validation error");
        message.setText("Enter nickname, please.");
        message.exec();
        isValid=false;
    }
    else if(uiL->Password->text()=="")
    {
        QMessageBox message;
        message.setWindowTitle("Validation error");
        message.setText("Enter password, please.");
        message.exec();
        isValid=false;
    }
    else if(uiL->serverAddressEdit->text()=="")
    {
        QMessageBox message;
        message.setWindowTitle("Validation error");
        message.setText("Enter server address, please.");
        message.exec();
        isValid=false;
    }
    return isValid;
}
