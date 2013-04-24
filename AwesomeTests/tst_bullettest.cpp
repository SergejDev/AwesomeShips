#include <QtCore/QString>
#include <QtTest/QtTest>
#include <QtCore/QCoreApplication>

class BulletTest : public QObject
{
    Q_OBJECT
    
public:
    BulletTest();
    
private Q_SLOTS:
    void initTestCase();
    void cleanupTestCase();
    void testCase1();
    void testCase1_data();
};

BulletTest::BulletTest()
{
}

void BulletTest::initTestCase()
{
}

void BulletTest::cleanupTestCase()
{
}

void BulletTest::testCase1()
{
    QFETCH(QString, data);
    QVERIFY2(true, "Failure");
}

void BulletTest::testCase1_data()
{
    QTest::addColumn<QString>("data");
    QTest::newRow("0") << QString();
}

QTEST_MAIN(BulletTest)

#include "tst_bullettest.moc"
