/********************************************************************************
** Form generated from reading UI file 'baza.ui'
**
** Created: Mon 4. Mar 22:24:40 2013
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BAZA_H
#define UI_BAZA_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Baza
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QComboBox *comboBox;
    QPushButton *pushButton_3;
    QLineEdit *textEdit;

    void setupUi(QDialog *Baza)
    {
        if (Baza->objectName().isEmpty())
            Baza->setObjectName(QString::fromUtf8("Baza"));
        Baza->resize(386, 249);
        pushButton = new QPushButton(Baza);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(30, 190, 121, 41));
        pushButton_2 = new QPushButton(Baza);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(30, 30, 101, 41));
        comboBox = new QComboBox(Baza);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(230, 30, 121, 41));
        pushButton_3 = new QPushButton(Baza);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(230, 190, 121, 41));
        textEdit = new QLineEdit(Baza);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(30, 100, 251, 31));

        retranslateUi(Baza);

        QMetaObject::connectSlotsByName(Baza);
    } // setupUi

    void retranslateUi(QDialog *Baza)
    {
        Baza->setWindowTitle(QApplication::translate("Baza", "Dialog", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("Baza", "Back to menu", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("Baza", "Open", 0, QApplication::UnicodeUTF8));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("Baza", "Food", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Baza", "Weather", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Baza", "Animals", 0, QApplication::UnicodeUTF8)
        );
        pushButton_3->setText(QApplication::translate("Baza", "Import", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Baza: public Ui_Baza {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BAZA_H
