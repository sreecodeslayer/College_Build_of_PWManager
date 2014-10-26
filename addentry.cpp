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

AddEntry::AddEntry(QWidget *parent,int current_user) :
    QDialog(parent),
    ui(new Ui::AddEntry)
{
    ui->setupUi(this);
    this->setWindowTitle("Add Entry");
    createConnection();
     //int current_user_id=0;
     current_user_id=current_user;
     QMessageBox::information(0, "Cuurent User", QString::number( current_user_id),QMessageBox::Ok, QMessageBox::NoButton);

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
    //QString acc_password = ui->add_password->text().toLatin1();
    QString acc_username = ui->add_username->text();
    QString acc_link = ui->add_link->text();

    //qDebug() << acc_link << " "<< acc_password << " " << acc_username;

    QString enc_pas = encrPassword();
    QSqlQuery qry(db);
    qry.prepare("INSERT INTO useraccount (Username,Password,Link,AccType,M_ID) VALUES(:usr,:pass,:l,:acc,:mid)");
    qry.bindValue(":usr",acc_username);
    qry.bindValue(":pass",enc_pas); //----> encryptPassword(acc_password)
    qry.bindValue(":l",acc_link);
    qry.bindValue(":mid",current_user_id);
    qry.bindValue(":acc",listitem);
    qry.exec();
    MyAccounts *goback = new MyAccounts(this,current_user_id);
    goback->show();
    close();
}

void AddEntry::on_account_type_list_itemClicked(QListWidgetItem *item)
{
    listitem = ui->account_type_list->currentItem()->text();
    //qDebug()<<listitem;
}

void AddEntry::on_Cancel_Button_clicked()
{
    QMessageBox::StandardButton cancel;
    cancel = QMessageBox::question(this,"Cancel","Do you want to cancel the entry?",QMessageBox::Yes|QMessageBox::No);

    if(cancel == QMessageBox::Yes)
    {
        MyAccounts *goback = new MyAccounts;
        goback->show();
        close();
        db.close();
    }
}

//Encryption Codes
TinyAES pass;
QByteArray en_de_key = pass.HexStringToByte("94baaf5764ad4948304eb538bb5839c50350f02eabc053f021d1b7f870aade12");//if changing, change in myaccounts.cpp as well

//actually is there a need to replace the key with MasterPassword?

QString AddEntry::encrPassword()
{

    QByteArray pasw = ui->add_password->text().toLatin1();

    QByteArray encrypted = (pass.Encrypt(pasw,en_de_key)).toHex();
    QByteArray d = QByteArray::fromHex(encrypted);
    qDebug()<<d<<"&&";
    QByteArray decrypted = pass.Decrypt(d,en_de_key);
    qDebug()<<encrypted<<" HERE & --> "<<decrypted;

    return QString(encrypted);
}

QString AddEntry::decrPassword(QByteArray encr_password)
{
    QByteArray plain_text = pass.Decrypt(encr_password,en_de_key);
    //QString actual_pass = plain_text.toHex();
    //qDebug()<< QString(plain_text)<<" Decrypted ";

    return plain_text;
}

