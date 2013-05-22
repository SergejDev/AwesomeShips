#include <QString>
#include <QtTest>
#include <ship.h>
#include <QString>
#include <QImage>
#include <QPainter>
#include <QCoreApplication>

class ShiptestTest : public QObject
{
    Q_OBJECT
    
public:
    ShiptestTest();
    
private Q_SLOTS:
    void testCase1Init();
    void testCase2SetPositionGetPosition();
    void testCase3SetCurrentHPGetCurrentHP();
    void testCase4Owerlap();
    void testCase5Draw();
    void testCase6Clear();
    void testCase7GetPointsAmount();
    void testCase8GetWordSpeed();
};

ShiptestTest::ShiptestTest()
{
}

void ShiptestTest::testCase1Init() //проверка инициализации
{
    Ship* sh = new Ship("rwrewr",4);

    //QString str=QString::number(ii);
    //QTextStream cout(stdout);
    //cout<<"Speed="<<sh->GetSpeed()<<"\n";
}

void ShiptestTest::testCase2SetPositionGetPosition() //проверка методов SetPosition() GetPosition()
{
    bool result=true;
    Ship* sh = new Ship("new_word",1);
    QPoint pn(100,150);
    sh->SetPosition(pn);
    if ((sh->GetPosition().x()!=100) || (sh->GetPosition().y()!=150))
        result = false;
    QCOMPARE(result, true);
}

void ShiptestTest::testCase3SetCurrentHPGetCurrentHP() //проверка методов SetCurrentHP() GetCurrentHP()
{
    bool result=true;
    QString str = "new_word";
    Ship* sh = new Ship(str,1);
    sh->SetCurrentHP(str.size());
    if (sh->GetCurrentHP()!=7)
        result = false;
    QCOMPARE(result, true);
}

void ShiptestTest::testCase4Owerlap() //проверка метода IsShipOwerlap()
{
    bool result;
    Ship* sh = new Ship("new_word",1);
    QPoint pn(100,150);
    sh->SetPosition(pn);
    result = sh->IsShipOwerlap(pn); //точка одна и та же - если все отработает правильно, то вернется true
    QCOMPARE(result, true);

    QPoint pnStart(500,150);
    QPoint pnEnd(100,450);
    sh->SetPosition(pnStart);
    result = sh->IsShipOwerlap(pnEnd); //точки далеко друг от друга - должно вернуться false
    QCOMPARE(result, false);
}

void ShiptestTest::testCase5Draw() //проверка метода DrawShip
{
    Ship* sh = new Ship("new_word",1);

    QImage* canvas=new QImage(1000,1000,QImage::Format_ARGB32);
    QPainter painter(canvas);
    sh->DrawShip(&painter);

}

void ShiptestTest::testCase6Clear() //проверка удаления объекта
{
    Ship* sh = new Ship("new_word",1);
    delete sh;
}

void ShiptestTest::testCase7GetPointsAmount() //проверка метода GetPointsAmount
{
    Ship* sh = new Ship("new_word",1);
    QCOMPARE(sh->GetPointsAmount(),10);
}

void ShiptestTest::testCase8GetWordSpeed() //проверка методов GetWord GetSpeed
{
    bool result=true;
    Ship* sh = new Ship("rwrewr",4); //уровень не соответсвует скорости. Не ошибка. Так и задумано
    if ((sh->GetWord()!="rwrewr") || (sh->GetSpeed()!=2))
        result = false;
    sh = new Ship("rwrewr",4); //уровень не соответсвует скорости. Не ошибка. Так и задумано
    if ((sh->GetWord()!="rwrewr") || (sh->GetSpeed()!=2))
        result = false;
    sh = new Ship("rwrewr",5);
    if ((sh->GetWord()!="rwrewr") || (sh->GetSpeed()!=2))
        result = false;
    sh = new Ship("rwrewr",8); //уровень не соответсвует скорости. Не ошибка. Так и задумано
    if ((sh->GetWord()!="rwrewr") || (sh->GetSpeed()!=3))
        result = false;
    sh = new Ship("rwrewr",9); //уровень не соответсвует скорости. Не ошибка. Так и задумано
    if ((sh->GetWord()!="rwrewr") || (sh->GetSpeed()!=3))
        result = false;
    QCOMPARE(result, true);
}

QTEST_MAIN(ShiptestTest)

#include "tst_shiptesttest.moc"
