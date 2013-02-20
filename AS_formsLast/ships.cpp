#include "ships.h"
#include <QDebug>

Ships::Ships(int windowWidth,QObject *parent):QObject(parent)
{
    this->windowWidth=windowWidth;
    gameAreaPadding=100;
    mooveTimerFrequency=25;
    border=500;
    mooveShipsAnimationsTimer=new QTimer();
    QObject::connect(mooveShipsAnimationsTimer,SIGNAL(timeout()),this,SLOT(MooveShipsAnimationsTimerSlot()));
    QObject::connect(this,SIGNAL(ShipOwercomeBorder(int)),this,SLOT(OvercomeBorderSlot(int)));
    mooveShipsAnimationsTimer->start(mooveTimerFrequency);
}

void Ships::DrawShips(QPainter* painter)
{
    for(int i = 0; i < allShips.size(); i++)
    {
        allShips[i]->DrawShip(painter);
    }
}

void Ships::AddShip(Ship* newShip)
{
    QPoint newPosition;
    do
    {
        int newX=RandInt(gameAreaPadding,windowWidth-gameAreaPadding);
        int newY=RandInt(-100,-20);
        newPosition.setX(newX);
        newPosition.setY(newY);
    }
    while(IsShipsOwerlap(newPosition));

    newShip->SetPosition(newPosition);
    allShips.append(newShip);
}

QPoint Ships::ShipPositionFromWord(QString typingWord)
{
    if(typingWord=="")
    {
        return QPoint(-2,-2);//empty input word error
    }
    for(int i = 0; i < allShips.size(); i++)
    {
        if(allShips[i]->GetWord().startsWith(typingWord,Qt::CaseInsensitive))
        {
            return allShips[i]->GetPosition();
        }
    }
    return QPoint(-1,-1);//error position
}

int Ships::ShipIndexFromWord(QString typingWord)
{
    if(typingWord=="")
    {
        return -2;//empty input word error
    }
    for(int i = 0; i < allShips.size(); i++)
    {
        if(allShips[i]->GetWord().startsWith(typingWord,Qt::CaseInsensitive))
        {
            return i;
        }
    }
    return -1;//error position
}

void Ships::ShipHited(int bulletIndex, int shipIndex)
{
    int damage=20;
    if(allShips.count()-1<shipIndex) return;
    allShips[shipIndex]->SetCurrentHP(allShips[shipIndex]->GetCurrentHP()-damage);
    if(allShips[shipIndex]->GetCurrentHP()<=0)
    {
        allShips.removeAt(shipIndex);
        emit ShipDestroyed(shipIndex);
    }
}

void Ships::PauseShips()
{
    mooveShipsAnimationsTimer->stop();
}

void Ships::ResumeShips()
{
    mooveShipsAnimationsTimer->start();
}

void Ships::MooveShipsAnimationsTimerSlot()
{
    MooveShips();
}

void Ships::OvercomeBorderSlot(int shipIndex)
{
    allShips.removeAt(shipIndex);
}


int Ships::RandInt(int low, int high)
{
    return qrand() % ((high + 1) - low) + low;
}

bool Ships::IsShipsOwerlap(QPoint newShipPosition)
{
    for(int i = 0; i < allShips.size(); i++)
    {
        if(allShips[i]->IsShipOwerlap(newShipPosition))
        {
            return true;
        }
    }
    return false;
}

void Ships::MooveShips()
{
    for(int i = 0; i < allShips.size(); i++)
    {
        QPoint oldPosition=allShips[i]->GetPosition();
        QPoint newPosition(oldPosition.x(),oldPosition.y()+allShips[i]->GetSpeed());
        allShips[i]->SetPosition(newPosition);
        if(newPosition.y()>border)
        {
            emit ShipOwercomeBorder(i);
        }
    }
    if(allShips.size()!=0)
    {
        emit ShipsPositionUpdate();
    }
}
