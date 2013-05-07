#ifndef WINDOW_H
#define WINDOW_H

#include <QtGui>
#include <QtGui/QApplication>
#include <QtGui/QPushButton>
#include <QtGui/QComboBox>
#include <QtGui/QLabel>
#include <QtGui/QListView>
#include <QtGui/QWidget>
#include <QtGui/QLabel>
#include <QtDeclarative/QDeclarativeView>
#include <QtDeclarative/QDeclarativeContext>
#include <QMainWindow>
#include <QDebug>

class ToolsWindow:public QMainWindow//QWidget
{
    Q_OBJECT

public:
    explicit ToolsWindow(QMainWindow *parent = 0);
    ~ToolsWindow();
    int GetTopicID();
    int GetLanguageID();

private:
    QDeclarativeView *ui;
    QObject *Root;//корневой элемент QML модели

    int topicID;
    int languageID;

    QPushButton *button_toMainMenu;
    QPushButton *button_Save;
    QPushButton *button_baza;

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
public slots:
    Q_INVOKABLE void on_button_Save_clicked();
    Q_INVOKABLE void ButtonBackClickedSlot();
    Q_INVOKABLE void button_baza_clicked();
signals:
    void ButtonSaveClicked();
    void ButtonBackClicked();
    void ButtonBazaClicked();
};



#endif // WINDOW_H
