#include <QtCore/QString>
#include <QtTest/QtTest>
#include <QString>

#include "workwithdb.h"


class WorkWithDBTest : public QObject
{
    Q_OBJECT
    
public:
    WorkWithDBTest();
    
private Q_SLOTS:
        void initTestCase();
        void cleanupTestCase();


        void GetCount_Default();
        void GetCount();
        void GetCount_data();

        void GetTopicID();
        void GetTopicID_Default();
        void GetTopicID_data();

        void GetLang();
        void GetLang_Default();
        void GetLang_data();

        void GetLevel();
        void GetLevel_data();

        void GetScore();
        void GetScore_data();

        void CreateOpenDB();
        void CreateOpenDB_data();
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

void WorkWithDBTest::GetCount_Default()
{
    WorkWithDB wdb("Words.s3db");
    wdb.SetParams();
    QCOMPARE(wdb.GetCount(), 10);
}

void WorkWithDBTest::GetCount()
{
    WorkWithDB wdb("Words.s3db");

    QFETCH (int, count);
    QFETCH (int, res);

    wdb.SetParams(count);
    QCOMPARE(wdb.GetCount(), res);
}

void WorkWithDBTest::GetCount_data()
{
    QTest::addColumn<int> ("count");
    QTest::addColumn<int> ("res");

    QTest::newRow("count_test1") << 0 << 0;
    QTest::newRow("count_test2") << 5 << 5;
    QTest::newRow("count_test2") << 7 << 7;
}

void WorkWithDBTest::GetTopicID()
{
    WorkWithDB wdb("Words.s3db");

    QFETCH (int, topicID);
    QFETCH (int, res);

    wdb.SetParams(topicID);
    QCOMPARE(wdb.GetTopicID(0, topicID), res);
}

void WorkWithDBTest::GetTopicID_Default()
{
    WorkWithDB wdb("Words.s3db");
    wdb.SetParams();
    QCOMPARE(wdb.GetTopicID(), 1);
}

void WorkWithDBTest::GetTopicID_data()
{
    QTest::addColumn<int> ("topicID");
    QTest::addColumn<int> ("res");

    QTest::newRow("topicID_test1") << 10 << 10;
    QTest::newRow("topicID_test2") << 15 << 15;
    QTest::newRow("topicID_test2") << 7 << 7;
}

void WorkWithDBTest::GetLang()
{
    WorkWithDB wdb("Words.s3db");

    QFETCH(int, lang);
    QFETCH(int, res);

    wdb.SetParams(1,1, lang);
    QCOMPARE(wdb.GetLang(), res);
}

void WorkWithDBTest::GetLang_Default()
{
    WorkWithDB wdb("Words.s3db");
    wdb.SetParams();
    QCOMPARE(wdb.GetLang(), 0);
}

void WorkWithDBTest::GetLang_data()
{
    QTest::addColumn<int> ("lang");
    QTest::addColumn<int> ("res");

    QTest::newRow("lang_test1") << 13 << 13;
    QTest::newRow("lang_test2") << 20 << 20;
    QTest::newRow("lang_test2") << 9 << 9;
}


void WorkWithDBTest::GetLevel()
{
    WorkWithDB wdb("Users.s3db");
    QCOMPARE(wdb.GetLevel(63), 5);
}

void WorkWithDBTest::GetScore()
{
    WorkWithDB wdb("Users.s3db");
    QCOMPARE(wdb.GetScore(63), 1290);
}

void WorkWithDBTest::CreateOpenDB()
{
    WorkWithDB wdb;
    QFETCH(QString, dbName);
    QFETCH(bool, result);

    QCOMPARE(wdb.CreateOpenDB(dbName), result);
}



void WorkWithDBTest::CreateOpenDB_data()
{
    QTest::addColumn<QString>("dbName");
    QTest::addColumn<bool>("result");

    QTest::newRow("CreateOpenDB_test1") << "Words.s3db" << true;
    QTest::newRow("CreateOpenDB_test2") << "Users.s3db" << true;
    QTest::newRow("CreateOpenDB_test3") << "W.s3db" << false;
}




QTEST_APPLESS_MAIN(WorkWithDBTest)

#include "tst_workwithdbtest.moc"
