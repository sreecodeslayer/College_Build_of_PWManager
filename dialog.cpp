#include "dialog.h"
#include "ui_dialog.h"
#include <QString>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlError>
#include <QDebug>
#include <QSqlQuery>


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

Dialog::~Dialog()
{
    delete ui;
}

bool Dialog::createConnection()
{

    QSqlDatabase passwordmanager = QSqlDatabase :: addDatabase("QSQLITE","passwordmanager");

    passwordmanager.setDatabaseName("Db/passwordwmanager.sqlite");

    if(!passwordmanager.open())
    {
        passwordmanager.setDatabaseName("D:/S5IT/Lock-Up/Db/pwmanager.db");

         if(!passwordmanager.open())
         {
             QMessageBox::information(0, "Connection Failed!", passwordmanager.lastError().text(),QMessageBox::Ok, QMessageBox::NoButton);
         }
    }
    return true;
}



void Dialog::on_LogInButton_clicked()
{
    //Log in check and Log in
    username = ui->UsernameBox->text();
    password = ui->PasswordBox->text();

    //Database Check for username and password
    QSqlDatabase db = QSqlDatabase::database("passwordmanager");
    db.open();
    QSqlQuery qry(db);
    qDebug()<<qry.exec("SELECT Username,MasterPassword FROM pwmanager");

}

void Dialog::on_NewAccountButton_clicked()
{
    NewAccount *dialog=new NewAccount();
    dialog->setWindowTitle("Register");
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
