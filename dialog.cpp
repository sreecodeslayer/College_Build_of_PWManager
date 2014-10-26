#include "dialog.h"
#include "ui_dialog.h"
#include <QString>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlError>
#include <QDebug>
#include <QSqlQuery>
#include <QDir>
#include <QCryptographicHash>
#include "myaccounts.h"


QString password;
QString username;

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    this->setWindowTitle("Log In");
   // db = QSqlDatabase::database("passwordmanager");
    createConnection();
}
Dialog::~Dialog()
{
    delete ui;
    db.close();
}


bool Dialog::createConnection()
{

    db = QSqlDatabase :: addDatabase("QSQLITE","passwordmanager");
    QString path = QDir::currentPath();

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


void Dialog::on_LogInButton_clicked()
{
        //Log in check and Log in
        username = ui->UsernameBox->text();
        password = ui->PasswordBox->text();

        //Hash the password and compare from table
        QByteArray password_hashkey ;
        password_hashkey.append(password);
        QCryptographicHash passwordHasher(QCryptographicHash::Sha1);
        passwordHasher.addData(password_hashkey);
        QByteArray hash_key_result = passwordHasher.result();
        QString hash_str = hash_key_result;
        qDebug()<< "Dialog-, log in button clicked" + hash_key_result;

        QSqlQuery Log_in_query(db);
        QString output_hashedpassword,output_username, query = "SELECT Username,MasterPassword,M_ID FROM pwmanager";

        Log_in_query.exec(query);
        while(Log_in_query.next())
        {
            output_username = Log_in_query.value(0).toString();
            output_hashedpassword = Log_in_query.value(1).toString();
            int current_user_id=Log_in_query.value(2).toString().toInt();
            if(output_hashedpassword == hash_str && output_username == username)
            {
                ui->loginerror->setText("");

                qDebug()<<"Now open next ui!";
                this->hide();
                /*int current_user_id=5;*/ //to be determined
                MyAccounts *main_ui = new MyAccounts(this,current_user_id);
                main_ui->show();
                break;

            }
            else
            {
              ui->loginerror->setText("<font color = red size = 3>Invalid Username and/or Password,<br> Please try again or register new account!</font>");
            }
        }


}

void Dialog::on_NewAccountButton_clicked()
{
    NewAccount *dialog=new NewAccount();
    dialog->setWindowTitle("Register");
    this->hide();
    db.close();
    dialog->show();
}

void Dialog::on_QuitButton_clicked()
{
    //Quit Button
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this,"Quit","Do you really wan't to quit the application?",QMessageBox::Yes| QMessageBox::No);

    if(reply == QMessageBox::Yes)
    {
     db.close();
     close();
    }
}
