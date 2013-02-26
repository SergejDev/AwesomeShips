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
    QString UserName;
    QString PassWord;
    QString addr;

private:
    Ui::MenuWindow *ui;
    void SetWindowStyle();
    bool Validate();
    QPushButton *RegisterButton;

public slots:
    void GetUserData();

signals:
    void StartButtonPressed();
    void RegisterButtonPressed();
    void SettingsButtonPressed();
    void QuitButtonPressed();

};

#endif // MENUWINDOW_H
