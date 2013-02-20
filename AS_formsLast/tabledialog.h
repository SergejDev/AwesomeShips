#ifndef TABLEDIALOG_H
#define TABLEDIALOG_H

#include <QDialog>

namespace Ui {
class TableDialog;
}

class TableDialog : public QDialog
{
    Q_OBJECT
private:
    void closeEvent(QCloseEvent *);
public:
    explicit TableDialog(QWidget *parent = 0);
    ~TableDialog();
    
    Ui::TableDialog *ui;
};

#endif // TABLEDIALOG_H
