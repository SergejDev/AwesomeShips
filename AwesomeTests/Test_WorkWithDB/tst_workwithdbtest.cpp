#include <QtCore/QString>
#include <QtTest/QtTest>
#include "workwithdb.h"


class WorkWithDBTest : public QObject
{
    Q_OBJECT
    
public:
    WorkWithDBTest();
    
private Q_SLOTS:
        void initTestCase();
        void cleanupTestCase();


        void GetCount();
        void GetCount_data();

        void GetTopicID();
        void GetLang();

};

WorkWithDBTest::WorkWithDBTest()
{
}

void WorkWithDBTest::initTestCase()
{
    qDebug()<<"Start testing WorkWithDB class";
}

void WorkWithDBTest::cleanupTestCase()
{
    qDebug()<<"End testing WorkWithDB class";
}

void WorkWithDBTest::GetCount()
{
    WorkWithDB wdb("Words.s3db");

//    QFETCH (int, count);
//    QFETCH (int, res);

    wdb.SetParams();
    QCOMPARE(wdb.GetCount(), 10);

    wdb.SetParams(5);
    QCOMPARE(wdb.GetCount(), 5);
}

void WorkWithDBTest::GetTopicID()
{
    WorkWithDB wdb("Words.s3db");
    wdb.SetParams();
    QCOMPARE(wdb.GetTopicID(), 1);

    wdb.SetParams(0, 3);
    QCOMPARE(wdb.GetTopicID(), 3);
}

void WorkWithDBTest::GetLang()
{
    WorkWithDB wdb("Words.s3db");
    wdb.SetParams();
    QCOMPARE(wdb.GetLang(), 0);

    wdb.SetParams(1,1,5);
    QCOMPARE(wdb.GetLang(), 5);
}

void WorkWithDBTest::GetCount_data()
{
    QTest::addColumn<int> ("count");
    QTest::addColumn<int> ("res");

    QTest::newRow("count_test1") << NULL << 10;
    QTest::newRow("count_test2") << 5 << 5;

}


QTEST_APPLESS_MAIN(WorkWithDBTest)

#include "tst_workwithdbtest.moc"
