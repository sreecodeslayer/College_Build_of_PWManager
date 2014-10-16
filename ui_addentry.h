/********************************************************************************
** Form generated from reading UI file 'addentry.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDENTRY_H
#define UI_ADDENTRY_H

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
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AddEntry
{
public:
    QGroupBox *groupBox;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_4;
    QListWidget *account_type_list;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *add_username;
    QLineEdit *add_password;
    QLineEdit *add_link;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *Ok_Button;
    QPushButton *Cancel_Button;

    void setupUi(QDialog *AddEntry)
    {
        if (AddEntry->objectName().isEmpty())
            AddEntry->setObjectName(QStringLiteral("AddEntry"));
        AddEntry->resize(269, 279);
        AddEntry->setMinimumSize(QSize(269, 279));
        AddEntry->setMaximumSize(QSize(269, 279));
        groupBox = new QGroupBox(AddEntry);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 10, 251, 261));
        groupBox->setMinimumSize(QSize(251, 261));
        groupBox->setMaximumSize(QSize(251, 261));
        layoutWidget = new QWidget(groupBox);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(11, 21, 231, 191));
        verticalLayout_4 = new QVBoxLayout(layoutWidget);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_2->addWidget(label_4);

        account_type_list = new QListWidget(layoutWidget);
        QIcon icon;
        icon.addFile(QStringLiteral(":/new/prefix1/Resources/Bg-Images/list-tree-50p.png"), QSize(), QIcon::Normal, QIcon::Off);
        QListWidgetItem *__qlistwidgetitem = new QListWidgetItem(account_type_list);
        __qlistwidgetitem->setIcon(icon);
        QListWidgetItem *__qlistwidgetitem1 = new QListWidgetItem(account_type_list);
        __qlistwidgetitem1->setIcon(icon);
        QListWidgetItem *__qlistwidgetitem2 = new QListWidgetItem(account_type_list);
        __qlistwidgetitem2->setIcon(icon);
        QListWidgetItem *__qlistwidgetitem3 = new QListWidgetItem(account_type_list);
        __qlistwidgetitem3->setIcon(icon);
        QListWidgetItem *__qlistwidgetitem4 = new QListWidgetItem(account_type_list);
        __qlistwidgetitem4->setIcon(icon);
        QListWidgetItem *__qlistwidgetitem5 = new QListWidgetItem(account_type_list);
        __qlistwidgetitem5->setIcon(icon);
        QListWidgetItem *__qlistwidgetitem6 = new QListWidgetItem(account_type_list);
        __qlistwidgetitem6->setIcon(icon);
        account_type_list->setObjectName(QStringLiteral("account_type_list"));
        account_type_list->setAcceptDrops(true);
        account_type_list->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        account_type_list->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        account_type_list->setAlternatingRowColors(true);
        account_type_list->setMovement(QListView::Static);
        account_type_list->setProperty("isWrapping", QVariant(false));
        account_type_list->setResizeMode(QListView::Fixed);
        account_type_list->setViewMode(QListView::ListMode);
        account_type_list->setUniformItemSizes(true);
        account_type_list->setSortingEnabled(false);

        horizontalLayout_2->addWidget(account_type_list);


        verticalLayout_3->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
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
        add_username = new QLineEdit(layoutWidget);
        add_username->setObjectName(QStringLiteral("add_username"));

        verticalLayout_2->addWidget(add_username);

        add_password = new QLineEdit(layoutWidget);
        add_password->setObjectName(QStringLiteral("add_password"));
        add_password->setEchoMode(QLineEdit::Password);

        verticalLayout_2->addWidget(add_password);

        add_link = new QLineEdit(layoutWidget);
        add_link->setObjectName(QStringLiteral("add_link"));

        verticalLayout_2->addWidget(add_link);


        horizontalLayout->addLayout(verticalLayout_2);


        verticalLayout_3->addLayout(horizontalLayout);


        verticalLayout_4->addLayout(verticalLayout_3);

        layoutWidget1 = new QWidget(groupBox);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(80, 220, 158, 25));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        Ok_Button = new QPushButton(layoutWidget1);
        Ok_Button->setObjectName(QStringLiteral("Ok_Button"));

        horizontalLayout_3->addWidget(Ok_Button);

        Cancel_Button = new QPushButton(layoutWidget1);
        Cancel_Button->setObjectName(QStringLiteral("Cancel_Button"));

        horizontalLayout_3->addWidget(Cancel_Button);

#ifndef QT_NO_SHORTCUT
        label_4->setBuddy(account_type_list);
        label->setBuddy(add_username);
        label_2->setBuddy(add_password);
        label_3->setBuddy(add_link);
#endif // QT_NO_SHORTCUT
        QWidget::setTabOrder(account_type_list, add_username);
        QWidget::setTabOrder(add_username, add_password);
        QWidget::setTabOrder(add_password, add_link);

        retranslateUi(AddEntry);

        QMetaObject::connectSlotsByName(AddEntry);
    } // setupUi

    void retranslateUi(QDialog *AddEntry)
    {
        AddEntry->setWindowTitle(QApplication::translate("AddEntry", "Dialog", 0));
        groupBox->setTitle(QApplication::translate("AddEntry", "Enter the details: ", 0));
        label_4->setText(QApplication::translate("AddEntry", "A/C type:", 0));

        const bool __sortingEnabled = account_type_list->isSortingEnabled();
        account_type_list->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = account_type_list->item(0);
        ___qlistwidgetitem->setText(QApplication::translate("AddEntry", "Social Network", 0));
        QListWidgetItem *___qlistwidgetitem1 = account_type_list->item(1);
        ___qlistwidgetitem1->setText(QApplication::translate("AddEntry", "Bank", 0));
        QListWidgetItem *___qlistwidgetitem2 = account_type_list->item(2);
        ___qlistwidgetitem2->setText(QApplication::translate("AddEntry", "E-Mails", 0));
        QListWidgetItem *___qlistwidgetitem3 = account_type_list->item(3);
        ___qlistwidgetitem3->setText(QApplication::translate("AddEntry", "Webpages", 0));
        QListWidgetItem *___qlistwidgetitem4 = account_type_list->item(4);
        ___qlistwidgetitem4->setText(QApplication::translate("AddEntry", "Online Shopping", 0));
        QListWidgetItem *___qlistwidgetitem5 = account_type_list->item(5);
        ___qlistwidgetitem5->setText(QApplication::translate("AddEntry", "Office", 0));
        QListWidgetItem *___qlistwidgetitem6 = account_type_list->item(6);
        ___qlistwidgetitem6->setText(QApplication::translate("AddEntry", "Education", 0));
        account_type_list->setSortingEnabled(__sortingEnabled);

        label->setText(QApplication::translate("AddEntry", "Username:", 0));
        label_2->setText(QApplication::translate("AddEntry", "Password:", 0));
        label_3->setText(QApplication::translate("AddEntry", "Link:", 0));
        Ok_Button->setText(QApplication::translate("AddEntry", "Add", 0));
        Cancel_Button->setText(QApplication::translate("AddEntry", "Cancel", 0));
    } // retranslateUi

};

namespace Ui {
    class AddEntry: public Ui_AddEntry {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDENTRY_H
