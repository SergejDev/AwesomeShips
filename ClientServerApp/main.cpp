#include "server.h"
#include <QApplication>
#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
  QApplication app(argc, argv);
  Server server;
  cout << "port 9485" << endl;
  cout << "waiting please..." << endl;
  return app.exec();
}
