#include "bullet.h"
#include <QPainter>

Bullet::Bullet(QPoint aimPosition, int aimIndex)
{
    speed=20;
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
    QPoint bulletPosition(position.x()-bulletSize.width()/2,position.y()-bulletSize.height()/2);
    painter->drawImage(bulletPosition,*bulletImage);
}

void Bullet::SetPosition(QPoint newPosition)
{
    position=newPosition;
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


