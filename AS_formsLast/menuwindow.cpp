#include "menuwindow.h"
//#include "ui_menuwindow.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>

QObject* _Username;
QObject* _Password;
QObject* _IP;

MenuWindow::MenuWindow(QWidget *parent) :
    QMainWindow(parent)
{
    //Включаем QML
    ui = new QDeclarativeView;
    ui->setSource(QUrl("qrc:/main.qml"));
    setCentralWidget(ui);
    ui->setResizeMode(QDeclarativeView::SizeRootObjectToView);

    //Находим корневой элемент
    Root = ui->rootObject();
    //Соединяем C++ и QML, делая видимым функции С++ через элемент window
    ui->rootContext()->setContextProperty("window", this);
    setWindowFlags(Qt::CustomizeWindowHint | Qt::WindowTitleHint);

    _Username = Root->findChild<QObject*>("username");
    _Password = Root->findChild<QObject*>("password");
    _IP = Root->findChild<QObject*>("ip");

    //ui->setupUi(this);//не знаю что это: закомментирую

}

MenuWindow::~MenuWindow()
{
    delete ui;
}

void MenuWindow::GetUserData()
{
    if(Validate())
    {
        credentialsValid=true;
        UserName=(_Username->property("text")).toString();
        PassWord=(_Password->property("text")).toString();
        addr=(_IP->property("text")).toString();
    }
    else
    {
        credentialsValid=false;
    }
}

void MenuWindow::DisableSettingsButton()
{
    //ui->settingsPushButton->setDisabled(true);
}

void MenuWindow::EnableSettingsButton()
{
    //ui->settingsPushButton->setDisabled(false);
}

bool MenuWindow::getCredentialsState()
{
    return credentialsValid;
}

void MenuWindow::SetWindowStyle()
{
    QString str;
    QString fileName=":/Style.txt";
    QFile inputFile(fileName);
    QTextStream ts(&inputFile);
    if(!inputFile.open(QFile::ReadOnly | QFile::Text))
    {
        return;
    }
    str=ts.readAll();
    inputFile.close();
    this->setStyleSheet(str);
}

bool MenuWindow::Validate()
{
    bool isValid=true;

    if((_Username->property("text")).toString()=="")
    {
        QMessageBox message;
        message.setWindowTitle("Validation error");
        message.setText("Enter nickname, please.");
        message.exec();
        isValid=false;
    }
    else if((_Password->property("text")).toString()=="")
    {
        QMessageBox message;
        message.setWindowTitle("Validation error");
        message.setText("Enter password, please.");
        message.exec();
        isValid=false;
    }
    else if((_IP->property("text")).toString()=="")
    {
        QMessageBox message;
        message.setWindowTitle("Validation error");
        message.setText("Enter server address, please.");
        message.exec();
        isValid=false;
    }
    return isValid;
}


