#ifndef WINDOWSCONTROLLER_H
#define WINDOWSCONTROLLER_H
#include <QObject>
#include "gamewindow.h"
#include "menuwindow.h"
#include "WINDOW.h"
#include "gamecontroller.h"
#include <QTcpSocket>
#include "gamemenu.h"

class WindowsController: public QObject
{
    Q_OBJECT
private:
    MenuWindow *menuWindow;
    GameWindow *gameWindow;
    gamemenu *gameMenu;
    ToolsWindow *settingsWindow;
    bool onApplicationStart;
    bool gameStarted;
    QTcpSocket *client;
    bool hasConnection;
    //QTimer *awaitConnectionTimer;
    void StartAwaitTimer();
    void ConnectionEstablished();
    bool ArePassAndLoginGood();
public:
    WindowsController(QObject *parent=0);
    ~WindowsController();
    QStringList userData;


public slots:
    void ShowMenuWindow(bool isGameWindowActive=false);
    void ShowGameMenu(bool isGameWindowActive=false);
private slots:
    void ReturnToGame();
    void GoToMainMenuSlot();
    void RegisterSlot();
    void RegisterStartRead();
    void StartGameSlot();
    void SettingsSlot();
    void QuitGameSlot();
    void ReturnToMenuSlot();
    void StartRead();
    void ConnectionTimeout();
};

#endif // WINDOWSCONTROLLER_H
