#ifndef TABLEDIALOG_H
#define TABLEDIALOG_H

#include <QMainWindow>
#include <QtDeclarative/QDeclarativeView>
#include <QGraphicsObject>
#include <QtGui>
#include <QDeclarativeContext>

namespace Ui {
class TableDialog;
}

class TableDialog : public QMainWindow
{
    Q_OBJECT
private:
    void closeEvent(QCloseEvent *);

public:
    explicit TableDialog(QWidget *parent = 0);
    ~TableDialog();

    QDeclarativeView *ui;
};

#endif // TABLEDIALOG_H
