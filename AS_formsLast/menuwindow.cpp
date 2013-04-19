#include "menuwindow.h"
//#include "ui_menuwindow.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>

QObject* _Username;
QObject* _Password;
QObject* _IP;
QString TempUserName;
QString TempPassWord;
QString Tempaddr;

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

    //_Username = Root->findChild<QObject*>("_Username");
    //_Password = Root->findChild<QObject*>("_Password");
    //_IP = Root->findChild<QObject*>("_IP");

    //ui->setupUi(this);//не знаю что это: закомментирую
    //setModal(true);

}

MenuWindow::~MenuWindow()
{
    delete ui;
}

void MenuWindow::GetUserData()
{
    QMessageBox message2; //это сообщение показывает, что программа заходит в процедуру
    message2.setWindowTitle("Validation error");
    message2.setText("111111");
    message2.exec();

    _Username = Root->findChild<QObject*>("username");
    //а тут ошибка, объект не находится, хотя строчка работоспособная, взята из примера на хабрахабре, в пустом проекте работала правильно
    _Password = Root->findChild<QObject*>("password");
    _IP = Root->findChild<QObject*>("ip");

    QMessageBox message4;
    message4.setWindowTitle("Validation error");
    //if (_Username->children().isEmpty()==true)
    if (Root->findChild<QObject*>("password")==0)
        message4.setText("true"); //видим, что объект Root пустой
    else
        message4.setText("false");

    message4.exec();

    QMessageBox message;
    message.setWindowTitle("Validation error");
    message.setText(((_Username->property("text"))).toString());
    message.exec();

    QMessageBox message3;
    message3.setWindowTitle("Validation error");
    message3.setText("33333");
    message3.exec();

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


