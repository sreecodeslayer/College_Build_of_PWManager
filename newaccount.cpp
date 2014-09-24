#include "newaccount.h"
#include "ui_newaccount.h"
#include <QString>
#include <QDebug>
#include <QLabel>
#include <QMessageBox>
#include <QCryptographicHash>

QString New_username;
QString New_password;
QString Confirm_password;

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


void NewAccount::on_RegisterButton_clicked()
{
    //Get the Inputs
       New_username = ui->NewUsernameBox->text();
       New_password = ui->NewPasswordBox->text();
       Confirm_password = ui->ConfirmPasswordBox->text();
       //Password Entry Confirm, Re-Confirm
       if(New_password == Confirm_password)
       {

           connect(ui->ConfirmPasswordBox, SIGNAL(returnPressed()),ui->RegisterButton,SLOT(click()));
           ui->re_confirm->setText(""); //Set label back to empty

           //Hash the password
           QByteArray password_hashkey ;
           password_hashkey.append(New_password);
           QCryptographicHash passwordHasher(QCryptographicHash::Sha1);
           passwordHasher.addData(password_hashkey);

           QByteArray hash_key_result = passwordHasher.result();
           qDebug()<< hash_key_result;

       }
       else
       {

           connect(ui->ConfirmPasswordBox, SIGNAL(returnPressed()),ui->ConfirmPasswordBox,SLOT(setFocus()));
           ui->re_confirm->setText("<font color = red> Please re-enter the password correctly!</font>");
       }
}

void NewAccount::on_CancelButton_clicked()
{
    QMessageBox::StandardButton cancel;
    cancel=QMessageBox::question(this,"Cancel","Do you really want to cancel ?",QMessageBox::Yes|QMessageBox::No);
    if(cancel==QMessageBox::Yes)
    {
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
