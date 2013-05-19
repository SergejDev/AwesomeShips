#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QTimer>
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
#include "tabledialog.h"
#include "gamecontroller.h"
#include <QTcpSocket>
#include <QtDeclarative/QDeclarativeView>
#include <QGraphicsObject>
#include <QDeclarativeContext>


namespace Ui {
class GameWindow;
}

class GameWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit GameWindow(int languageID, int topicID, int userID, int level, int score, QString addr, QWidget *parent = 0);

    Q_INVOKABLE void PauseGame();
    Q_INVOKABLE void InputFieldTextChanged(QString word);



    ~GameWindow();

private:
    UserNameDialog* userNameDialog;
    TableDialog* tableDialog;

    GameController *gameController;
    int userID;
    QTcpSocket *client;
    QString address;

    QObject *root;
    QDeclarativeView *ui;
    QTimer *renderTimer;
    int renderFrequency;
    void setScore(QString score);
    void setLevel(QString level);
    void clearInputField();

    bool eventFilter(QObject *, QEvent *);

    void initializeFields();
    void initializeRenderTimer();
    void initializeQmlEngine();
    void MakeInterface();

signals:
    Q_INVOKABLE void MenuButtonPressed(bool isGameWindowActive=true);
    Q_INVOKABLE void EndGameFlag();

public slots:
    void ResumeGame();

private slots:
    void StartRead();
    void EndGame();
    void render();
    void ShipDestroyedSlot(int shipIndex);

    void GameOverOkClick();
};

#endif // GAMEWINDOW_H
