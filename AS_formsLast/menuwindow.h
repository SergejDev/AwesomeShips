#ifndef MENUWINDOW_H
#define MENUWINDOW_H

#include <QDialog>
#include <login.h>

namespace Ui {
class MenuWindow;
}

class MenuWindow : public QDialog
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
    bool credentialsValid;
    bool getCredentialsState();
    LoginDialog *loginWindow;

private:

    Ui::MenuWindow *ui;
    void SetWindowStyle();
    QPushButton *LoginB;


public slots:
    void OpenLoginWindow();

signals:
    void StartButtonPressed();
    void SettingsButtonPressed();
    void QuitButtonPressed();

};

#endif // MENUWINDOW_H
