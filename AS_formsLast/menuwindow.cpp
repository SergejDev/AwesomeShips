#include "menuwindow.h"
#include "ui_menuwindow.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <login.h>

MenuWindow::MenuWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MenuWindow)
{
    ui->setupUi(this);
    setWindowFlags(Qt::CustomizeWindowHint | Qt::WindowTitleHint);
    //setModal(true);
    SetWindowStyle();
    //connect(this->ui->startPushButton,SIGNAL(clicked()),this,SLOT(GetUserData()));
    connect(this->ui->startPushButton,SIGNAL(clicked()),this,SIGNAL(StartButtonPressed()));

    connect(this->ui->LoginB,SIGNAL(clicked()),this,SLOT(OpenLoginWindow()));


    connect(this->ui->settingsPushButton,SIGNAL(clicked()),this,SIGNAL(SettingsButtonPressed()));
    connect(this->ui->quitPushButton,SIGNAL(clicked()),this,SIGNAL(QuitButtonPressed()));
}

MenuWindow::~MenuWindow()
{
    delete ui;
}

void MenuWindow::OpenLoginWindow()
{
    loginWindow = new LoginDialog();
        loginWindow->show();
}

bool MenuWindow::getCredentialsState()
{
    return credentialsValid;
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


