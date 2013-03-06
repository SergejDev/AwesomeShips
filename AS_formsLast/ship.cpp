#include "ship.h"
#include <QPainter>
#include <math.h>
#include <QDebug>

Ship::Ship(QString word,int level)
{
    InitializeSpeedSettings();
    shipsPadding=50;
    speed=speedOnLevels[level];
    totalHP=word.size();
    currentHP=totalHP;
    normalDamage=1;
    this->word=word;
    ShipImage1 = new QImage("dk2_darker.png");
    shipSize.setWidth(ShipImage1->width());
    shipSize.setHeight(ShipImage1->height());
}

void Ship::InitializeSpeedSettings()
{
    speedOnLevels[0]=1;
    speedOnLevels[1]=1;
    speedOnLevels[2]=1;
    speedOnLevels[3]=2;
    speedOnLevels[4]=2;
    speedOnLevels[5]=2;
    speedOnLevels[6]=2;
    speedOnLevels[7]=2;
    speedOnLevels[8]=3;
    speedOnLevels[9]=3;
}

int Ship::GetSpeed()
{
    return speed;
}

void Ship::DrawShip(QPainter* painter)
{
    QPoint shipPosition(position.x()-shipSize.width()/2,position.y()-shipSize.height()/2);
    painter->drawImage(shipPosition,*ShipImage1);

    QFont font("Calibri",13);
    QFontMetrics fm(font);
    //drawGreen
    QPoint startTextPosition(position.x()-fm.width(word)/2,
                             position.y()-shipSize.height()/2-30);
    int textWidth=shipSize.width();
    int textHeight=30;
    int firstPartLetterCount = word.size() - int((static_cast<double>(currentHP)/static_cast<double>(normalDamage))+0.5);

    QString wordPart = word.mid(0,firstPartLetterCount);
    painter->setPen(QColor(50,255,50));
    painter->setFont(font);
    painter->drawText(startTextPosition.x(),startTextPosition.y(),textWidth,textHeight,Qt::AlignLeft,wordPart);
    QString wordSecPart = word.mid(firstPartLetterCount,word.size()-firstPartLetterCount);
    painter->setPen(QColor(255,255,255));
    painter->setFont(font);
    painter->drawText(startTextPosition.x()+fm.width(wordPart),startTextPosition.y(),textWidth,textHeight,Qt::AlignLeft,wordSecPart);

    painter->drawRect(position.x()-51,position.y()-shipSize.height()/2-1,102,7);
    painter->fillRect(position.x()-50,position.y()-shipSize.height()/2,((double)currentHP/(double)totalHP)*100,5,Qt::green);
}

void Ship::SetPosition(QPoint newPosition)
{
    position=newPosition;
}

QPoint Ship::GetPosition()
{
    return position;
}

QString Ship::GetWord()
{
    return word;
}

bool Ship::IsShipOwerlap(QPoint newShipPosition)
{
//    int newShipX=newShipPosition.x()-shipSize.width()/2;
//    int newShipY=newShipPosition.y()-shipSize.width()/2;
    int newShipX=newShipPosition.x();
    int newShipY=newShipPosition.y();
    if((abs(newShipX-position.x())<shipSize.width()/2+shipsPadding) &&
            (abs(newShipY-position.y())<shipSize.height()/2+shipsPadding))
    {
        return true;
    }
    return false;
}

void Ship::SetCurrentHP(int currentHP)
{
    this->currentHP-=normalDamage;
}

int Ship::GetCurrentHP()
{
    return currentHP;
}
