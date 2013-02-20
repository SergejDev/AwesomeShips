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
    db.setHostName("server");
    db.setPassword("");
    if (!db.open())
        cout << "Failed to open db. Check it. You wouldn't be able to play!" << endl;
//cout<< db.tables().count() <<endl;
    connect(&server, SIGNAL(newConnection()),
    this, SLOT(acceptConnection()));
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

    if (listIn.at(0).toStdString() != "INSERT DAMN DATA OF USER WHO ENDED THE GAME")
    {
        cout << "IT IS NOT INSERT CMD!!!" << endl << endl;
        QStringList list;
        QString id = "-1";

        query.exec("SELECT ID,NikName,Password,Level,Scores FROM Users");

        while (query.next())
            if (query.record().value(1).toString().toStdString() == listIn.at(0).toStdString())
                if (query.record().value(2).toString().toStdString() == listIn.at(1).toStdString())
                {
                    QSqlRecord record = query.record();
                    id = record.value(0).toString();
                    cout << "Sending info " << endl;
                    cout << "   ID     : " << record.value(0).toString().toStdString() << endl;
                    cout << "   Level  : " << record.value(3).toString().toStdString() << endl;
                    cout << "   Score  : " << record.value(4).toString().toStdString() << endl << endl;
                    for (int i = 0 ; i < 5; i++)
                        list.append(record.value(i).toString());
                    in << list;
                    break;
                }

        if (id == "-1")
        {
            QSqlQuery query2;
            QString nam=listIn.at(0);
            QString pas=listIn.at(1);
            query2.exec("INSERT INTO Users(NikName,Password,Level,Scores) VALUES ('"+nam+"','"+pas +"',1,0)");
            list.append(id);
            in << list;
        }
    }
    else
    {
        cout << "Updating data " << endl;
        cout << "   UserID : " << listIn.at(1).toStdString() << endl;
        cout << "   Level  : " << listIn.at(3).toStdString() << endl;
        cout << "   Scores : " << listIn.at(2).toStdString() << endl;
        query.exec("Update Users Set Level="+listIn.at(3)+", Scores="+listIn.at(2)+" Where ID="+listIn.at(1));

        query.exec("Select ID,NikName,Password,Level,Scores From Users");

        /*QStringList list;*/
        QByteArray source;

        query.next();
        for (int i = 0 ; i < query.record().count(); i++)
        {
            for (int i = 0; i < 5; i++)
            {
                source.append(query.record().value(i).toByteArray());
                source.append(',');
            }
            source.append(':');
            query.next();
        }
        in << source;
    }
}

void Server::stopConnection()
{
    cout << "Connection is close" << endl;
}
