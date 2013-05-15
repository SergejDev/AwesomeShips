#ifndef USERNAMEDIALOG_H
#define USERNAMEDIALOG_H

#include <QMainWindow>
#include <QtDeclarative/QDeclarativeView>
#include <QGraphicsObject>
#include <QtGui>
#include <QDeclarativeContext>

namespace Ui {
class UserNameDialog;
}

class UserNameDialog : public QMainWindow
{
    Q_OBJECT

public:
    explicit UserNameDialog(QWidget *parent = 0);
    ~UserNameDialog();
    QObject *Root;

private:
    QDeclarativeView *ui;
    //Ui::UserNameDialog *ui;

signals:
    Q_INVOKABLE void okButtonClicked();
};

#endif // USERNAMEDIALOG_H
