#ifndef BULLET_H
#define BULLET_H
#include <QPoint>
#include <QSize>
#include <QImage>


class Bullet
{
private:
    //int shipsPadding;
    int speed;
    QPoint position;
    QPoint aimPosition;
    int aimIndex;
    QSize bulletSize;
    QImage *bulletImage;
    void drawLaser(QPainter *painter, QPoint &shootPoint,QPoint &aimPosition, int r, int g, int b);

public:
    Bullet(QPoint aimPosition, int aimIndex);
    int GetSpeed();
    void DrawBullet(QPainter* Painter);
    void SetPosition(QPoint newPosition);
    QPoint GetPosition();
    QPoint GetAimPosition();
    int GetAimIndex();
};

#endif // BULLET_H
