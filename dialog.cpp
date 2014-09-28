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
    createConnection();
}

QSqlDatabase db = QSqlDatabase::database("passwordmanager");

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
        QString s = hash_key_result;
        qDebug()<< "Dialog-, log in button clicked" + hash_key_result;

        QSqlQuery Log_in_query(db);
        QString output_hashedpassword,output_username, query = "SELECT Username,MasterPassword FROM pwmanager";

        Log_in_query.exec(query);
        while(Log_in_query.next())
        {
            output_username = Log_in_query.value(0).toString();
            output_hashedpassword = Log_in_query.value(1).toString();

            if(output_hashedpassword == s && output_username == username)
            {
                ui->loginerror->setText("");

                qDebug()<<"Now open next ui!";
                MyAccounts *main_ui = new MyAccounts;
                main_ui->show();
                close();
                break;

            }
            else
            {
              ui->loginerror->setText("<font color = red size = 4>Invalid Username and/or Password,<br> Please try again</font>");
            }
        }


}

void Dialog::on_NewAccountButton_clicked()
{
    NewAccount *dialog=new NewAccount();
    dialog->setWindowTitle("Register");
    this->hide();
    dialog->show();
}

void Dialog::on_QuitButton_clicked()
{
    //Quit Button
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this,"Quit","Do you really wan't to quit the application?",QMessageBox::Yes| QMessageBox::No);

    if(reply == QMessageBox::Yes)
    {
     close();
    }
}
