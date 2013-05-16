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
    void SetWindowStyle();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();

signals:

    void ButtonBackClicked();
private:
    Ui::Baza *ui;
     QString s;
};

#endif // BAZA_H
