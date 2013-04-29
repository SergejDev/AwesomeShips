#include <QtCore/QString>
#include <QImage>
#include <QPainter>
#include <QtTest/QtTest>
#include "bullet.h"

class BulletTest : public QObject
{
    Q_OBJECT

private:
    Bullet* testBullet;
    QPoint initAimPosition;
    int initAimIndex;
    
public:
    BulletTest();
    
private Q_SLOTS:
    void initTestCase();
    void cleanupTestCase();
    void getAimPosition();
    void getAimIndex();
    void setPosition();
    void getSpeed();
    void drawBullet();
    void drawLaser();
};

BulletTest::BulletTest()
{

}

void BulletTest::initTestCase()
{
    initAimPosition=QPoint(10,10);
    initAimIndex=0;
    testBullet=new Bullet(initAimPosition,initAimIndex);
}

void BulletTest::cleanupTestCase()
{
    delete testBullet;
}

void BulletTest::getAimPosition()
{
    QCOMPARE(testBullet->GetAimPosition(),initAimPosition);
}

void BulletTest::getAimIndex()
{
    QCOMPARE(testBullet->GetAimIndex(),initAimIndex);
}

void BulletTest::setPosition()
{
    QPoint newPosition(20,20);
    testBullet->SetPosition(newPosition);
    QCOMPARE(testBullet->GetPosition(),newPosition);
}

void BulletTest::getSpeed()
{
    QCOMPARE(testBullet->GetSpeed(),60);
}

void BulletTest::drawBullet()
{
    QImage* canvas=new QImage(1000,1000,QImage::Format_ARGB32);
    QPainter painter(canvas);
    testBullet->DrawBullet(&painter);
}

void BulletTest::drawLaser()
{
    QImage* canvas=new QImage(1000,1000,QImage::Format_ARGB32);
    QPainter painter(canvas);
    QPoint shootPoint(0,0);
    testBullet->drawLaser(&painter,shootPoint,initAimPosition);
}

QTEST_APPLESS_MAIN(BulletTest)

#include "tst_bullettest.moc"
