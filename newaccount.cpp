#include "newaccount.h"
#include "dialog.h"
#include "ui_newaccount.h"
#include <QString>
#include <QDebug>
#include <QLabel>
#include <QMessageBox>
#include <QCryptographicHash>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>

QString New_username;
QString New_password;
QString Confirm_password;

int M_id = 0;

NewAccount::NewAccount(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewAccount)
{
    ui->setupUi(this);
}

NewAccount::~NewAccount()
{
    delete ui;
}

bool NewAccount::createConnection()
{

    QSqlDatabase db = QSqlDatabase::database("passwordmanager");
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
void NewAccount::on_RegisterButton_clicked()
{
       //Password confirmation handled by Signals and Slots...Get the Inputs

       New_username = ui->NewUsernameBox->text();
       New_password = ui->NewPasswordBox->text();
       Confirm_password = ui->ConfirmPasswordBox->text();

       QString Reg_query, M_id_Label = "MID";

       if(confirm_password_check() && createConnection())
       {
           //Hash the password
           QByteArray password_hashkey ;
           password_hashkey.append(New_password);
           QCryptographicHash passwordHasher(QCryptographicHash::Sha1);
           passwordHasher.addData(password_hashkey);
           QByteArray hash_key_result = passwordHasher.result();
           qDebug()<< "New-account, reg button clicked"+hash_key_result;

           M_id_Label.append(char(M_id));

           QSqlDatabase db=QSqlDatabase::database("passwordmanager");
           QSqlQuery Reg_query(db);
           Reg_query.prepare("INSERT INTO pwmanager (M_ID,Username,MasterPassword) VALUES(:mid,:username,:password)");
           Reg_query.bindValue(":mid",M_id_Label); //this is not working as expected o.O :D
           Reg_query.bindValue(":username",New_username);
           Reg_query.bindValue(":password",hash_key_result);
           Reg_query.exec();

           QMessageBox::StandardButton registered;
           registered = QMessageBox::information(this,"Successfull Register","Your account has been registered!<br>Please log in to continue!");
           if(registered)
           {
               Dialog *s = new Dialog;
               s->show();
               db.close();
               close();
           }

           M_id++; // thought of unique ID this way, but resets when quitting :D

       }
}


/*void NewAccount::createPersonTable(int M_id)
{

    // Create table
    bool ret = false;
    QSqlDatabase db=QSqlDatabase::database("passwordmanager");
    QString table_name = "table_";
    if (db.isOpen())
    {
                   //create table for that corresponding user
                   QSqlQuery create_table(db);
                   qDebug()<<"Now in createPersonTable func!";
                   create_table.prepare("CREATE TABLE IF NOT EXISTS :tableName(M_ID VARCHAR PRIMARY KEY NOT NULL,Username VARCHAR NOT NULL,Password VARCHAR NOT NULL,Link VARCHAR");
                   table_name = table_name.append(New_username);

                   create_table.bindValue(":tableName",table_name); //His corresponding table
                   ret = create_table.exec();
                   qDebug()<<ret;
                   if(ret)
                   {
                       QMessageBox::StandardButton registered;
                       registered = QMessageBox::information(this,"Successfull Register","Your account has been registered!<br>Please log in to continue!");
                       if(registered)
                       {
                           Dialog *s = new Dialog;
                           s->show();
                           close();
                       }

                   }

    }
} */

void NewAccount::on_CancelButton_clicked()
{
    QMessageBox::StandardButton cancel;
    cancel=QMessageBox::question(this,"Cancel","Do you really want to cancel ?",QMessageBox::Yes|QMessageBox::No);
    if(cancel==QMessageBox::Yes)
    {
        Dialog *s = new Dialog;
        s->show();
        close();
    }
}

bool NewAccount::confirm_password_check()
{
    //Password Entry Confirm, Re-Confirm
    if(ui->NewPasswordBox->text() == ui->ConfirmPasswordBox->text())
    {

        //connect(ui->ConfirmPass_Reg, SIGNAL(returnPressed()),ui->Register_Button,SLOT(click()));
        ui->re_confirm->setText(""); //Set label back to empty
        return true;
    }
    else
    {

        //connect(ui->ConfirmPass_Reg, SIGNAL(returnPressed()),ui->ConfirmPass_Reg,SLOT(setFocus()));
        ui->re_confirm->setText("<font color = red> Password do not match!</font>");
        return false;
    }

}

void NewAccount::on_ConfirmPasswordBox_textEdited(const QString &arg1)
{
    confirm_password_check();
}
