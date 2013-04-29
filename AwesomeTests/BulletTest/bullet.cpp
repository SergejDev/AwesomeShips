#include "bullet.h"
#include <QPainter>
#include <QDebug>

Bullet::Bullet(QPoint aimPosition, int aimIndex)
{
    speed=60;
    this->aimPosition=aimPosition;
    this->aimIndex=aimIndex;
    bulletImage=new QImage("plasma_bullet_small.png");
    bulletSize.setWidth(bulletImage->width());
    bulletSize.setHeight(bulletImage->height());
}

int Bullet::GetSpeed()
{
    return speed;
}

void Bullet::DrawBullet(QPainter* painter)
{
    //    QPoint bulletPosition(position.x()-bulletSize.width()/2,position.y()-bulletSize.height()/2);
    //    painter->drawImage(bulletPosition,*bulletImage);

    int windowWidth=1000;
    QPoint shootPosition(windowWidth/2,590);
    drawLaser(painter,shootPosition,aimPosition);
}

void Bullet::drawLaser(QPainter *painter, QPoint &shootPosition, QPoint &aimPosition)
{
    painter->setRenderHint(QPainter::Antialiasing,true);

    QBrush outerLineBrush(QColor(0,90,200));
    QPen outerLinePen(outerLineBrush,4,Qt::SolidLine,Qt::RoundCap);
    painter->setPen(outerLinePen);
    painter->drawLine(shootPosition,aimPosition);

    QBrush innerLineBush(Qt::blue);
    QPen innerLinePen(innerLineBush,1,Qt::SolidLine,Qt::RoundCap);
    painter->setPen(innerLinePen);
    painter->drawLine(shootPosition,aimPosition);
}

void Bullet::SetPosition(QPoint newPosition)
{
    position=newPosition;
    //qDebug()<<position<<" - bullet position";
}

QPoint Bullet::GetPosition()
{
    return position;
}

QPoint Bullet::GetAimPosition()
{
    return aimPosition;
}

int Bullet::GetAimIndex()
{
    return aimIndex;
}


