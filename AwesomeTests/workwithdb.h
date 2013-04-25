#ifndef WORKWITHDB_H
#define WORKWITHDB_H

#include <QObject>
#include <QDebug>
#include <QString>
#include <QStringList>
#include <iostream>

#include <QtSql>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QTableView>
#include <QSqlTableModel>
#include <QSqlQueryModel>
#include <QtGui/QApplication>


class WorkWithDB: QObject
{
    Q_OBJECT
private:
    int Cnt;//1...n
    int TpcId;//1 2 3
    int LngID;//0 1

public:
    WorkWithDB(QString DBName);
    ~WorkWithDB();

public:
    QSqlDatabase myDB;
    QSqlQuery query;
    QSqlTableModel *tableModel;

    void SetParams(int count = 10, int topic = 1, int lang = 0);
    int GetCount();
    int GetTopicID();
    int GetLang();
    int GetUserID(QString name, QString pass);
    int GetScore(int ID);
    int GetLevel(int ID);
    ///////////////////////////////////
    bool CreateOpenDB(QString DBName);//+
    void InsertDataTopicTable();
    void InsertDataMultiLanTable();
    ///////////////////////////////////

    void ReadTable(QString TableName);
    QSqlQueryModel *ReadConnectedTables(QStringList TablesNames);

    QStringList GetWords(/*int Count, int TopicId, int LangID*/);//database name - default='Words'
};

#endif // WORKWITHDB_H
