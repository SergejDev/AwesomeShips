#ifndef MENUWINDOW_H
#define MENUWINDOW_H

#include <QDialog>

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
    bool getCredentialsState();

private:

    Ui::MenuWindow *ui;
    void SetWindowStyle();
    bool Validate();
    QPushButton *RegisterButton;
    bool credentialsValid;

public slots:
    void GetUserData();

signals:
    void StartButtonPressed();
    void RegisterButtonPressed();
    void SettingsButtonPressed();
    void QuitButtonPressed();
};

#endif // MENUWINDOW_H
