/********************************************************************************
** Form generated from reading UI file 'newaccount.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWACCOUNT_H
#define UI_NEWACCOUNT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_NewAccount
{
public:
    QGroupBox *groupBox;
    QPushButton *RegisterButton;
    QPushButton *CancelButton;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *NewUsernameBox;
    QLineEdit *NewPasswordBox;
    QLineEdit *ConfirmPasswordBox;
    QLabel *label_4;
    QLabel *re_confirm;

    void setupUi(QDialog *NewAccount)
    {
        if (NewAccount->objectName().isEmpty())
            NewAccount->setObjectName(QStringLiteral("NewAccount"));
        NewAccount->resize(393, 416);
        NewAccount->setMinimumSize(QSize(393, 416));
        NewAccount->setMaximumSize(QSize(393, 416));
        QIcon icon;
        icon.addFile(QStringLiteral(":/new/prefix1/Resources/Icons/lock-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        NewAccount->setWindowIcon(icon);
        groupBox = new QGroupBox(NewAccount);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(20, 20, 351, 381));
        RegisterButton = new QPushButton(groupBox);
        RegisterButton->setObjectName(QStringLiteral("RegisterButton"));
        RegisterButton->setGeometry(QRect(170, 340, 81, 31));
        CancelButton = new QPushButton(groupBox);
        CancelButton->setObjectName(QStringLiteral("CancelButton"));
        CancelButton->setGeometry(QRect(260, 340, 81, 31));
        layoutWidget = new QWidget(groupBox);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 180, 331, 121));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout->addWidget(label_2);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        verticalLayout->addWidget(label_3);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        NewUsernameBox = new QLineEdit(layoutWidget);
        NewUsernameBox->setObjectName(QStringLiteral("NewUsernameBox"));

        verticalLayout_2->addWidget(NewUsernameBox);

        NewPasswordBox = new QLineEdit(layoutWidget);
        NewPasswordBox->setObjectName(QStringLiteral("NewPasswordBox"));
        NewPasswordBox->setEchoMode(QLineEdit::Password);

        verticalLayout_2->addWidget(NewPasswordBox);

        ConfirmPasswordBox = new QLineEdit(layoutWidget);
        ConfirmPasswordBox->setObjectName(QStringLiteral("ConfirmPasswordBox"));
        ConfirmPasswordBox->setEchoMode(QLineEdit::Password);

        verticalLayout_2->addWidget(ConfirmPasswordBox);


        horizontalLayout->addLayout(verticalLayout_2);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(110, 30, 121, 141));
        label_4->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/Resources/Bg-Images/account_and_control.png")));
        re_confirm = new QLabel(groupBox);
        re_confirm->setObjectName(QStringLiteral("re_confirm"));
        re_confirm->setGeometry(QRect(20, 310, 321, 16));

        retranslateUi(NewAccount);

        QMetaObject::connectSlotsByName(NewAccount);
    } // setupUi

    void retranslateUi(QDialog *NewAccount)
    {
        NewAccount->setWindowTitle(QApplication::translate("NewAccount", "Dialog", 0));
        groupBox->setTitle(QApplication::translate("NewAccount", "Enter the Details", 0));
        RegisterButton->setText(QApplication::translate("NewAccount", "Register", 0));
        CancelButton->setText(QApplication::translate("NewAccount", "Cancel", 0));
        label->setText(QApplication::translate("NewAccount", "Username", 0));
        label_2->setText(QApplication::translate("NewAccount", "Password", 0));
        label_3->setText(QApplication::translate("NewAccount", "Confirm Password", 0));
        label_4->setText(QString());
        re_confirm->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class NewAccount: public Ui_NewAccount {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWACCOUNT_H
