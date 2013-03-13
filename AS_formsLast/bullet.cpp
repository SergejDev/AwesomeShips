#include "bullet.h"
#include <QPainter>
#include <QDebug>
#include <QTimer>

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
    drawLaser(painter,shootPosition,aimPosition, 200, 70, 70);
}

void Bullet::drawLaser(QPainter *painter, QPoint &shootPosition, QPoint &aimPosition, int r, int g, int b)
{
    painter->setRenderHint(QPainter::Antialiasing,true);

    QBrush outerLineBrush(QColor(r,g,b));
    QPen outerLinePen(outerLineBrush,10,Qt::SolidLine,Qt::RoundCap);
    painter->setPen(outerLinePen);
    painter->drawLine(shootPosition,aimPosition);

    QBrush innerLineBush(Qt::red);
    QPen innerLinePen(innerLineBush,4,Qt::SolidLine,Qt::RoundCap);
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


