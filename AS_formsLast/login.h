#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include <QTcpSocket>

namespace Ui {
class LoginDialog;
}

class LoginDialog : public QDialog
{
    Q_OBJECT
private:
    bool Validate();
    QPushButton *RegisterButton;

    QTcpSocket *client;

public:
    explicit LoginDialog(QWidget *parent = 0);

    ~LoginDialog();

    Ui::LoginDialog *uiL;
private slots:
    void on_LoginButton_clicked();
    void GetUserData();

signals:
    void RegisterButtonPressed();
    void StartButtonPressed();
};

#endif // LOGIN_H
