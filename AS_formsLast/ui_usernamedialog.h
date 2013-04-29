/********************************************************************************
** Form generated from reading UI file 'usernamedialog.ui'
**
** Created: Mon 4. Mar 22:24:40 2013
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERNAMEDIALOG_H
#define UI_USERNAMEDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_UserNameDialog
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *okPushButton;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QDialog *UserNameDialog)
    {
        if (UserNameDialog->objectName().isEmpty())
            UserNameDialog->setObjectName(QString::fromUtf8("UserNameDialog"));
        UserNameDialog->resize(210, 74);
        UserNameDialog->setStyleSheet(QString::fromUtf8("Style.txt"));
        verticalLayout = new QVBoxLayout(UserNameDialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(UserNameDialog);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setFamily(QString::fromUtf8("Segoe Print"));
        font.setPointSize(20);
        label->setFont(font);
        label->setTextFormat(Qt::RichText);
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        okPushButton = new QPushButton(UserNameDialog);
        okPushButton->setObjectName(QString::fromUtf8("okPushButton"));
        okPushButton->setStyleSheet(QString::fromUtf8("Style.txt"));

        horizontalLayout->addWidget(okPushButton);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(UserNameDialog);
        QObject::connect(okPushButton, SIGNAL(clicked()), UserNameDialog, SLOT(accept()));

        QMetaObject::connectSlotsByName(UserNameDialog);
    } // setupUi

    void retranslateUi(QDialog *UserNameDialog)
    {
        UserNameDialog->setWindowTitle(QApplication::translate("UserNameDialog", "Game over", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("UserNameDialog", "Game over", 0, QApplication::UnicodeUTF8));
        okPushButton->setText(QApplication::translate("UserNameDialog", "    Ok    ", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class UserNameDialog: public Ui_UserNameDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERNAMEDIALOG_H
