#include <QString>
#include <QtTest>
#include <ship.h>
#include <QString>
#include <QTextStream>

class ShiptestTest : public QObject
{
    Q_OBJECT
    
public:
    ShiptestTest();
    
private Q_SLOTS:
    void testCase1();
    void testCase2();
    void testCase3();
    void testCase4();
    void testCase5();
};

ShiptestTest::ShiptestTest()
{
}

void ShiptestTest::testCase1() //проверка инициализации
{
    bool result=true;
    Ship* sh = new Ship("rwrewr",4); //уровень не соответсвует скорости. Не ошибка. Так и задумано
    if ((sh->GetWord()!="rwrewr") || (sh->GetSpeed()!=2))
        result = false;
    QCOMPARE(result, true);

    //QString str=QString::number(ii);
    //QTextStream cout(stdout);
    //cout<<"Speed="<<sh->GetSpeed()<<"\n";
}

void ShiptestTest::testCase2() //проверка методов SetPosition() GetPosition()
{
    bool result=true;
    Ship* sh = new Ship("new_word",1);
    QPoint pn(100,150);
    sh->SetPosition(pn);
    if ((sh->GetPosition().x()!=100) || (sh->GetPosition().y()!=150))
        result = false;
    QCOMPARE(result, true);
}

void ShiptestTest::testCase3() //проверка методов SetCurrentHP() GetCurrentHP()
{
    bool result=true;
    QString str = "new_word";
    Ship* sh = new Ship(str,1);
    sh->SetCurrentHP(str.size());
    if (sh->GetCurrentHP()!=7)
        result = false;
    QCOMPARE(result, true);
}

void ShiptestTest::testCase4() //проверка метода IsShipOwerlap()
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

void ShiptestTest::testCase5() //проверка методов
{

}

QTEST_APPLESS_MAIN(ShiptestTest)

#include "tst_shiptesttest.moc"
