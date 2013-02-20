#include "windowscontroller.h"
#include <QMessageBox>
#include "QtSql"
#include "workwithdb.h"
#include "gamecontroller.h"
#include <QTcpSocket>
#include "user.h"
#include <QHostAddress>

#include <iostream>
#include <QMessageBox>
#include <QString>
#include <QHash>

WindowsController::WindowsController(QObject *parent):QObject(parent)
{
    settingsWindow=new ToolsWindow();
    connect(settingsWindow,SIGNAL(ButtonBackClicked()),this,SLOT(ReturnToMenuSlot()));
    connect(settingsWindow,SIGNAL(ButtonSaveClicked()),this,SLOT(ReturnToMenuSlot()));
    onApplicationStart=true;
}

WindowsController::~WindowsController()
{
    delete menuWindow;
    delete settingsWindow;
}

void WindowsController::ShowMenuWindow(bool isGameWindowActive)
{
    menuWindow=new MenuWindow();
    connect(menuWindow,SIGNAL(StartButtonPressed()),this,SLOT(StartRead()));
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
    qDebug()<<"return from settings";
    menuWindow->show();
}
void WindowsController::RegisterSlot()
{
    client = new QTcpSocket(this);
    QHostAddress addr(menuWindow->addr);
    //QMessageBox msg;
    client->connectToHost(addr, 9485);
    //msg.setText("Connecting to " + menuWindow->addr);
    //msg.exec();
    //User s(menuWindow->UserName, menuWindow->PassWord);
    QStringList list;
    list.append(menuWindow->UserName);
    list.append(menuWindow->PassWord);
    QDataStream out(client);
    out << list;
    connect(client, SIGNAL(readyRead()), this, SLOT(RegisterStartRead()));
}

void WindowsController::RegisterStartRead()
{
    QDataStream in(client);
    in >> userData;
    client->disconnect();
    in.~QDataStream();
    int id = userData.value(0).toInt();
    if (id!=-1)
    {
        QMessageBox msg;
        msg.setText("Nickname exists.");
        msg.exec();
    }
    else
    {
        QMessageBox msg;
        msg.setText("User added.");
        msg.exec();
    }
}

void WindowsController::StartGameSlot()
{
    menuWindow->hide();
    if (onApplicationStart)
    {
        client = new QTcpSocket(this);
        QHostAddress addr(menuWindow->addr);
        client->connectToHost(addr, 9485);

        QStringList list;
        list.append(menuWindow->UserName);
        list.append(menuWindow->PassWord);
        QDataStream out(client);
        out << list;
        connect(client, SIGNAL(readyRead()), this, SLOT(StartRead()));
//////////////
//        gameWindow=new GameWindow(settingsWindow->GetLanguageID(),settingsWindow->GetTopicID());///////
//        connect(gameWindow,SIGNAL(MenuButtonPressed(bool)),this,SLOT(ShowMenuWindow(bool)));
//        gameWindow->show();
        onApplicationStart=false;
    }
    else
    {
        //        QMessageBox msg;
        //        msg.setText("App is already running, fool.");
        //        msg.exec();
        gameWindow->ResumeGame();
    }

    //    menuWindow->hide();
    //        if(onApplicationStart)
    //        {
    //            gameWindow=new GameWindow(settingsWindow->GetLanguageID(),settingsWindow->GetTopicID());
    //            connect(gameWindow,SIGNAL(MenuButtonPressed(bool)),this,SLOT(ShowMenuWindow(bool)));
    //            gameWindow->show();
    //            onApplicationStart=false;
    //        }
    //        else
    //        {
    //
    //        }
}

void WindowsController::SettingsSlot()
{
    qDebug()<<"settings";
    menuWindow->hide();
    //settingsWindow=new ToolsWindow();
    settingsWindow->show();
}

void WindowsController::StartRead()
{
    QDataStream in(client);
    in >> userData;
    client->disconnect();
    in.~QDataStream();
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

void WindowsController::QuitGameSlot()
{
    QApplication::quit();
}
