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
}

MyAccounts::~MyAccounts()
{
    delete ui;
}

bool MyAccounts::createConnection()
{

    QSqlDatabase db = QSqlDatabase::database("passwordmanager");
    db = QSqlDatabase :: addDatabase("QSQLITE","passwordmanager");

    //Setting the relative path
    db.setDatabaseName("../College_Build_of_PWManager/Db/passwordmanager.sqlite");
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
    QSqlDatabase db = QSqlDatabase::database("passwordmanager");
    db = QSqlDatabase :: addDatabase("QSQLITE","passwordmanager");

    QSqlTableModel *model = new QSqlTableModel;
    model->setTable("Useraccount");
    model->select();

    ui->my_account_table->setModel(model);
    qDebug()<<model->lastError().text();


    db.close();
}
