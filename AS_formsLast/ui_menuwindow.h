/********************************************************************************
** Form generated from reading UI file 'menuwindow.ui'
**
** Created: Fri 26. Apr 12:50:20 2013
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MENUWINDOW_H
#define UI_MENUWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_MenuWindow
{
public:
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer_3;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_7;
    QLabel *label;
    QSpacerItem *horizontalSpacer_8;
    QSpacerItem *verticalSpacer_4;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_2;
    QLineEdit *serverAddressEdit;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_9;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_3;
    QSpacerItem *horizontalSpacer_11;
    QLabel *label_4;
    QHBoxLayout *horizontalLayout_5;
    QLineEdit *Username;
    QSpacerItem *horizontalSpacer_9;
    QLineEdit *Password;
    QHBoxLayout *horizontalLayout_7;
    QSpacerItem *horizontalSpacer_10;
    QPushButton *RegisterButton;
    QSpacerItem *horizontalSpacer_12;
    QHBoxLayout *horizontalLayout_8;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer;
    QPushButton *startPushButton;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *settingsPushButton;
    QSpacerItem *horizontalSpacer_4;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *quitPushButton;
    QSpacerItem *horizontalSpacer_6;
    QSpacerItem *verticalSpacer_2;

    void setupUi(QDialog *MenuWindow)
    {
        if (MenuWindow->objectName().isEmpty())
            MenuWindow->setObjectName(QString::fromUtf8("MenuWindow"));
        MenuWindow->resize(187, 358);
        verticalLayout = new QVBoxLayout(MenuWindow);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_7);

        label = new QLabel(MenuWindow);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_4->addWidget(label);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_8);


        verticalLayout->addLayout(horizontalLayout_4);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_4);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(0, -1, -1, 0);
        label_2 = new QLabel(MenuWindow);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_6->addWidget(label_2);

        serverAddressEdit = new QLineEdit(MenuWindow);
        serverAddressEdit->setObjectName(QString::fromUtf8("serverAddressEdit"));

        horizontalLayout_6->addWidget(serverAddressEdit);


        verticalLayout->addLayout(horizontalLayout_6);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));

        verticalLayout->addLayout(horizontalLayout_9);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        label_3 = new QLabel(MenuWindow);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_10->addWidget(label_3);

        horizontalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_11);

        label_4 = new QLabel(MenuWindow);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_10->addWidget(label_4);


        verticalLayout->addLayout(horizontalLayout_10);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(-1, -1, -1, 0);
        Username = new QLineEdit(MenuWindow);
        Username->setObjectName(QString::fromUtf8("Username"));

        horizontalLayout_5->addWidget(Username);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_9);

        Password = new QLineEdit(MenuWindow);
        Password->setObjectName(QString::fromUtf8("Password"));
        Password->setEchoMode(QLineEdit::Password);

        horizontalLayout_5->addWidget(Password);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_10);

        RegisterButton = new QPushButton(MenuWindow);
        RegisterButton->setObjectName(QString::fromUtf8("RegisterButton"));

        horizontalLayout_7->addWidget(RegisterButton);

        horizontalSpacer_12 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_12);


        verticalLayout->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));

        verticalLayout->addLayout(horizontalLayout_8);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        startPushButton = new QPushButton(MenuWindow);
        startPushButton->setObjectName(QString::fromUtf8("startPushButton"));

        horizontalLayout_3->addWidget(startPushButton);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        settingsPushButton = new QPushButton(MenuWindow);
        settingsPushButton->setObjectName(QString::fromUtf8("settingsPushButton"));
        settingsPushButton->setMinimumSize(QSize(62, 0));

        horizontalLayout_2->addWidget(settingsPushButton);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_5);

        quitPushButton = new QPushButton(MenuWindow);
        quitPushButton->setObjectName(QString::fromUtf8("quitPushButton"));

        horizontalLayout->addWidget(quitPushButton);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_6);


        verticalLayout->addLayout(horizontalLayout);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

#ifndef QT_NO_SHORTCUT
        label_2->setBuddy(serverAddressEdit);
        label_3->setBuddy(Username);
        label_4->setBuddy(Password);
#endif // QT_NO_SHORTCUT
        QWidget::setTabOrder(Username, Password);
        QWidget::setTabOrder(Password, RegisterButton);
        QWidget::setTabOrder(RegisterButton, startPushButton);
        QWidget::setTabOrder(startPushButton, settingsPushButton);
        QWidget::setTabOrder(settingsPushButton, quitPushButton);
        QWidget::setTabOrder(quitPushButton, serverAddressEdit);

        retranslateUi(MenuWindow);

        QMetaObject::connectSlotsByName(MenuWindow);
    } // setupUi

    void retranslateUi(QDialog *MenuWindow)
    {
        MenuWindow->setWindowTitle(QApplication::translate("MenuWindow", "Awesome ships", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MenuWindow", "Awesome ships", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MenuWindow", "IP :", 0, QApplication::UnicodeUTF8));
        serverAddressEdit->setInputMask(QString());
        serverAddressEdit->setText(QApplication::translate("MenuWindow", "127.0.0.1", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MenuWindow", "Name:", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("MenuWindow", "Password:", 0, QApplication::UnicodeUTF8));
        RegisterButton->setText(QApplication::translate("MenuWindow", "Register", 0, QApplication::UnicodeUTF8));
        startPushButton->setText(QApplication::translate("MenuWindow", "Start", 0, QApplication::UnicodeUTF8));
        settingsPushButton->setText(QApplication::translate("MenuWindow", "Settings", 0, QApplication::UnicodeUTF8));
        quitPushButton->setText(QApplication::translate("MenuWindow", "Quit", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MenuWindow: public Ui_MenuWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MENUWINDOW_H
