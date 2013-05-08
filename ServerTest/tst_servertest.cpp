#include <QtCore/QString>
#include <QtTest/QtTest>
#include <QtCore/QCoreApplication>

#include "Server.h"

class ServerTest : public QObject
{
    Q_OBJECT
    
public:
    QStringList userData;
    int loginID;

private Q_SLOTS:
    void WrongRegister(){
        Server server;
        QTcpSocket *client = new QTcpSocket();
        QVERIFY(server.server->isListening() == true);
        client->connectToHost(QHostAddress("127.0.0.1"), 9485);
        //client->waitForConnected(1000);
        while (!server.userConnected){
            qApp->processEvents();
        }
        QVERIFY(client->state() == QTcpSocket::ConnectedState);

        QDataStream out(client);
        QStringList list;
        list.append("Register");
        list.append("Nikita");
        list.append("WhoCares");
        out << list;
        while (!server.dataReceived){
            qApp->processEvents();
        }
        while (!server.dataSended){
            qApp->processEvents();
        }
        QDataStream in(client);
        in >> userData;

        QVERIFY(userData.length() == 1);
        QVERIFY(userData.at(0) == "User exists");

        client->disconnect();
        client->close();
    }

    void RightRegister(){
        Server server;
        QTcpSocket *client = new QTcpSocket();
        QVERIFY(server.server->isListening() == true);
        client->connectToHost(QHostAddress("127.0.0.1"), 9485);
        //client->waitForConnected(1000);
        while (!server.userConnected){
            qApp->processEvents();
        }
        QVERIFY(client->state() == QTcpSocket::ConnectedState);

        QDataStream out(client);
        QStringList list;
        list.append("Register");
        list.append("NewUser");
        list.append("NewPassword");
        out << list;
        while (!server.dataReceived){
            qApp->processEvents();
        }
        while (!server.dataSended){
            qApp->processEvents();
        }
        QDataStream in(client);
        in >> userData;

        QVERIFY(userData.length() == 1);
        QVERIFY(userData.at(0) == "Registered");

        client->disconnect();
        client->close();
    }

    void LoginNewUser(){
        Server server;
        QTcpSocket *client = new QTcpSocket();
        QVERIFY(server.server->isListening() == true);
        client->connectToHost(QHostAddress("127.0.0.1"), 9485);
        //client->waitForConnected(1000);
        while (!server.userConnected){
            qApp->processEvents();
        }
        QVERIFY(client->state() == QTcpSocket::ConnectedState);

        QDataStream out(client);
        QStringList list;
        list.append("Login");
        list.append("NewUser");
        list.append("NewPassword");
        out << list;
        while (!server.dataReceived){
            qApp->processEvents();
        }
        while (!server.dataSended){
            qApp->processEvents();
        }
        QDataStream in(client);
        in >> userData;

        QVERIFY(userData.length() == 5);
        QVERIFY(userData.at(1) == "NewUser");
        QVERIFY(userData.at(2) == "NewPassword");
        QVERIFY(userData.at(3) == "0");
        QVERIFY(userData.at(4) == "0");

        loginID = userData.at(0).toInt();

        client->disconnect();
        client->close();
    }

    void UpdateNewUser(){
        Server server;
        QTcpSocket *client = new QTcpSocket();
        QVERIFY(server.server->isListening() == true);
        client->connectToHost(QHostAddress("127.0.0.1"), 9485);
        //client->waitForConnected(1000);
        while (!server.userConnected){
            qApp->processEvents();
        }
        QVERIFY(client->state() == QTcpSocket::ConnectedState);

        QDataStream out(client);
        QStringList list;
        list.append("Update");
        list.append(QString::number(loginID));
        list.append(QString::number(1));
        list.append(QString::number(123));
        out << list;
        while (!server.dataReceived){
            qApp->processEvents();
        }
        while (!server.dataSended){
            qApp->processEvents();
        }
        QByteArray a;
        QDataStream in(client);
        in >> a;

        QVERIFY(a.length() > 0);

        client->disconnect();
        client->close();
    }

    void CheckUpdatedData(){
        Server server;
        QTcpSocket *client = new QTcpSocket();
        QVERIFY(server.server->isListening() == true);
        client->connectToHost(QHostAddress("127.0.0.1"), 9485);
        //client->waitForConnected(1000);
        while (!server.userConnected){
            qApp->processEvents();
        }
        QVERIFY(client->state() == QTcpSocket::ConnectedState);

        QDataStream out(client);
        QStringList list;
        list.append("Login");
        list.append("NewUser");
        list.append("NewPassword");
        out << list;
        while (!server.dataReceived){
            qApp->processEvents();
        }
        while (!server.dataSended){
            qApp->processEvents();
        }
        QDataStream in(client);
        in >> userData;

        QVERIFY(userData.length() == 5);
        QVERIFY(userData.at(1) == "NewUser");
        QVERIFY(userData.at(2) == "NewPassword");
        QVERIFY(userData.at(3) == "123");
        QVERIFY(userData.at(4) == "1");

        client->disconnect();
        client->close();
    }

    void WrongLogin(){
        Server server;
        QTcpSocket *client = new QTcpSocket();
        QVERIFY(server.server->isListening() == true);
        client->connectToHost(QHostAddress("127.0.0.1"), 9485);
        //client->waitForConnected(1000);
        while (!server.userConnected){
            qApp->processEvents();
        }
        QVERIFY(client->state() == QTcpSocket::ConnectedState);

        QDataStream out(client);
        QStringList list;
        list.append("Login");
        list.append("NewUser");
        list.append("NotNewPassword");
        out << list;
        while (!server.dataReceived){
            qApp->processEvents();
        }
        while (!server.dataSended){
            qApp->processEvents();
        }
        QDataStream in(client);
        in >> userData;

        QVERIFY(userData.length() == 1);
        QVERIFY(userData.at(0) == "-1");

        client->disconnect();
        client->close();
    }

    void RemoveNewUser(){
        Server server;
        QTcpSocket *client = new QTcpSocket();
        QVERIFY(server.server->isListening() == true);
        client->connectToHost(QHostAddress("127.0.0.1"), 9485);
        //client->waitForConnected(1000);
        while (!server.userConnected){
            qApp->processEvents();
        }
        QVERIFY(client->state() == QTcpSocket::ConnectedState);

        QDataStream out(client);
        QStringList list;
        list.append("RemoveUser");
        list.append("NewUser");
        out << list;
        while (!server.dataReceived){
            qApp->processEvents();
        }
        while (!server.dataSended){
            qApp->processEvents();
        }
        QDataStream in(client);
        in >> userData;

        QVERIFY(userData.length() == 1);
        QVERIFY(userData.at(0) == "Removed");

        client->disconnect();
        client->close();
    }
};

QTEST_MAIN(ServerTest)

#include "tst_servertest.moc"
