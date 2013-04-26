#ifndef SHIP_H
#define SHIP_H
#include <QPoint>
#include <QSize>
#include <QtGui/QImage>

class Ship
{
protected:
    QImage *ShipImage1;
    int speed;

private:
    int shipsPadding;
    int speedOnLevels[10];
    int totalHP;
    QPoint position;
    QSize shipSize;
    QString word;
    void InitializeSpeedSettings();

public:
    int currentHP;
    int normalDamage;
    int pointsForKill;
    Ship(QString word, int level);
    int GetSpeed();
    void DrawShip(QPainter* Painter);
    void SetPosition(QPoint newPosition);
    QPoint GetPosition();
    QString GetWord();
    bool IsShipOwerlap(QPoint newShipPosition);
    void SetCurrentHP(int damage);
    int GetCurrentHP();
    int GetPointsAmount();
//signals:
//    void ShipOwercomeBorder();
};

#endif // SHIP_H
