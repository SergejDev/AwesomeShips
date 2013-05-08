#ifndef SERVER_H
#define SERVER_H

#include <QtNetwork>
#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QString>
#include <QSqlDatabase>

class Server: public QObject
{
Q_OBJECT
public:
  Server(QObject * parent = 0);
  ~Server();
  QSqlDatabase db;
  QTcpServer *server;
  bool readyForConnectings;
  bool userConnected;
  bool dataReceived;
  bool dataSended;

public slots:
  void acceptConnection();
  void startRead();

private:
  QTcpSocket *client;
};
#endif // SERVER_H
