#include "server.h"
#include "user.h"
#include <iostream>
#include <QMessageBox>
#include <QString>
#include <QHash>
#include <QTcpServer>
#include <QTcpSocket>
#include "QtSql"

using namespace std;

Server::Server(QObject* parent): QObject(parent)
{
    db=QSqlDatabase::addDatabase("QSQLITE");
    db.setUserName("user");
    db.setDatabaseName("Users.s3db");
    //db.setHostName("server");
    db.setPassword("");
    if (!db.open())
    {
        cout << "Failed to open db. Check it. You wouldn't be able to play!" << endl;
    }
    connect(&server, SIGNAL(newConnection()), this, SLOT(acceptConnection()));
    server.listen(QHostAddress::Any, 9485);
}

Server::~Server()
{
    server.close();
}

void Server::acceptConnection()
{
    client = server.nextPendingConnection();
    cout << "Connection is open" << endl;
    cout << client->peerAddress().toString().toStdString() << endl;
    connect(client, SIGNAL(readyRead()), this, SLOT(startRead()));
    connect(client, SIGNAL(disconnected()), this, SLOT(stopConnection()));
}

void Server::startRead()
{
    QDataStream in(client);
    in.setVersion(QDataStream::Qt_4_0);

    QStringList listIn;
    in >> listIn;

    QSqlQuery query;

    QStringList list;
    QString id = "-2";
    if (listIn.at(0).toStdString() == "Register")
    {
        cout << "Registering." << endl;
        query.exec("SELECT ID,NikName,Password,Level,Scores FROM Users");
        while (query.next())
        {
            if (query.record().value(1).toString().toStdString() == listIn.at(1).toStdString())//username check
            {
                list.append(query.record().value(0).toString());
                in << list;
                return;
            }
        }
        QSqlQuery query2;
        QString nam=listIn.at(1);
        QString pas=listIn.at(2);
        query2.exec("INSERT INTO Users(NikName,Password,Level,Scores) VALUES ('"+nam+"','"+pas +"',0,0)");
        list.append(id);
        in << list;
    }
    else if (listIn.at(0).toStdString() == "Login")
    {
        cout << "Asking for login." << endl;

        query.exec("SELECT ID,NikName,Password,Level,Scores FROM Users");

        while (query.next())
        {
            if ((query.record().value(1).toString().toStdString() == listIn.at(1).toStdString())//username check
                &&(query.record().value(2).toString().toStdString() == listIn.at(2).toStdString()))//pass check
                {
                    QSqlRecord record = query.record();
                    id = record.value(0).toString();
                    cout << "Sending info " << endl;
                    cout << "   ID     : " << record.value(0).toString().toStdString() << endl;
                    cout << "   Level  : " << record.value(3).toString().toStdString() << endl;
                    cout << "   Score  : " << record.value(4).toString().toStdString() << endl << endl;
                    for (int i = 0 ; i < 5; i++)
                    {
                        list.append(record.value(i).toString());
                    }
                    in << list;
                    return;
                }
        }
        id = "-1";
        list.append(id);
        in << list;
    }
    else if (listIn.at(0).toStdString() == "Update")
    {
        cout << "Updating data " << endl;
        cout << "   UserID : " << listIn.at(1).toStdString() << endl;
        cout << "   Level  : " << listIn.at(3).toStdString() << endl;
        cout << "   Scores : " << listIn.at(2).toStdString() << endl;
        query.exec("Update Users Set Level="+listIn.at(3)+", Scores="+listIn.at(2)+" Where ID="+listIn.at(1));

        query.exec("Select NikName,Level,Scores From Users ORDER BY Scores DESC");

        /*QStringList list;*/
        QByteArray source;

        while(query.next())
        {
            for (int i = 0; i < query.record().count(); i++)
            {
                source.append(query.record().value(i).toByteArray());
                source.append(',');
            }
            source.remove(source.size()-1,1);
            source.append(':');
        }
        source.remove(source.size()-1,1);
        in << source;
    }
}

void Server::stopConnection()//Nikita fix this!!!!!!!!!!
{
    cout << "Connection is close" << endl;
}
