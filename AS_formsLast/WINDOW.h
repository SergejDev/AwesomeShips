#ifndef WINDOW_H
#define WINDOW_H

#include <QtGui/QApplication>
#include <QtGui/QPushButton>
#include <QtGui/QComboBox>
#include <QtGui/QLabel>
#include <QtGui/QListView>
#include <QtGui/QWidget>
#include <QtGui/QLabel>
//#include "workwithdb.h"

class ToolsWindow:public QWidget
{
    Q_OBJECT

public:
    explicit ToolsWindow(QWidget *parent = 0);
    ~ToolsWindow();
    int GetTopicID();
    int GetLanguageID();

private:

    int topicID;
    int languageID;

    QPushButton *button_toMainMenu;
    QPushButton *button_Save;

    QLabel *label_Lang;
    //QLabel *label_Color;
    QLabel *label_Topic;
    QLabel *label_main;
    //QLabel *label_tmp;

    QComboBox *Combo_Lang;
    //QComboBox *Combo_Color;
    QComboBox *Combo_Topic;

    // void GetWordsFromDB();

    void setupToolsWindow(QWidget *ToolsWindow);
private slots:
    void on_button_Save_clicked();
    void ButtonBackClickedSlot();
signals:
    void ButtonSaveClicked();
    void ButtonBackClicked();
};



#endif // WINDOW_H
