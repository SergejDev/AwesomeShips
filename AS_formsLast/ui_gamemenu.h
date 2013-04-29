/********************************************************************************
** Form generated from reading UI file 'gamemenu.ui'
**
** Created: Fri 26. Apr 12:50:20 2013
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAMEMENU_H
#define UI_GAMEMENU_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_gamemenu
{
public:
    QPushButton *ResumeGame_pushButton;
    QPushButton *BackToMenu_pushButton;

    void setupUi(QDialog *gamemenu)
    {
        if (gamemenu->objectName().isEmpty())
            gamemenu->setObjectName(QString::fromUtf8("gamemenu"));
        gamemenu->resize(243, 200);
        ResumeGame_pushButton = new QPushButton(gamemenu);
        ResumeGame_pushButton->setObjectName(QString::fromUtf8("ResumeGame_pushButton"));
        ResumeGame_pushButton->setGeometry(QRect(40, 30, 161, 51));
        BackToMenu_pushButton = new QPushButton(gamemenu);
        BackToMenu_pushButton->setObjectName(QString::fromUtf8("BackToMenu_pushButton"));
        BackToMenu_pushButton->setGeometry(QRect(40, 110, 161, 51));

        retranslateUi(gamemenu);

        QMetaObject::connectSlotsByName(gamemenu);
    } // setupUi

    void retranslateUi(QDialog *gamemenu)
    {
        gamemenu->setWindowTitle(QApplication::translate("gamemenu", "Menu", 0, QApplication::UnicodeUTF8));
        ResumeGame_pushButton->setText(QApplication::translate("gamemenu", "Resume Game", 0, QApplication::UnicodeUTF8));
        BackToMenu_pushButton->setText(QApplication::translate("gamemenu", "Back to Main Menu", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class gamemenu: public Ui_gamemenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMEMENU_H
