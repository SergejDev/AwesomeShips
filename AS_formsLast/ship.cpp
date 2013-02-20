#include "ship.h"
#include <QPainter>
#include <math.h>
#include <QDebug>


Ship::Ship(QString word,int level)
{
    speedOnLevels[0]=1;speedOnLevels[1]=1;speedOnLevels[2]=1;speedOnLevels[3]=2;speedOnLevels[4]=2;
    shipsPadding=50;
    speed=speedOnLevels[level];
    totalHP=100;
    currentHP=totalHP;
    normalDamage=ceil((double)totalHP/(double)word.size());
    qDebug()<<(double)totalHP/(double)word.size()<<"  "<<normalDamage;
    this->word=word;
    ShipImage1 = new QImage("dk2_darker.png");
    shipSize.setWidth(ShipImage1->width());
    shipSize.setHeight(ShipImage1->height());
}

int Ship::GetSpeed()
{
    return speed;
}

void Ship::DrawShip(QPainter* painter)
{
    QPoint shipPosition(position.x()-shipSize.width()/2,position.y()-shipSize.height()/2);
    painter->drawImage(shipPosition,*ShipImage1);

    QPoint textPosition(position.x()-shipSize.width()/2,position.y()-shipSize.height()/2-30);
    int textWhidth=shipSize.width();
    int textHeight=30;
    painter->setPen(QColor(255,255,255));
    painter->setFont(QFont("Calibri",13));
    painter->drawText(textPosition.x(),textPosition.y(),textWhidth,textHeight,Qt::AlignCenter,word);

    painter->drawRect(position.x()-51,position.y()-shipSize.height()/2-1,102,7);
    painter->fillRect(position.x()-50,position.y()-shipSize.height()/2,currentHP,5,Qt::green);
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
    else
    {
        return false;
    }
}

void Ship::SetCurrentHP(int currentHP)
{
    this->currentHP-=normalDamage;
}

int Ship::GetCurrentHP()
{
    return currentHP;
}

