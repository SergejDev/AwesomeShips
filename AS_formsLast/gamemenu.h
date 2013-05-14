#ifndef GAMEMENU_H
#define GAMEMENU_H

#include <QMainWindow>
#include <QtDeclarative/QDeclarativeView>
#include <QGraphicsObject>
#include <QtGui>
#include <QDeclarativeContext>
namespace Ui {
class gamemenu;
}

class gamemenu : public QMainWindow
{
    Q_OBJECT

public:
    explicit gamemenu(QMainWindow *parent = 0);
    ~gamemenu();
    QDeclarativeView *ui;
    QObject *Root;//корневой элемент QML модели

 signals:
  void ResumeGameButton_Pressed();
  void BackToMenuButton_Pressed();

public:
   // Ui::gamemenu *ui;
};

#endif // GAMEMENU_H
