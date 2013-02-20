#include "workwithdb.h"
#include "WINDOW.h"
#include "stdlib.h"
#include "menuwindow.h"
#include <QMessageBox>

WorkWithDB::WorkWithDB(QString DBName)//when you create object you need to define the DB name to work with
{
    bool create_open = CreateOpenDB(DBName);
    if (!create_open)
    {
        qDebug()<< myDB.lastError().text() + "DB didn't created";
    }
    else
    {
        qDebug()<< "DB created";
    }
}

WorkWithDB::~WorkWithDB()
{
    myDB.close();
}

void WorkWithDB::SetParams(int count, int topic, int lang)
{
    Cnt = count;
    TpcId = topic;
    LngID = lang;
}

int WorkWithDB::GetCount()
{
    return Cnt;
}

int WorkWithDB::GetTopicID()
{
    return TpcId;
}

int WorkWithDB::GetLang()
{
    return LngID;
}

bool WorkWithDB::CreateOpenDB(QString DBName)
{
    bool opened = false;
    myDB = QSqlDatabase::addDatabase("QSQLITE");
    myDB.setDatabaseName(DBName);

    if (!myDB.open())
    {
        qDebug()<<myDB.lastError().text() + " in CreateNewDB";
        opened = false;
    }
    else
    {
        //        if ()//check for existing tables
        //        {

        //            try{
        QString qStr = "CREATE TABLE Topics (TopicID integer PRIMARY KEY, topicName text)";
        query.exec(qStr);
        qStr = "CREATE TABLE MultiLanguage (wordID integer PRIMARY KEY, TopicID integer, russian text, english text)";
        query.exec(qStr);
        qStr = "CREATE TABLE Statistic (statID integer PRIMARY KEY, userName text, score integer, levels integer)";
        query.exec(qStr);
        //            }
        //            catch ()
        //            {
        //            qDebug()<<myDB.lastError().text() + "Can't create tables";
        //    }
    }
    opened = true;
    //    }

    return opened;
}

void WorkWithDB::ReadTable(QString TableName)
{
    tableModel = new QSqlTableModel();
    tableModel->setTable(TableName);
    tableModel->select();
    tableModel->setEditStrategy(QSqlTableModel::OnRowChange);

    //return model;
}

QSqlQueryModel* WorkWithDB::ReadConnectedTables(QStringList TablesNames)//1st table - multilan, 2nd - topics
{
    QSqlQueryModel* q_model = new QSqlQueryModel();
    q_model->setQuery("SELECT t.topicName, m.Russian, m.English FROM "+TablesNames[0]+" m inner join "+TablesNames[1]+" t on m.topicID  = t.topicID order by t.topicName");
    //q_model->setQuery("select * from Topics");
    return q_model;
}

int WorkWithDB::GetUserID(QString name, QString pass)
{
    ReadTable("Users");
    for (int i = 0 ; i < tableModel->rowCount(); i++)
        if (tableModel->record(i).value("NikName")==name)
            if (tableModel->record(i).value("Password")==pass)
                return i + 1;
    return -1;
}

int WorkWithDB::GetScore(int ID)
{
    ReadTable("Statistic");
    for (int i = 0 ; i < tableModel->rowCount(); i++)
        if (tableModel->record(i).value("ID")==ID)
           return tableModel->record(i).value("Scores").toInt();
    return 0;
}

int WorkWithDB::GetLevel(int ID)
{
    ReadTable("Users");
    for (int i = 0 ; i < tableModel->rowCount(); i++)
        if (tableModel->record(i).value("ID")==ID)
           return tableModel->record(i).value("Level").toInt();
    return 1;
}

QStringList WorkWithDB::GetWords()
{
    QStringList strList;
    QStringList strList_tmp;
    QString language;
    QString topic;

    ReadTable("MultiLanguage");
    if (LngID == 0) language = "Russian";
    if (LngID == 1) language = "English";

    tableModel->setFilter("topicID = "+topic.setNum(TpcId));
    for (int k = 0; k < tableModel->rowCount(); k++)
    {
        strList_tmp.append(tableModel->record(k).value(language).toString());
    }

    int cnt = strList_tmp.count();
    srand(cnt);

    int i = 0;
    while( i < Cnt )
    {

        int r = rand()%cnt;

        if (!strList.contains(strList_tmp.at(r)))
        {
            strList.append(strList_tmp.at(r));
            i++;
        }

        for (int j = 0 ; j < strList.count(); j++)
        {
            for (int p = 0 ; p < strList.count(); p++)
            {
                if (j == p) continue;
                if (strList.at(j).mid(0,1) == strList.at(p).mid(0,1))
                {
                    strList.removeAt(p);
                    i--;
                }
            }
        }
    }

    strList.sort();

    return strList;
}

void WorkWithDB::InsertDataMultiLanTable()
{
    int rCount = tableModel->rowCount();
    if (!tableModel->insertRow(rCount))
        qDebug()<<tableModel->lastError().text();
}


void WorkWithDB::InsertDataTopicTable()
{
    int rCount = tableModel->rowCount();
    if (!tableModel->insertRow(rCount))
        qDebug()<<tableModel->lastError().text();
}
