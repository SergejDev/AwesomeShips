#ifndef BAZA_H
#define BAZA_H

#include <QDialog>
#include <QMainWindow>
#include <QtDeclarative/QDeclarativeView>
#include <QGraphicsObject>
#include <QtGui>
#include <QDeclarativeContext>

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
    QDeclarativeView *ui;
    QObject *Root;//корневой элемент QML модели

private slots:
  Q_INVOKABLE  void on_pushButton_clicked();
    Q_INVOKABLE  void on_pushButton_2_clicked();
   Q_INVOKABLE   void on_pushButton_3_clicked();

signals:

    void ButtonBackClicked();
private:
  //  Ui::Baza *ui;
     QString s;
};

#endif // BAZA_H
