#include "gamecontroller.h"
#include <QStringList>
#include <QDebug>
#include <QMessageBox>
#include <QString>
#include <QHostAddress>

GameController::GameController(int windowWidth,int level,int languageID,int topicID, int score,QString addr, QObject *parrent):QObject(parrent)
{
    //wordGetter=new WorkWithDB("Words.s3db");
    //wordGetter->SetParams(3,topicID,languageID);
    //words=wordGetter->GetWords();

    client = new QTcpSocket(this);
    if (!client->isOpen())
    {
        QHostAddress address(addr);
        client->connectToHost(address, 9485);
    }
    QStringList list;
    list.append("Words");
    list.append(QString::number(topicID));
    list.append(QString::number(languageID));
    QDataStream stream(client);
    stream << list;

    QString string("");
    while (string.length() < 1){
        qApp->processEvents();
        QDataStream stream(client);
        QByteArray source;
        stream >> source;

        string = QString::QString(source);
    }

    words = string.split(",");

    currentScore=score;
    scorePointsForDestroyingShip=10;

    currentLevel=level;
    scoresPerLevel=100;

    allShips=new Ships(windowWidth,parrent);
    allBullets=new Bullets(windowWidth,parrent);
    gun=new Gun(windowWidth);
    currentWordIndex=0;
    background=new QImage(":/deepness_1600.jpg");

    animationTimerFrequency=25;
    animationsTimer=new QTimer();
    QObject::connect(animationsTimer,SIGNAL(timeout()),this,SLOT(AnimationsTimerSlot()));

    InitializeLevelSettings();

    addShipTimer=new QTimer();
    QObject::connect(addShipTimer,SIGNAL(timeout()),this,SLOT(AddShipTimerSlot()));

    QObject::connect(allBullets,SIGNAL(ShipHit(int,int)),this,SLOT(ShipHitedSlot(int,int)));

    QObject::connect(allShips,SIGNAL(ShipDestroyed(int)),this,SLOT(ShipDestroyedSlot(int)));
    QObject::connect(allShips,SIGNAL(ShipDestroyed(int)),this,SIGNAL(ShipDestroyed(int)));

    QObject::connect(allShips,SIGNAL(ShipOwercomeBorder(int)),this,SIGNAL(ShipOwercomeBorder(int)));

    animationsTimer->start(animationTimerFrequency);
    addShipTimer->start(addShipTimerFrequency);
}

void GameController::AddShip()
{
    if (GetScore()%50==0)
    {
        allShips->AddShip(new ShipExtended(GetWordForShip(),currentLevel));
    }
    else
    {
        allShips->AddShip(new Ship(GetWordForShip(),currentLevel));
    }
}

void GameController::Draw(QPainter *painter)
{
    painter->drawImage(0,0,*background);
    allShips->DrawShips(painter);
    allBullets->DrawBullets(painter);
    gun->DrawGun(painter);
}

void GameController::Shoot(QString word)//inits when key was pressed
{
    if(IsSuccessfulShoot(word))
    {
        int aimIndex=allShips->ShipIndexFromWord(word);
        QPoint aimPosition=allShips->ShipPositionFromWord(word);
        allBullets->AddBullet(new Bullet(aimPosition,aimIndex));
        gun->SetAim(aimPosition);
    }
}

void GameController::SetLevel(int level)
{
    currentLevel=level;
}

int GameController::GetScore()
{
    return currentScore;
}
int GameController::GetLevel()
{
    return currentLevel;
}

void GameController::PauseGame()
{
    allShips->PauseShips();
    allBullets->PauseBullets();
    addShipTimer->stop();
}

void GameController::ResumeGame()
{
    allShips->ResumeShips();
    allBullets->ResumeBullets();
    addShipTimer->start();
}

void GameController::NextLevel()
{
    currentLevel+=1;
}

void GameController::AnimationsTimerSlot()
{
    emit GameAreaUpdate();
}

void GameController::AddShipTimerSlot()
{
    AddShip();
}

void GameController::ShipHitedSlot(int bulletIndex, int shipIndex)
{
    allShips->ShipHited(bulletIndex,shipIndex);
}

void GameController::ShipDestroyedSlot(int points)
{
    currentScore+=points;
    if(currentScore>=(currentLevel+1)*scoresPerLevel)
    {
        //qDebug()<<"current level"<<currentLevel+1;
        NextLevel();
        addShipTimerFrequency=addShipTimerFrequencyOnLevels[currentLevel];
        addShipTimer->setInterval(addShipTimerFrequency);
    }
}

//int GameController::RandInt(int low, int high)//!!!!!!
//{
//    return qrand() % ((high + 1) - low) + low;
//}

QString GameController::GetWordForShip()//TO DO: Get words from DB (don't forget about RandInt)
{
    if(currentWordIndex>=words.size())
    {
        currentWordIndex=0;
    }
    //qDebug()<<currentWordIndex<<" word index";
    QString result=words[currentWordIndex];
    currentWordIndex++;

    return result;
}

bool GameController::IsSuccessfulShoot(QString word)
{
    QPoint aimPosition=allShips->ShipPositionFromWord(word);
    if(((aimPosition!=QPoint(-1,-1))&&(aimPosition!=QPoint(-2,-2)))&&(previousWord.size()<word.size()))
    {
        previousWord=word;
        return true;
    }
    else
    {
        previousWord=word;
        return false;
    }
}

GameController::~GameController()
{
    delete gun;
}

void GameController::InitializeLevelSettings()
{
    addShipTimerFrequencyOnLevels[0]=6000;
    addShipTimerFrequencyOnLevels[1]=5000;
    addShipTimerFrequencyOnLevels[2]=4000;
    addShipTimerFrequencyOnLevels[3]=3000;
    addShipTimerFrequencyOnLevels[4]=2000;
    addShipTimerFrequencyOnLevels[5]=1900;
    addShipTimerFrequencyOnLevels[6]=1800;
    addShipTimerFrequencyOnLevels[7]=1700;
    addShipTimerFrequencyOnLevels[8]=1600;
    addShipTimerFrequencyOnLevels[9]=1500;
    addShipTimerFrequency=addShipTimerFrequencyOnLevels[currentLevel];
}
