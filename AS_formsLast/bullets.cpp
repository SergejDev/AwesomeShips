#include "bullets.h"
#include <math.h>
#include <QDebug>


Bullets::Bullets(int windowWidth,QObject *parent):QObject(parent)
{
    this->windowWidth=windowWidth;
    mooveTimerFrequency=25;
    mooveBulletsAnimationsTimer=new QTimer();
    QObject::connect(mooveBulletsAnimationsTimer,SIGNAL(timeout()),this,SLOT(MooveBulletsAnimationsTimerSlot()));
    QObject::connect(this,SIGNAL(AimHit(int,int)),this,SLOT(AimHitSlot(int,int)));
    mooveBulletsAnimationsTimer->start(mooveTimerFrequency);
}

void Bullets::DrawBullets(QPainter* painter)
{
    for(int i = 0; i < allBullets.size(); i++)
    {
        allBullets[i]->DrawBullet(painter);
    }
}

void Bullets::AddBullet(Bullet* newBullet)
{
    QPoint shootPosition(windowWidth/2,590);
    newBullet->SetPosition(shootPosition);
    allBullets.append(newBullet);
}

void Bullets::PauseBullets()
{
    mooveBulletsAnimationsTimer->stop();
}

void Bullets::ResumeBullets()
{
    mooveBulletsAnimationsTimer->start();
}

void Bullets::MooveBulletsAnimationsTimerSlot()
{
    MooveBullets();
}

void Bullets::AimHitSlot(int bulletIndex, int shipIndex)
{
    allBullets.removeAt(bulletIndex);
    qDebug()<<shipIndex<<" shipIndex";
}

void Bullets::MooveBullets()
{
    for(int i = 0; i < allBullets.size(); i++)
    {
        QPoint newPosition=GetNextBulletPosition(allBullets[i]);
        allBullets[i]->SetPosition(newPosition);
        if(IsAimHited(allBullets[i]))
        {
            emit AimHit(i,allBullets[i]->GetAimIndex());//!!!!!!!
        }
    }
    if(allBullets.size()!=0)
    {
        emit BulletsPositionUpdate();
    }
}

QPoint Bullets::GetNextBulletPosition(Bullet *bullet)
{
    QPoint currentPosition=bullet->GetPosition();
    QPoint aimPosition=bullet->GetAimPosition();

    double dx=currentPosition.x()-aimPosition.x();
    double dy=currentPosition.y()-aimPosition.y();
    double tan=dy/dx;
    double angle=atan(tan);
    double bulletSpeed=bullet->GetSpeed();
    double x=bulletSpeed*cos(angle);
    double y=bulletSpeed*sin(angle);
    if(!(x>0 && y<0))
    {
        x=-x;
        y=-y;
    }
    return QPoint(currentPosition.x()+x,currentPosition.y()+y);
}

bool Bullets::IsAimHited(Bullet *bullet)
{
    QPoint aimPosition=bullet->GetAimPosition();
    QPoint bulletPosition=bullet->GetPosition();
    int dx=abs(aimPosition.x()-bulletPosition.x());
    int dy=abs(aimPosition.y()-bulletPosition.y());
    int threshold=20;
    if((dx+dy)<threshold)
    {
        return true;
    }
    else
    {
        return false;
    }
}
