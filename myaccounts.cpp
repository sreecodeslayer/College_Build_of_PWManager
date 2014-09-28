#include "myaccounts.h"
#include "ui_myaccounts.h"
#include <QSqlTableModel>
#include <QString>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlError>
#include <QDebug>
#include <QSqlQuery>

MyAccounts::MyAccounts(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MyAccounts)
{
    ui->setupUi(this);
    createConnection();
    populateTable();
}

MyAccounts::~MyAccounts()
{
    delete ui;
}

bool MyAccounts::createConnection()
{

    db = QSqlDatabase::database("passwordmanager");
    //db = QSqlDatabase :: addDatabase("QSQLITE","passwordmanager");

    //Setting the relative path
    db.setDatabaseName("../Lock-Up/Db/passwordmanager.sqlite");
    if(!db.open())
         {
             QMessageBox::information(0, "Connection Failed!", db.lastError().text(),QMessageBox::Ok, QMessageBox::NoButton);
         }
    else
        qDebug ()<<"Connected!"; // TEST
    return true;
}

void MyAccounts::populateTable()
{
    //db = QSqlDatabase :: addDatabase("QSQLITE","passwordmanager");

    qDebug()<<"Now populate";
    QSqlTableModel *model = new QSqlTableModel(this,db);
    model->setTable("useraccount");
    model->select();
    model->setHeaderData(0, Qt::Horizontal, tr("First col"));
    model->setHeaderData(1, Qt::Horizontal, tr("second col"));
    ui->tableView->setModel(model);
    ui->tableView->show();
    ui->tableView->hideColumn(3);

   /* QTableView *view = new QTableView;
    view->setModel(model);
    view->hideColumn(0); // don't show the ID*/
    //view->show();
    qDebug()<<model->lastError().text();
    db.close();
}
