#ifndef MENUWINDOW_H
#define MENUWINDOW_H

#include <QMainWindow>
#include <QtDeclarative/QDeclarativeView>
#include <QGraphicsObject>
#include <QtGui>
#include <QDeclarativeContext>

namespace Ui {
    class MenuWindow;
}

class MenuWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MenuWindow(QWidget *parent = 0);
    ~MenuWindow();
    void DisableSettingsButton();
    void EnableSettingsButton();
    QString UserName;///перенести в привате и дописать геттеры
    QString PassWord;
    QString addr;
    bool getCredentialsState();
    Q_INVOKABLE void GetUserData();

private:

    QDeclarativeView *ui;
    void SetWindowStyle();
    bool Validate();
    QPushButton *RegisterButton;
    bool credentialsValid;
    QObject *Root;//корневой элемент QML модели

//public slots:
    //Q_INVOKABLE void GetUserData();

signals:
    Q_INVOKABLE void StartButtonPressed();
    Q_INVOKABLE void RegisterButtonPressed();
    Q_INVOKABLE void SettingsButtonPressed();
    Q_INVOKABLE void QuitButtonPressed();

};

#endif // MENUWINDOW_H
