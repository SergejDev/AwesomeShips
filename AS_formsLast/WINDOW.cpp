#include "WINDOW.h"
#include "QString"
#include "QStringList"
#include "QFile"
#include "QTextStream"
#include "workwithdb.h"

ToolsWindow::ToolsWindow(QWidget *parent):
    QWidget (parent)
{
    topicID=1;
    languageID=0;
    setupToolsWindow(this);
    connect(button_Save,SIGNAL(clicked()), this, SLOT(on_button_Save_clicked()));
    //connect(button_Save,SIGNAL(clicked()), this, SIGNAL(ButtonSaveClicked()));
    //connect(button_toMainMenu,SIGNAL(clicked()), this, SIGNAL(ButtonBackClicked()));
    connect(button_toMainMenu,SIGNAL(clicked()), this, SLOT(ButtonBackClickedSlot()));
}

ToolsWindow::~ToolsWindow()
{
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

void ToolsWindow::setupToolsWindow(QWidget *ToolsWindowForm)
{
    if (ToolsWindowForm->objectName().isEmpty())
        ToolsWindowForm->setObjectName(QString::fromUtf8("ToolsWindow"));
    ToolsWindowForm->resize(450, 375);

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
    QPalette pallete;
    pallete.setBrush(ToolsWindowForm->backgroundRole(), QBrush(QPixmap(":/deepness_1600.jpg")));
    ToolsWindowForm->setPalette(pallete);
    ToolsWindowForm->autoFillBackground();

    button_toMainMenu = new QPushButton(ToolsWindowForm);
    button_Save = new QPushButton(ToolsWindowForm);
    button_toMainMenu->setObjectName("button_toMainMenu");
    button_Save->setObjectName("button_Save");
    button_toMainMenu->setGeometry(40, 310, 120, 35);
    button_Save->setGeometry(290, 310, 120, 35);
    button_toMainMenu->setText(QString::fromUtf8("Back to menu"));
    button_Save->setText(QString::fromUtf8("Save"));

    label_Lang = new QLabel(ToolsWindowForm);
    label_Topic = new QLabel(ToolsWindowForm);
    label_main = new QLabel(ToolsWindowForm);


    label_Lang->setObjectName("label_Lang");
    label_Topic->setObjectName("label_Topic");
    label_main->setObjectName("label_main");


    label_Lang->setGeometry(QRect(100, 100, 91, 20));
    label_Lang->setText(QString::fromUtf8("Language"));


    label_Topic->setGeometry(QRect(100, 180, 51, 21));
    label_Topic->setText(QString::fromUtf8("Topic"));

    label_main->setGeometry(QRect(190, 30, 121, 21));
    label_main->setText(QString::fromUtf8("Settings"));


    Combo_Lang = new QComboBox(ToolsWindowForm);
    Combo_Topic = new QComboBox(ToolsWindowForm);

    Combo_Lang->setObjectName("Combo_Lang");
    Combo_Topic->setObjectName("Combo_Topic");

    Combo_Lang->setGeometry(QRect(220, 100, 131, 31));
    Combo_Topic->setGeometry(QRect(218, 180, 131, 31));

    Combo_Lang->insertItems(0, QStringList()<<QString::fromUtf8("Russian")<<QString::fromUtf8("English"));
    Combo_Topic->insertItems(0, QStringList()<<QString::fromUtf8("Food")<<QString::fromUtf8("Weather")<<QString::fromUtf8("Animals"));
    Combo_Lang->setCurrentIndex(0);
    Combo_Topic->setCurrentIndex(0);
}

void ToolsWindow::on_button_Save_clicked()
{
    topicID = Combo_Topic->currentIndex()+1;
    languageID = Combo_Lang->currentIndex();
    this->hide();
    emit ButtonSaveClicked();
}

void ToolsWindow::ButtonBackClickedSlot()
{
    this->hide();
    emit ButtonBackClicked();
}


