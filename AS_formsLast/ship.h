#ifndef SHIP_H
#define SHIP_H
#include <QPoint>
#include <QSize>
#include <QImage>

class Ship
{
private:
    int shipsPadding;
    int speed;
    int speedOnLevels[5];
    int totalHP;
    int currentHP;
    int normalDamage;
    QPoint position;
    QSize shipSize;
    QImage *ShipImage1;
    QString word;

public:
    Ship(QString word, int level);
    int GetSpeed();
    void DrawShip(QPainter* Painter);
    void SetPosition(QPoint newPosition);
    QPoint GetPosition();
    QString GetWord();
    bool IsShipOwerlap(QPoint newShipPosition);
    void SetCurrentHP(int damage);
    int GetCurrentHP();

//signals:
//    void ShipOwercomeBorder();
};

#endif // SHIP_H
