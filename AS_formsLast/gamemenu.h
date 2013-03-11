#ifndef GAMEMENU_H
#define GAMEMENU_H

#include <QDialog>
#include "gamecontroller.h"

namespace Ui {
class gamemenu;
}

class gamemenu : public QDialog
{
    Q_OBJECT

public:
    explicit gamemenu(QWidget *parent = 0);
    ~gamemenu();
 signals:
    void ResumeGameButton_Pressed();
    void BackToMenuButton_Pressed();


public:
    Ui::gamemenu *ui;
};

#endif // GAMEMENU_H
