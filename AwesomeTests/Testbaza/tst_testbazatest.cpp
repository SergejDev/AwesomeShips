#include <QtCore/QString>
#include <QtTest/QtTest>

class TestbazaTest : public QObject
{
    Q_OBJECT
    
public:
    TestbazaTest();
    
private Q_SLOTS:
    void testCase1();
};

TestbazaTest::TestbazaTest()
{
}

void TestbazaTest::testCase1()
{
    QVERIFY2(true, "Failure");
}

QTEST_APPLESS_MAIN(TestbazaTest)

#include "tst_testbazatest.moc"
