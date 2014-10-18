#include "delentry.h"
#include "ui_delentry.h"
#include <QMessageBox>
#include <QDebug>
#include <QSqlError>
#include "myaccounts.h"
#include <QSqlQuery>

DelEntry::DelEntry(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DelEntry)
{
    ui->setupUi(this);
    this->setWindowTitle("Delete");
    createConnection();
}

DelEntry::~DelEntry()
{
    delete ui;

}
bool DelEntry::createConnection()
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

void DelEntry::on_DeleteButton_clicked()
{
    QString username = ui->username->text();
    QString user_link = ui->user_link->text();
    if(username != "" && user_link != "")
    {
        ui->DeleteErrorLabel->setText("");
        QSqlQuery del_query(db);
        del_query.prepare("DELETE FROM Useraccount WHERE Username = :usr AND Link = :link");
        del_query.bindValue(":usr",username);
        del_query.bindValue(":link",user_link);
        if(!del_query.exec())
        {
            QMessageBox::information(this,"", del_query.lastError().text());

        }
        else
        {
            QMessageBox::StandardButton ok;
            ok = QMessageBox::information(this,"Deleted","Deletion Successful!");
            if(ok)
            {
                on_CancelButton_clicked();
            }

        }
    }
    else
        ui->DeleteErrorLabel->setText("<font color = red size = 3>Please enter details to delete!</font>");

}

void DelEntry::on_CancelButton_clicked()
{
    MyAccounts *back = new MyAccounts();
    back->show();
    close();
}

void DelEntry::on_DeleteAllButton_clicked()
{
    QMessageBox::StandardButton delete_all;
    delete_all = QMessageBox::question(this,"Delete all","<font color = red>Caution!</font><br>Delete all?",QMessageBox::Yes|QMessageBox::No);
    if(delete_all == QMessageBox::Yes)
    {
        QSqlQuery del_query(db);
        del_query.exec("DELETE FROM Useraccount");
        on_CancelButton_clicked();
    }
    else
        on_CancelButton_clicked();
}
