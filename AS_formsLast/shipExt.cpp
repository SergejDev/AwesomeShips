#include "ship.h"
#include "shipExt.h"
#include <QDebug>

ShipExtended::ShipExtended(QString word, int level): Ship(word, level)
{
    ShipImage1 = new QImage("db2_darker.png");
    speed++;
    pointsForKill=20;
}
