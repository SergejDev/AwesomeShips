#include "WINDOW.h"
#include "workwithdb.h"
#include "baza.h"

QObject *_topicID;
QObject *_langID;

ToolsWindow::ToolsWindow(QMainWindow *parent):
    QMainWindow (parent)
{
    ui = new QDeclarativeView();
    ui->setSource(QUrl("qrc:/qml_WINDOW.qml"));
    setCentralWidget(ui);

    ui->setResizeMode(QDeclarativeView::SizeRootObjectToView);

    Root = ui->rootObject();
    ui->rootContext()->setContextProperty("window", this);

    setWindowFlags(Qt::CustomizeWindowHint | Qt::WindowTitleHint|Qt::FramelessWindowHint);

    _topicID = Root->findChild<QObject*>("combo_topic");
    _langID = Root->findChild<QObject*>("combo_lang");

    topicID = (_topicID->property("selectedindex")).toInt();
    languageID = (_langID->property("selectedindex")).toInt();
}

ToolsWindow::~ToolsWindow()
{
    delete ui;
    this->close();
}

int ToolsWindow::GetTopicID()
{
    return topicID;
}

int ToolsWindow::GetLanguageID()
{
    return languageID;
}

void ToolsWindow::on_button_Save_clicked()
{
    topicID = (_topicID->property("selectedindex")).toInt();
    languageID = (_langID->property("selectedindex")).toInt();
    this->hide();
    emit ButtonSaveClicked();
}

void ToolsWindow::ButtonBackClickedSlot()
{
    this->hide();
    emit ButtonBackClicked();
}
void ToolsWindow::button_baza_clicked()
{
   Baza *baza = new Baza;
   baza->show();
}

