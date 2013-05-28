#include <QDeclarativeComponent>
#include <QDeclarativeEngine>
#include "gamewindow.h"
#include <QObject>
#include "bullet.h"
#include <QTcpSocket>
#include <QHostAddress>
#include <QMessageBox>
#include <QStandardItemModel>
#include "menuwindow.h"
#include "windowscontroller.h"
#include <QDebug>

GameWindow::GameWindow(int languageID, int topicID, int userid, int level, int scores, QString addr, QWidget *parent) :
    QMainWindow(parent)
{
    userID = userid;
    address = addr;

    initializeQmlEngine();
    MakeInterface();
    gameController=new GameController(this->width(),level,languageID,topicID,scores, addr, this);

    initializeFields();
    initializeRenderTimer();

    connect(gameController,SIGNAL(GameAreaUpdate()),this, SLOT(update()));
    connect(gameController,SIGNAL(ShipDestroyed(int)),this,SLOT(ShipDestroyedSlot(int)));
    connect(gameController,SIGNAL(ShipOwercomeBorder(int)),this,SLOT(EndGame()));
    connect(gameController, SIGNAL(ShipOwercomeBorder(int)), this, SIGNAL(EndGameFlag()));
}

void GameWindow::PauseGame()
{
    gameController->PauseGame();
}

void GameWindow::ResumeGame()
{
    gameController->ResumeGame();
}

void GameWindow::EndGame()
{

    gameController->PauseGame();

    userNameDialog=new UserNameDialog(this);
    userNameDialog->show();
    QObject::connect(userNameDialog, SIGNAL(okButtonClicked()), this, SLOT(GameOverOkClick()));
}

void GameWindow::render()
{
    ui->viewport()->update();
}

void GameWindow::GameOverOkClick()
{
    QObject::disconnect(userNameDialog, SIGNAL(okButtonClicked()), this, SLOT(GameOverOkClick()));
    userNameDialog->close();
    client = new QTcpSocket(this);
    if (!client->isOpen())
    {
        QHostAddress addr(address);
        client->connectToHost(addr, 9485);
    }
    QStringList list;
    list.append("Update");
    list.append(QString::number(userID));
    list.append(QString::number(gameController->GetScore()));
    list.append(QString::number(gameController->GetLevel()));
    QDataStream stream(client);
    stream << list;
    connect(client,SIGNAL(readyRead()),this,SLOT(StartRead()));
}

void GameWindow::StartRead()
{
    QDataStream stream(client);
    QByteArray source;
    stream >> source;

    QString string(source);
    QStringList list1 = string.split(':');

    tableDialog=new TableDialog(this);
    tableDialog->show();
    tableDialog->ui->rootContext()->setContextProperty("list", list1);

    disconnect(client,SIGNAL(readyRead()),this,SLOT(StartRead()));
}

void GameWindow::InputFieldTextChanged(QString word)
{
    gameController->Shoot(word);
}

void GameWindow::ShipDestroyedSlot(int shipIndex)
{
    setScore("Score: "+QString::number(gameController->GetScore()));
    setLevel("Level: "+QString::number(gameController->GetLevel()+1));
    clearInputField();
}

void GameWindow::MakeInterface()
{
    setWindowFlags(Qt::CustomizeWindowHint | Qt::WindowTitleHint);
    setCentralWidget(ui);
    this->setFixedSize(1000,700);
    this->setWindowTitle("Awesome ships");
}

GameWindow::~GameWindow()
{

}

void GameWindow::setScore(QString score)
{
    QObject* scoreLabel = root->findChild<QObject*>("scoreLabel");
    scoreLabel->setProperty("text",score);
}

void GameWindow::setLevel(QString level)
{
    QObject* levelLabel = root->findChild<QObject*>("levelLabel");
    levelLabel->setProperty("text",level);
}

void GameWindow::clearInputField()
{
    QObject* inputField = root->findChild<QObject*>("inputField");
    inputField->setProperty("text","");
}

bool GameWindow::eventFilter(QObject *target, QEvent *event)
{
    if((target==ui->viewport()) && (event->type()==QEvent::Paint))
    {
        QPainter painter(ui->viewport());
        gameController->Draw(&painter);
    }

    return QMainWindow::eventFilter(target,event);
}

void GameWindow::initializeFields()
{
    renderFrequency=20;
    setScore("Score: "+QString::number(gameController->GetScore()));
    setLevel("Level: "+QString::number(gameController->GetLevel()+1));
}

void GameWindow::initializeRenderTimer()
{
    renderTimer=new QTimer(this);
    connect(renderTimer, SIGNAL(timeout()),this,SLOT(render()));
    renderTimer->start(renderFrequency);
}

void GameWindow::initializeQmlEngine()
{
    ui = new QDeclarativeView(this);
    ui->setSource(QUrl("qrc:/gameWindow.qml"));
    ui->setResizeMode(QDeclarativeView::SizeRootObjectToView);

    root = ui->rootObject();
    ui->rootContext()->setContextProperty("window", this);
    ui->viewport()->installEventFilter(this);
}
