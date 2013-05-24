#ifndef WINDOW_H
#define WINDOW_H

#include <QtGui>
#include <QtGui/QApplication>
#include <QtGui/QWidget>
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

    // void GetWordsFromDB();

    void setupToolsWindow(QWidget *ToolsWindow);
public slots:
    Q_INVOKABLE void on_button_Save_clicked();

    Q_INVOKABLE void button_baza_clicked();
signals:
    void ButtonSaveClicked();
    Q_INVOKABLE void ButtonBackClicked();
    void ButtonBazaClicked();
};



#endif // WINDOW_H
