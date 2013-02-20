#include "menuwindow.h"
#include "ui_menuwindow.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>

MenuWindow::MenuWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MenuWindow)
{
    ui->setupUi(this);
    setWindowFlags(Qt::CustomizeWindowHint | Qt::WindowTitleHint);
    //setModal(true);
    SetWindowStyle();
    connect(this->ui->startPushButton,SIGNAL(clicked()),this,SLOT(GetUserData()));
    connect(this->ui->startPushButton,SIGNAL(clicked()),this,SIGNAL(StartButtonPressed()));

    connect(this->ui->RegisterButton,SIGNAL(clicked()),this,SLOT(GetUserData()));
    connect(this->ui->RegisterButton,SIGNAL(clicked()),this,SIGNAL(RegisterButtonPressed()));

    connect(this->ui->settingsPushButton,SIGNAL(clicked()),this,SIGNAL(SettingsButtonPressed()));
    connect(this->ui->quitPushButton,SIGNAL(clicked()),this,SIGNAL(QuitButtonPressed()));
}

MenuWindow::~MenuWindow()
{
    delete ui;
}

void MenuWindow::GetUserData()
{

    if(Validate())
    {
        UserName=ui->Username->text();
        PassWord=ui->Password->text();
        addr=ui->serverAddressEdit->text();
    }
}

void MenuWindow::DisableSettingsButton()
{
    ui->settingsPushButton->setDisabled(true);
}

void MenuWindow::EnableSettingsButton()
{
    ui->settingsPushButton->setDisabled(false);
}

void MenuWindow::SetWindowStyle()
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

bool MenuWindow::Validate()
{
    if(ui->Username->text()=="")
    {
        QMessageBox message;
        message.setWindowTitle("Validation error");
        message.setText("Enter nickname, please.");
        message.exec();
        return false;
    }
    else if(ui->Password->text()=="")
    {
        QMessageBox message;
        message.setWindowTitle("Validation error");
        message.setText("Enter password, please.");
        message.exec();
        return false;
    }
    else if(ui->serverAddressEdit->text()=="")
    {
        QMessageBox message;
        message.setWindowTitle("Validation error");
        message.setText("Enter server address, please.");
        message.exec();
        return false;
    }
    else
    {
        return true;
    }
}
