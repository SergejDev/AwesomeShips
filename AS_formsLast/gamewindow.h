#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QTextStream>
#include <QFile>
#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QStatusBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlDriver>
#include <QtSql>
#include <QSqlTableModel>
#include <QPainter>
#include "usernamedialog.h"
#include "ui_usernamedialog.h"
#include "tabledialog.h"
#include "ui_tabledialog.h"
#include "gamecontroller.h"
#include <QTcpSocket>

namespace Ui {
class GameWindow;
}

class GameWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit GameWindow(int languageID, int topicID, int userID, int level, int score, QString addr, QWidget *parent = 0);

    ~GameWindow();

private:

    UserNameDialog* userNameDialog;
    TableDialog* tableDialog;

    QSqlDatabase db;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *score;
    QSpacerItem *horizontalSpacer;
    QPushButton *menuPushButton;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_2;
    QLineEdit *inputField;
    QSpacerItem *horizontalSpacer_3;
    /////////
    GameController *gameController;
    int userID;
    QTcpSocket *client;
    QString address;

    void paintEvent(QPaintEvent *arg);

    void MakeInterface();
    void SetWindowStyle();
    void SQLConnectionOpen();
    void InitializeRandom();

signals:
    void MenuButtonPressed(bool isGameWindowActive=true);
public slots:
    void PauseGame();
    void ResumeGame();
private slots:
    void StartRead();
    void EndGame();
    void InputFieldTextChanged(QString word);
    void ShipDestroyedSlot(int shipIndex);
    //void ShipOwercomeBorderSlot(int shipIndex);
};

#endif // GAMEWINDOW_H
