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

class Baza :public QMainWindow //public QDialog
{
    Q_OBJECT
    
public:
    explicit Baza(QMainWindow *parent = 0);
    ~Baza();
private:
    int topicId;
    void SetWindowStyle();
    QDeclarativeView *ui;
    QObject *Root;//корневой элемент QML модели

private slots:
  void on_pushButton_clicked();
  void on_pushButton_2_clicked();
  void on_pushButton_3_clicked();

signals:
 void ButtonBackClicked();
 Q_INVOKABLE void ButtonBack();
 Q_INVOKABLE void ButtonOpen();
 Q_INVOKABLE void ButtonImport();
private:
  //  Ui::Baza *ui;
     QString s;
};

#endif // BAZA_H
