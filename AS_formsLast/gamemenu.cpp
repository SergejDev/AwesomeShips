#include "gamemenu.h"
#include "ui_gamemenu.h"
#include "gamecontroller.h"
#include "menuwindow.h"

gamemenu::gamemenu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::gamemenu)
{
    ui->setupUi(this);
    setWindowFlags(Qt::CustomizeWindowHint | Qt::WindowTitleHint);
    connect(ui->ResumeGame_pushButton,SIGNAL(clicked()),this,SIGNAL(ResumeGameButton_Pressed()));
    connect(ui->BackToMenu_pushButton,SIGNAL(clicked()),this,SIGNAL(BackToMenuButton_Pressed()));


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


