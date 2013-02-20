#ifndef SHIPS_H
#define SHIPS_H
#include "ship.h"
#include <QTimer>
#include <QObject>

class Ships: public QObject
{
    Q_OBJECT
private:
    int gameAreaPadding;
    int mooveTimerFrequency;
    int border;
    QList<Ship*> allShips;
    //QPainter* Painter;
    int windowWidth;
    QTimer *mooveShipsAnimationsTimer;

    int RandInt(int low, int high);
    bool IsShipsOwerlap(QPoint newShipPosition);
    void MooveShips();


public:
    Ships(int windowWidth, QObject *parent=0);
    void DrawShips(QPainter* painter);
    void AddShip(Ship* newShip);
    QPoint ShipPositionFromWord(QString typingWord);
    int ShipIndexFromWord(QString typingWord);
    void ShipHited(int bulletIndex, int shipIndex);
    void PauseShips();
    void ResumeShips();

signals:
    void ShipsPositionUpdate();
    void ShipOwercomeBorder(int shipIndex);
    void ShipDestroyed(int shipIndex);

private slots:
    void MooveShipsAnimationsTimerSlot();
    void OvercomeBorderSlot(int shipIndex);
    //void ShipDestroyedSlot(int shipIndex);
};

#endif // SHIPS_H
