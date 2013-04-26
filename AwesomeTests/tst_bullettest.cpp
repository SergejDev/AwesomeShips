#include <QtCore/QString>
#include <QtTest/QtTest>
#include <QtCore/QCoreApplication>

#include "workwithdb.h"

#include "tst_workwithdbtest.h"
//class BulletTest : public QObject
//{
//    Q_OBJECT

//public:
//    BulletTest();

//private Q_SLOTS:
//    void initTestCase();
//    void cleanupTestCase();
//    void testCase1();
//    void testCase1_data();
//};


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


//void WorkWithDBTest::SetParamsTest_data()
//{
//    QTest::addColumn<int>("count");
//    QTest::addColumn<int>("topic");
//    QTest::addColumn<int>("lang");
//    QTest::addColumn<int>("result");

//    QTest::newRow("SetParams_test1") << 0 << 3 << 2 << 0;
//    QTest::newRow("SetParams_test1") << 1;
//   // QTest::newRow("SetParams_test1") << "0" << "3" << "2";
//}

//void WorkWithDBTest::SetParamsTest()
//{
////    WorkWithDB wdb("Words.s3db");
////    QFETCH(int, count);
////    QFETCH(int, topic);
////    QFETCH(int, lang);
////    QFETCH(int, result);

////    QCOMPARE(wdb.SetParams(count, topic, lang), result);
//}

//void WorkWithDBTest::GetCount()
//{
//    WorkWithDB wdb("Words.s3db");
//    wdb.SetParams(10);
//    QCOMPARE(wdb.GetCount(), 10);
//}

//void WorkWithDBTest::GetCount_data()
//{
//   // QTest::addColumn("");
//}


//void WorkWithDBTest::initTestCase()
//{
//    qDebug("called before everything else");
//}

//void WorkWithDBTest::cleanupTestCase()
//{
//    qDebug("testing ended");
//}

//QTEST_APPLESS_MAIN(WorkWithDBTest)
////QTEST_APPLESS_MAIN(WorkWithDBTest)

//#include "tst_bullettest.moc"
////#include "tst_workwithdb.moc"
