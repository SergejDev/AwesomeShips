#ifndef BAZA_H
#define BAZA_H

#include <QDialog>

namespace Ui {
class Baza;
}

class Baza : public QDialog
{
    Q_OBJECT
    
public:
    explicit Baza(QWidget *parent = 0);
    ~Baza();
    
private:
    Ui::Baza *ui;
};

#endif // BAZA_H
