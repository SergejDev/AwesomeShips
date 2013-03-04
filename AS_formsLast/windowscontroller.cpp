#include "windowscontroller.h"
#include <QMessageBox>
#include "QtSql"
#include "workwithdb.h"
#include "gamecontroller.h"
#include <QTcpSocket>
#include "user.h"
#include <QHostAddress>
#include <QMessageBox>
#include <QString>
#include <QTimer>
#include <QCryptographicHash>
#include <QByteArray>

WindowsController::WindowsController(QObject *parent):QObject(parent)
{
    settingsWindow=new ToolsWindow();
    connect(settingsWindow,SIGNAL(ButtonBackClicked()),this,SLOT(ReturnToMenuSlot()));
    connect(settingsWindow,SIGNAL(ButtonSaveClicked()),this,SLOT(ReturnToMenuSlot()));

    onApplicationStart=true;
    client = new QTcpSocket(this);
    hasConnection=false;
}

WindowsController::~WindowsController()
{
    delete menuWindow;
    delete settingsWindow;
}

void WindowsController::ShowMenuWindow(bool isGameWindowActive)
{
    menuWindow=new MenuWindow();
    connect(menuWindow,SIGNAL(StartButtonPressed()),this,SLOT(StartGameSlot()));
    connect(menuWindow,SIGNAL(RegisterButtonPressed()),this,SLOT(RegisterSlot()));
    connect(menuWindow,SIGNAL(SettingsButtonPressed()),this,SLOT(SettingsSlot()));
    connect(menuWindow,SIGNAL(QuitButtonPressed()),this,SLOT(QuitGameSlot()));
    menuWindow->show();
    if(isGameWindowActive)
    {
        menuWindow->DisableSettingsButton();
        gameWindow->PauseGame();
    }
}

void WindowsController::ReturnToMenuSlot()
{
    //qDebug()<<"return from settings";
    menuWindow->show();
}
void WindowsController::RegisterSlot()
{
    if(!menuWindow->getCredentialsState())
    {
        return;
    }
    StartAwaitTimer();//
    if (!client->isOpen())
    {
        QHostAddress addr(menuWindow->addr);
        client->connectToHost(addr, 9485);
    }
    QStringList list;
    list.append(menuWindow->UserName);    
    QCryptographicHash *hash = new QCryptographicHash(QCryptographicHash::Sha1);
    QByteArray string(menuWindow->PassWord.toAscii());
    hash->addData(string);
    list.append(hash->result());
    QDataStream out(client);
    out << list;
    connect(client, SIGNAL(readyRead()), this, SLOT(RegisterStartRead()));
}

void WindowsController::RegisterStartRead()
{
    ConnectionEstablished();
    QDataStream in(client);
    in >> userData;
    int id = userData.value(0).toInt();
    if (id!=-1)
    {
        QMessageBox msg;
        msg.setWindowTitle("Awesome Ships");
        msg.setText("Nickname exists.");
        msg.exec();
    }
    else
    {
        QMessageBox msg;
        msg.setWindowTitle("Awesome Ships");
        msg.setText("User added.");
        msg.exec();
    }
}

void WindowsController::StartGameSlot()
{
    if(!menuWindow->getCredentialsState())
    {
        return;
    }
    StartAwaitTimer();//ADD timer
    if (onApplicationStart)
    {
        if (!client->isOpen())
        {
            QHostAddress addr(menuWindow->addr);
            client->connectToHost(addr, 9485);
        }

        QStringList list;
        list.append(menuWindow->UserName);

        QCryptographicHash *hash = new QCryptographicHash(QCryptographicHash::Sha1);
        QByteArray string(menuWindow->PassWord.toAscii());
        hash->addData(string);
        list.append(hash->result());

        QDataStream out(client);
        out << list;
        connect(client, SIGNAL(readyRead()), this, SLOT(StartRead()));
    }
    else
    {
        gameWindow->ResumeGame();
    }
}

void WindowsController::SettingsSlot()
{
    //qDebug()<<"settings";
    menuWindow->hide();
    //settingsWindow=new ToolsWindow();
    settingsWindow->show();
}

void WindowsController::StartRead()
{
    //qDebug()<<"start read data from server";
    ConnectionEstablished();
    QDataStream in(client);
    in >> userData;
    int id = userData.value(0).toInt();
    if (id!=-1)//Wrong nickname or password
    {
        menuWindow->hide();
        if(onApplicationStart)
        {
            int level=userData.value(3).toInt();
            if (level == 5)
            {
                level = 0;
            }
            gameWindow=new GameWindow(settingsWindow->GetLanguageID(),settingsWindow->GetTopicID(),id,level,userData.value(4).toInt(),menuWindow->addr);
            connect(gameWindow,SIGNAL(MenuButtonPressed(bool)),this,SLOT(ShowMenuWindow(bool)));
            gameWindow->show();
            onApplicationStart=false;
            gameStarted=true;
        }
        else
        {
            gameWindow->ResumeGame();
        }
    }
    else
    {
        QMessageBox message;
        message.setWindowTitle("Login error");
        message.setText("Wrong nickname or password.");
        message.exec();
    }
}

void WindowsController::ConnectionTimeout()
{
    if(!hasConnection)
    {
        menuWindow->setCursor(Qt::ArrowCursor);
        QMessageBox message;
        message.setWindowTitle("Connection error");
        message.setText("Sorry. Server unawailible.");
        message.exec();
    }
}

void WindowsController::QuitGameSlot()
{
    QApplication::quit();
}

void WindowsController::StartAwaitTimer()
{
    QTimer::singleShot(3000, this, SLOT(ConnectionTimeout()));
    menuWindow->setCursor(Qt::WaitCursor);
}

void WindowsController::ConnectionEstablished()
{
    hasConnection=true;
    menuWindow->setCursor(Qt::ArrowCursor);
}
