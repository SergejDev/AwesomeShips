#ifndef BULLETS_H
#define BULLETS
#include "bullet.h"
#include <QTimer>
#include <QObject>

class Bullets: public QObject
{
    Q_OBJECT
private:
    //int gameAreaPadding;
    int mooveTimerFrequency;
    QList<Bullet*> allBullets;
    //QPainter* Painter;
    int windowWidth;
    QTimer *mooveBulletsAnimationsTimer;

    void MooveBullets();
    QPoint GetNextBulletPosition(Bullet* bullet);
    bool IsAimHited(Bullet* bullet);

public:
    Bullets(int windowWidth,QObject *parent=0);
    void DrawBullets(QPainter* painter);
    void AddBullet(Bullet* newBullet);
    void PauseBullets();
    void ResumeBullets();

signals:
    void BulletsPositionUpdate();
    void AimHit(int bulletIndex,int shipIndex);

private slots:
    void MooveBulletsAnimationsTimerSlot();
    void AimHitSlot(int bulletIndex,int shipIndex);
};

#endif // BULLETS_H
