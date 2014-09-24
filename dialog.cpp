#include "dialog.h"
#include "ui_dialog.h"
#include <QString>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlError>
#include <QDebug>
#include <QSqlQuery>
#include <QDir>


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

QSqlDatabase db ;

bool Dialog::createConnection()
{

    db = QSqlDatabase :: addDatabase("QSQLITE","passwordmanager");
    QString path = QDir::currentPath();

    //Setting the relative path
    db.setDatabaseName("../Db/passwordwmanager.sqlite");
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
    if(createConnection())
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
