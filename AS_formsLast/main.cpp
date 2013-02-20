#include <QtGui/QApplication>
#include "windowscontroller.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //GameWindow w;
    //w.show();

    WindowsController wc;
    //wc.wordGetter=new WorkWithDB("Words.s3db");
    wc.ShowMenuWindow();
    
    return a.exec();
}
