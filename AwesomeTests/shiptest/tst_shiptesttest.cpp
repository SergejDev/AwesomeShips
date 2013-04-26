#include <QString>
#include <QtTest>

class ShiptestTest : public QObject
{
    Q_OBJECT
    
public:
    ShiptestTest();
    
private Q_SLOTS:
    void testCase1();
};

ShiptestTest::ShiptestTest()
{
}

void ShiptestTest::testCase1()
{
    QVERIFY2(true, "Failure");
}

QTEST_APPLESS_MAIN(ShiptestTest)

#include "tst_shiptesttest.moc"
