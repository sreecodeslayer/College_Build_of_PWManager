/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QPushButton *LogInButton;
    QPushButton *NewAccountButton;
    QPushButton *QuitButton;
    QLabel *label_3;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *label_2;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *UsernameBox;
    QLineEdit *PasswordBox;
    QLabel *loginerror;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QStringLiteral("Dialog"));
        Dialog->resize(269, 386);
        Dialog->setMinimumSize(QSize(269, 386));
        Dialog->setMaximumSize(QSize(269, 386));
        QIcon icon;
        icon.addFile(QStringLiteral(":/new/prefix1/Resources/Icons/lock-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        Dialog->setWindowIcon(icon);
        LogInButton = new QPushButton(Dialog);
        LogInButton->setObjectName(QStringLiteral("LogInButton"));
        LogInButton->setGeometry(QRect(90, 300, 111, 41));
        NewAccountButton = new QPushButton(Dialog);
        NewAccountButton->setObjectName(QStringLiteral("NewAccountButton"));
        NewAccountButton->setGeometry(QRect(10, 350, 81, 31));
        QuitButton = new QPushButton(Dialog);
        QuitButton->setObjectName(QStringLiteral("QuitButton"));
        QuitButton->setGeometry(QRect(180, 350, 81, 31));
        label_3 = new QLabel(Dialog);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(70, 60, 131, 101));
        label_3->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/Resources/Bg-Images/key.png")));
        layoutWidget = new QWidget(Dialog);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 190, 231, 61));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout->addWidget(label_2);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        UsernameBox = new QLineEdit(layoutWidget);
        UsernameBox->setObjectName(QStringLiteral("UsernameBox"));

        verticalLayout_2->addWidget(UsernameBox);

        PasswordBox = new QLineEdit(layoutWidget);
        PasswordBox->setObjectName(QStringLiteral("PasswordBox"));
        PasswordBox->setEchoMode(QLineEdit::Password);

        verticalLayout_2->addWidget(PasswordBox);


        horizontalLayout->addLayout(verticalLayout_2);

        loginerror = new QLabel(Dialog);
        loginerror->setObjectName(QStringLiteral("loginerror"));
        loginerror->setGeometry(QRect(20, 250, 231, 41));
        layoutWidget->raise();
        LogInButton->raise();
        NewAccountButton->raise();
        QuitButton->raise();
        label_3->raise();
        loginerror->raise();

        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "Dialog", 0));
        LogInButton->setText(QApplication::translate("Dialog", "Log In", 0));
        NewAccountButton->setText(QApplication::translate("Dialog", "New", 0));
        QuitButton->setText(QApplication::translate("Dialog", "Quit", 0));
        label_3->setText(QString());
        label->setText(QApplication::translate("Dialog", "Username", 0));
        label_2->setText(QApplication::translate("Dialog", "Password", 0));
        loginerror->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
