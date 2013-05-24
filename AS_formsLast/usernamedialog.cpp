#include "usernamedialog.h"

UserNameDialog::UserNameDialog(QWidget *parent) :
    QMainWindow(parent)
{
    ui = new QDeclarativeView;
    ui->setSource(QUrl("qrc:/usernamedialog.qml"));
    ui->setResizeMode(QDeclarativeView::SizeRootObjectToView);
    setCentralWidget(ui);
    Root = ui->rootObject();
    ui->rootContext()->setContextProperty("window", this);
}

UserNameDialog::~UserNameDialog()
{
    delete ui;
}
