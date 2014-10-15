#include "addentry.h"
#include "ui_addentry.h"
#include <QListWidget>
#include <QString>
#include <QDebug>
#include <QListWidgetItem>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include "tinyaes.h"
#include <QMessageBox>
#include "myaccounts.h"

AddEntry::AddEntry(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddEntry)
{
    ui->setupUi(this);
    createConnection();
}

AddEntry::~AddEntry()
{
    delete ui;
}

bool AddEntry::createConnection()
{

    db = QSqlDatabase :: addDatabase("QSQLITE","passwordmanager");

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

QString listitem;
void AddEntry::on_Ok_Button_clicked()
{
    //Get the inputs
    QString acc_password = ui->add_password->text();
    QString acc_username = ui->add_username->text();
    QString acc_link = ui->add_link->text();

    qDebug() << acc_link << " "<< acc_password << " " << acc_username;

    QSqlQuery qry(db);
    qry.prepare("INSERT INTO useraccount (Username,Password,Link,M_ID,AccType) VALUES(:usr,:pass,:l,:m,:acc)");
    qry.bindValue(":usr",acc_username);
    qry.bindValue(":pass",acc_password);
    qry.bindValue(":l",acc_link);
    qry.bindValue(":m","o1");
    qry.bindValue(":acc",listitem);
    qry.exec();
    MyAccounts *goback = new MyAccounts;
    goback->show();
    close();
}

void AddEntry::on_account_type_list_itemClicked(QListWidgetItem *item)
{
    listitem = ui->account_type_list->currentItem()->text();
    qDebug()<<listitem;
}

void AddEntry::on_Cancel_Button_clicked()
{
    QMessageBox::StandardButton cancel;
    cancel = QMessageBox::question(this,"Cancel","Do you want to cancel the entry?",QMessageBox::Yes|QMessageBox::No);

    if(cancel == QMessageBox::Yes)
    {
        close();
        db.close();
    }


}
