#include "usernamedialog.h"
#include "ui_usernamedialog.h"

UserNameDialog::UserNameDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UserNameDialog)
{
    ui->setupUi(this);
}

UserNameDialog::~UserNameDialog()
{
    delete ui;
}
