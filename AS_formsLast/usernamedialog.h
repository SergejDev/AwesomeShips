#ifndef USERNAMEDIALOG_H
#define USERNAMEDIALOG_H

#include <QDialog>

namespace Ui {
class UserNameDialog;
}

class UserNameDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit UserNameDialog(QWidget *parent = 0);
    ~UserNameDialog();
    

    Ui::UserNameDialog *ui;
};

#endif // USERNAMEDIALOG_H
