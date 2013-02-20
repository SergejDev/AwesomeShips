#include "gun.h"
#include <math.h>
#include <QDebug>

Gun::Gun(int windowWidth)
{
    rotationAngle=0;
    gunImage=new QImage("gun.png");
    gunSize.setWidth(gunImage->width());
    gunSize.setHeight(gunImage->height());
    position=QPoint(windowWidth/2,590);
}

void Gun::DrawGun(QPainter *painter)
{
    painter->translate(position);
    painter->rotate(rotationAngle);
    painter->drawImage(QPoint(-gunSize.width()/2,-gunSize.height()/2),*gunImage);
}

void Gun::SetAim(QPoint aimPosition)
{
    double dx=position.x()-aimPosition.x();
    double dy=position.y()-aimPosition.y();
    double tan=dy/dx;
    if(dx<0)
    {
        rotationAngle=atan(tan)*180/3.14+90;
    }
    else
    {
        rotationAngle=atan(tan)*180/3.14-90;
    }
}
