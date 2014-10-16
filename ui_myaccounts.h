/********************************************************************************
** Form generated from reading UI file 'myaccounts.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYACCOUNTS_H
#define UI_MYACCOUNTS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MyAccounts
{
public:
    QAction *action_New;
    QAction *action_Close;
    QAction *action_About;
    QWidget *centralwidget;
    QListWidget *listWidget;
    QTableView *tableView;
    QLabel *StatusbarLabel;
    QMenuBar *menubar;
    QMenu *menu_File;
    QMenu *menu_Help;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MyAccounts)
    {
        if (MyAccounts->objectName().isEmpty())
            MyAccounts->setObjectName(QStringLiteral("MyAccounts"));
        MyAccounts->resize(640, 451);
        MyAccounts->setMinimumSize(QSize(640, 451));
        MyAccounts->setMaximumSize(QSize(640, 451));
        QIcon icon;
        icon.addFile(QStringLiteral(":/new/prefix1/Resources/Icons/lock-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        MyAccounts->setWindowIcon(icon);
        action_New = new QAction(MyAccounts);
        action_New->setObjectName(QStringLiteral("action_New"));
        action_Close = new QAction(MyAccounts);
        action_Close->setObjectName(QStringLiteral("action_Close"));
        action_About = new QAction(MyAccounts);
        action_About->setObjectName(QStringLiteral("action_About"));
        centralwidget = new QWidget(MyAccounts);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        listWidget = new QListWidget(centralwidget);
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/new/prefix1/Resources/Bg-Images/account_and_control.png"), QSize(), QIcon::Normal, QIcon::Off);
        QFont font;
        font.setPointSize(7);
        QListWidgetItem *__qlistwidgetitem = new QListWidgetItem(listWidget);
        __qlistwidgetitem->setFont(font);
        __qlistwidgetitem->setIcon(icon1);
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::Dense4Pattern);
        QListWidgetItem *__qlistwidgetitem1 = new QListWidgetItem(listWidget);
        __qlistwidgetitem1->setFont(font);
        __qlistwidgetitem1->setForeground(brush);
        __qlistwidgetitem1->setIcon(icon1);
        QListWidgetItem *__qlistwidgetitem2 = new QListWidgetItem(listWidget);
        __qlistwidgetitem2->setFont(font);
        __qlistwidgetitem2->setIcon(icon1);
        QListWidgetItem *__qlistwidgetitem3 = new QListWidgetItem(listWidget);
        __qlistwidgetitem3->setFont(font);
        __qlistwidgetitem3->setIcon(icon1);
        QListWidgetItem *__qlistwidgetitem4 = new QListWidgetItem(listWidget);
        __qlistwidgetitem4->setFont(font);
        __qlistwidgetitem4->setIcon(icon1);
        QListWidgetItem *__qlistwidgetitem5 = new QListWidgetItem(listWidget);
        __qlistwidgetitem5->setFont(font);
        __qlistwidgetitem5->setIcon(icon1);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setGeometry(QRect(11, 0, 171, 391));
        listWidget->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        listWidget->setIconSize(QSize(69, 63));
        listWidget->setTextElideMode(Qt::ElideMiddle);
        listWidget->setViewMode(QListView::ListMode);
        listWidget->setUniformItemSizes(true);
        listWidget->setSelectionRectVisible(true);
        tableView = new QTableView(centralwidget);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setGeometry(QRect(180, 0, 451, 391));
        tableView->setFrameShape(QFrame::Box);
        tableView->setFrameShadow(QFrame::Plain);
        tableView->setLineWidth(1);
        tableView->setMidLineWidth(0);
        tableView->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        tableView->setTextElideMode(Qt::ElideMiddle);
        tableView->setSortingEnabled(true);
        tableView->horizontalHeader()->setStretchLastSection(true);
        StatusbarLabel = new QLabel(centralwidget);
        StatusbarLabel->setObjectName(QStringLiteral("StatusbarLabel"));
        StatusbarLabel->setGeometry(QRect(230, 380, 391, 41));
        MyAccounts->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MyAccounts);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 640, 21));
        menu_File = new QMenu(menubar);
        menu_File->setObjectName(QStringLiteral("menu_File"));
        menu_Help = new QMenu(menubar);
        menu_Help->setObjectName(QStringLiteral("menu_Help"));
        MyAccounts->setMenuBar(menubar);
        statusBar = new QStatusBar(MyAccounts);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MyAccounts->setStatusBar(statusBar);

        menubar->addAction(menu_File->menuAction());
        menubar->addAction(menu_Help->menuAction());
        menu_File->addAction(action_New);
        menu_File->addAction(action_Close);
        menu_Help->addAction(action_About);

        retranslateUi(MyAccounts);

        QMetaObject::connectSlotsByName(MyAccounts);
    } // setupUi

    void retranslateUi(QMainWindow *MyAccounts)
    {
        MyAccounts->setWindowTitle(QApplication::translate("MyAccounts", "Accounts", 0));
        action_New->setText(QApplication::translate("MyAccounts", "&New Entry", 0));
        action_Close->setText(QApplication::translate("MyAccounts", "&Close", 0));
        action_About->setText(QApplication::translate("MyAccounts", "&About", 0));

        const bool __sortingEnabled = listWidget->isSortingEnabled();
        listWidget->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = listWidget->item(0);
        ___qlistwidgetitem->setText(QApplication::translate("MyAccounts", "All Accounts", 0));
        QListWidgetItem *___qlistwidgetitem1 = listWidget->item(1);
        ___qlistwidgetitem1->setText(QApplication::translate("MyAccounts", "Social Networks", 0));
        QListWidgetItem *___qlistwidgetitem2 = listWidget->item(2);
        ___qlistwidgetitem2->setText(QApplication::translate("MyAccounts", "E-Mails", 0));
        QListWidgetItem *___qlistwidgetitem3 = listWidget->item(3);
        ___qlistwidgetitem3->setText(QApplication::translate("MyAccounts", "Bank", 0));
        QListWidgetItem *___qlistwidgetitem4 = listWidget->item(4);
        ___qlistwidgetitem4->setText(QApplication::translate("MyAccounts", "Office", 0));
        QListWidgetItem *___qlistwidgetitem5 = listWidget->item(5);
        ___qlistwidgetitem5->setText(QApplication::translate("MyAccounts", "Education", 0));
        listWidget->setSortingEnabled(__sortingEnabled);

#ifndef QT_NO_WHATSTHIS
        listWidget->setWhatsThis(QApplication::translate("MyAccounts", "View your account by type", 0));
#endif // QT_NO_WHATSTHIS
        StatusbarLabel->setText(QString());
        menu_File->setTitle(QApplication::translate("MyAccounts", "&File", 0));
        menu_Help->setTitle(QApplication::translate("MyAccounts", "&Help", 0));
    } // retranslateUi

};

namespace Ui {
    class MyAccounts: public Ui_MyAccounts {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYACCOUNTS_H
