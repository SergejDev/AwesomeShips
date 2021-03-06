#include "workwithdb.h"
#include "WINDOW.h"
#include "stdlib.h"
#include "menuwindow.h"
#include <QMessageBox>

WorkWithDB::WorkWithDB(QString DBName)//when you create object you need to define the DB name to work with
{
    CreateOpenDB(DBName);
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
    bool opened = true;
    myDB = QSqlDatabase::addDatabase("QSQLITE");
    myDB.setDatabaseName(DBName);

    if (!myDB.open())
    {
        qDebug()<<myDB.lastError().text() + " in CreateNewDB";
        opened = false;
    }
    return opened;
}

void WorkWithDB::ReadTable(QString TableName)
{
    tableModel = new QSqlTableModel();
    tableModel->setTable(TableName);
    tableModel->select();
    tableModel->setEditStrategy(QSqlTableModel::OnRowChange);
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
    {
        if ((tableModel->record(i).value("NikName")==name)&&(tableModel->record(i).value("Password")==pass))
        {
            return i + 1;
        }
    }
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
    QTime time = QTime::currentTime();
    qsrand((uint)pow(static_cast<double>(time.msec()),2));

    int i = 0;
    while( i < Cnt )
    {

        int r = qrand()%cnt;

        if (!strList.contains(strList_tmp.at(r)))
        {
            strList.append(strList_tmp.at(r));
            i++;
        }

        for (int j = 0 ; j < strList.count(); j++)
        {
            for (int p = 0 ; p < strList.count(); p++)
            {
                if (j == p)
                {
                    continue;
                }
                if (strList.at(j).mid(0,1) == strList.at(p).mid(0,1))
                {
                    strList.removeAt(p);
                    i--;
                }
            }
        }
    }

    return strList;
}

void WorkWithDB::InsertDataMultiLanTable()
{
    int rCount = tableModel->rowCount();
    if (!tableModel->insertRow(rCount))
    {
        qDebug()<<tableModel->lastError().text();
    }
}


void WorkWithDB::InsertDataTopicTable()
{
    int rCount = tableModel->rowCount();
    if (!tableModel->insertRow(rCount))
    {
        qDebug()<<tableModel->lastError().text();
    }
}
