#include "editentry.h"
#include "ui_editentry.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>
#include <QListWidgetItem>
#include <QDebug>
#include "tinyaes.h"
#include "myaccounts.h"

EditEntry::EditEntry(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditEntry)
{
    ui->setupUi(this);
    createConnection();
}

EditEntry::~EditEntry()
{
    delete ui;
}
bool EditEntry::createConnection()
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

QString list_item;

void EditEntry::on_EditButton_clicked()
{
    QString old_usrnm = ui->OldUsername->text();
    QString old_pass = ui->OldPassword->text();
    QString old_link = ui->OldLink->text();

    QString new_usrnm = ui->NewUsername->text();
    QString new_pass = ui->NewPassword->text();
    QString new_link= ui->NewLink->text();
    QString output_username,output_password,output_link;

    QSqlQuery query(db);
    query.exec("SELECT Username,Password,Link FROM Useraccount");
    while(query.next())
    {
        output_username = query.value(0).toString();
        output_password = query.value(1).toString();
        output_link = query.value(2).toString();

        if(output_username == old_usrnm && output_link == old_link)
        {
            ui->ErrorLabel->setText("");
            QSqlQuery qry(db);

            qry.prepare("UPDATE useraccount SET Username = :user,Password = :passw,Link = :lnk,AccType = :acctype WHERE Username = :oldusr AND Link = :oldlnk");

            qry.bindValue(":user",new_usrnm);
            qry.bindValue(":passw",encr_Password(new_pass));
            qry.bindValue(":lnk",new_link);
            qry.bindValue(":acctype",list_item);

            qry.bindValue(":oldusr",old_usrnm);
            qry.bindValue(":oldlnk",old_link);

            qry.exec();

            on_CancelButton_clicked();

        }
        else
            ui->ErrorLabel->setText("<font color = red size = 3>Invalid current details!</font>");
    }

}

void EditEntry::on_account_type_list_itemClicked(QListWidgetItem *item)
{
    list_item = ui->account_type_list->currentItem()->text();
}

TinyAES pass_obj;
QByteArray ende_key = pass_obj.HexStringToByte("729308A8E815F6A46EB3A8AE6D5463CA7B64A0E2E11BC26A68106FC7697E727E");//if changing, change in myaccounts.cpp as well

//actually is there a need to replace the key with MasterPassword?

QString EditEntry::encr_Password(QString acc_pass)
{
    QByteArray encr_pass = pass_obj.HexStringToByte(acc_pass);
    QByteArray encr_res;
    encr_res = pass_obj.Encrypt(encr_pass,ende_key);

    qDebug()<<QString(encr_res)<< "Encrypted";
    decr_Password(encr_res);//just to test both function
    return encr_res;
}

QString EditEntry::decr_Password(QByteArray encr_pass)
{
    QByteArray plain_pass = pass_obj.Decrypt(encr_pass,ende_key);
    QString actual_password = plain_pass.toHex();
    qDebug()<< QString(plain_pass)<<" Decrypted & actuall pass = "<<actual_password.toUtf8();

    return plain_pass;
}



void EditEntry::on_CancelButton_clicked()
{
    MyAccounts *goback = new MyAccounts;
    goback->show();
    close();
}
