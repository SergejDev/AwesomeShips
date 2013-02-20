#ifndef GUN_H
#define GUN_H
#include <QPainter>

class Gun
{
private:
    double rotationAngle;
    QImage *gunImage;
    QSize gunSize;
    QPoint position;
public:
    Gun(int windowWidth);
    void DrawGun(QPainter *painter);
    void SetAim(QPoint aimPosition);
};

#endif // GUN_H
