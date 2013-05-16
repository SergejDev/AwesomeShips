#include "tabledialog.h"

TableDialog::TableDialog(QWidget *parent) :
    QMainWindow(parent)
{
    ui = new QDeclarativeView;
    ui->setSource(QUrl("qrc:/tabledialog.qml"));
    ui->setResizeMode(QDeclarativeView::SizeRootObjectToView);
    setCentralWidget(ui);
    ui->rootContext()->setContextProperty("window", this);
}

TableDialog::~TableDialog()
{
    delete ui;
}

void TableDialog::closeEvent(QCloseEvent *)
{
    //QApplication::quit();
}
