#include "gamemenu.h"
#include "ui_gamemenu.h"
#include "gamecontroller.h"
#include "menuwindow.h"

gamemenu::gamemenu(QMainWindow *parent) :
    QMainWindow(parent)
   // ui(new Ui::gamemenu)
{
   // ui->setupUi(this);
    ui = new QDeclarativeView(this);
    ui->setSource(QUrl("qrc:/gamemenu.qml"));
    ui->setResizeMode(QDeclarativeView::SizeRootObjectToView);
    setCentralWidget(ui);

    //Находим корневой элемент
    Root = ui->rootObject();
    //Соединяем C++ и QML, делая видимым функции С++ через элемент window
    ui->rootContext()->setContextProperty("window", this);
    setWindowFlags(Qt::CustomizeWindowHint | Qt::WindowTitleHint);
    setWindowTitle("Awesome ships");
   // setFixedSize(220,360);
   // connect(ui->ResumeGame_pushButton,SIGNAL(clicked()),this,SIGNAL(ResumeGameButton_Pressed()));
    //connect(ui->BackToMenu_pushButton,SIGNAL(clicked()),this,SIGNAL(BackToMenuButton_Pressed()));


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

gamemenu::~gamemenu()
{
    delete ui;
}


