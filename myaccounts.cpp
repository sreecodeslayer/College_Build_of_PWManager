#include "myaccounts.h"
#include "ui_myaccounts.h"
#include <QSqlTableModel>
#include <QString>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlError>
#include <QDebug>
#include <QSqlQuery>
#include "delentry.h"
#include "addentry.h"
#include "editentry.h"
#include "tinyaes.h"
#include <QByteArray>
#include <QTimer>

MyAccounts::MyAccounts(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MyAccounts)
{
    ui->setupUi(this);
    createConnection();
    ui->view_password->setText("<font color = blue size = 2>Double click field to see the actuall password!</font>");
    populateTable();
}

MyAccounts::~MyAccounts()
{
    delete ui;
    db.close(); //moved db.close to here for editable table view
}

bool MyAccounts::createConnection()
{

    db = QSqlDatabase::database("passwordmanager");
    //db = QSqlDatabase :: addDatabase("QSQLITE","passwordmanager");

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

void MyAccounts::populateTable()
{
    //db = QSqlDatabase :: addDatabase("QSQLITE","passwordmanager");

    qDebug()<<"Now populate";
    db.open();
    QSqlTableModel *model = new QSqlTableModel(this,db);
    model->setTable("useraccount");
    model->select();
    model->setHeaderData(0, Qt::Horizontal, tr("Username"));
    model->setHeaderData(1, Qt::Horizontal, tr("Password"));
    model->setHeaderData(2, Qt::Horizontal, tr("Link"));
    //model->setHeaderData(4, Qt::Horizontal, tr("Account Type")); -> required?


    ui->tableView->setModel(model);
    ui->tableView->show();
    ui->tableView->hideColumn(3);
    ui->tableView->hideColumn(4);


   /* QTableView *view = new QTableView;
    view->setModel(model);
    view->hideColumn(0); // don't show the ID*/
    //view->show();
    qDebug()<<model->lastError().text();
    //db.close(); // for enabling editable table, db needs to remain open!
}

void MyAccounts::on_action_New_triggered()
{
    AddEntry *new_entry = new AddEntry;
    new_entry->show();
    this->hide();

}

void MyAccounts::on_action_Close_triggered()
{
    db.close();
    close();
}

void MyAccounts::on_listWidget_clicked(const QModelIndex &index)
{
    QString q,type = ui->listWidget->currentItem()->text();
    QSqlTableModel *specific_model = new QSqlTableModel(this,db);

    if(type == "All Accounts")
    {
        //show full table
        populateTable();

    }
    else if(type == "Social Networks")
    {
        //show Social Networks type sorted table
        qDebug()<<type;

        specific_model->setTable("useraccount");
        specific_model->setFilter("Acctype == 'Social Network'");
        specific_model->select();
        specific_model->setHeaderData(0, Qt::Horizontal, tr("Username"));
        specific_model->setHeaderData(1, Qt::Horizontal, tr("Password"));
        specific_model->setHeaderData(2, Qt::Horizontal, tr("Link"));
        //specific_model->setHeaderData(4, Qt::Horizontal, tr("Account Type")); -> required?

        ui->tableView->setModel(specific_model);
        ui->tableView->show();
        ui->tableView->hideColumn(3);
        ui->tableView->hideColumn(4);

    }
    else if(type == "E-Mails")
    {
        //show E-Mails type sorted table
        qDebug()<<ui->listWidget->currentItem()->text();

        specific_model->setTable("useraccount");
        specific_model->setFilter("Acctype == 'E-Mails'");
        specific_model->select();
        specific_model->setHeaderData(0, Qt::Horizontal, tr("Username"));
        specific_model->setHeaderData(1, Qt::Horizontal, tr("Password"));
        specific_model->setHeaderData(2, Qt::Horizontal, tr("Link"));
        //specific_model->setHeaderData(4, Qt::Horizontal, tr("Account Type")); -> required?

        ui->tableView->setModel(specific_model);
        ui->tableView->show();
        ui->tableView->hideColumn(3);
        ui->tableView->hideColumn(4);


    }
    else if(type == "Bank")
    {
        //show Bank type sorted table
        qDebug()<<ui->listWidget->currentItem()->text();

        specific_model->setTable("useraccount");
        specific_model->setFilter("Acctype == 'Bank'");
        specific_model->select();
        specific_model->setHeaderData(0, Qt::Horizontal, tr("Username"));
        specific_model->setHeaderData(1, Qt::Horizontal, tr("Password"));
        specific_model->setHeaderData(2, Qt::Horizontal, tr("Link"));
        //specific_model->setHeaderData(4, Qt::Horizontal, tr("Account Type")); -> required?

        ui->tableView->setModel(specific_model);
        ui->tableView->show();
        ui->tableView->hideColumn(3);
        ui->tableView->hideColumn(4);


    }
    else if(type == "Office")
    {
        //show Office type sorted table
        qDebug()<<ui->listWidget->currentItem()->text();

        specific_model->setTable("useraccount");
        specific_model->setFilter("Acctype == 'Office'");
        specific_model->select();
        specific_model->setHeaderData(0, Qt::Horizontal, tr("Username"));
        specific_model->setHeaderData(1, Qt::Horizontal, tr("Password"));
        specific_model->setHeaderData(2, Qt::Horizontal, tr("Link"));
        //specific_model->setHeaderData(4, Qt::Horizontal, tr("Account Type")); -> required?

        ui->tableView->setModel(specific_model);
        ui->tableView->show();
        ui->tableView->hideColumn(3);
        ui->tableView->hideColumn(4);


    }
    else if(type == "Online Shopping")
    {
        //show Online shopping type sorted table
        qDebug()<<ui->listWidget->currentItem()->text();

        specific_model->setTable("useraccount");
        specific_model->setFilter("Acctype == 'Online Shopping'");
        specific_model->select();
        specific_model->setHeaderData(0, Qt::Horizontal, tr("Username"));
        specific_model->setHeaderData(1, Qt::Horizontal, tr("Password"));
        specific_model->setHeaderData(2, Qt::Horizontal, tr("Link"));
        //specific_model->setHeaderData(4, Qt::Horizontal, tr("Account Type")); -> required?

        ui->tableView->setModel(specific_model);
        ui->tableView->show();
        ui->tableView->hideColumn(3);
        ui->tableView->hideColumn(4);


    }
    else
    {
        //show Education type sorted table
        qDebug()<<ui->listWidget->currentItem()->text();

        specific_model->setTable("useraccount");
        specific_model->setFilter("Acctype == 'Education'");
        specific_model->select();
        specific_model->setHeaderData(0, Qt::Horizontal, tr("Username"));
        specific_model->setHeaderData(1, Qt::Horizontal, tr("Password"));
        specific_model->setHeaderData(2, Qt::Horizontal, tr("Link"));
        //specific_model->setHeaderData(4, Qt::Horizontal, tr("Account Type")); -> required?

        ui->tableView->setModel(specific_model);
        ui->tableView->show();
        ui->tableView->hideColumn(3);
        ui->tableView->hideColumn(4);


    }
}

void MyAccounts::on_actionDelete_Entry_triggered()
{
    DelEntry *del = new DelEntry();
    this->hide();
    del->show();
}

void MyAccounts::on_AddEntryButton_clicked()
{
    on_action_New_triggered();
}

void MyAccounts::on_DeleteButton_clicked()
{
    on_actionDelete_Entry_triggered();
}

void MyAccounts::on_EditButton_clicked()
{
    EditEntry *edit = new EditEntry();
    edit->show();
    this->hide();
}

TinyAES p;
QByteArray encr_decr_key = p.HexStringToByte("94baaf5764ad4948304eb538bb5839c50350f02eabc053f021d1b7f870aade12");
QString MyAccounts::decrPassword(QByteArray encr_password)
{
    QByteArray plain_pass = p.Decrypt(encr_password,encr_decr_key);
    qDebug()<< QString(plain_pass)<<" Decrypted";
    return plain_pass;
}

QByteArray sel_password;
void MyAccounts::on_tableView_doubleClicked(const QModelIndex &index)
{
    //View decrypted password when double clicked
    QModelIndex mo;
    int row = 0;
    row = index.row();
    sel_password = index.sibling(row,1).data().toByteArray();
    qDebug()<<sel_password<<"show this";

    QTimer *pass_timer = new QTimer();
    pass_timer->start(5000);
    showPass();
    connect(pass_timer,SIGNAL(timeout()),this,SLOT(hidePass()));
}
void MyAccounts::showPass()
{
    ui->DecryptedPassword->setText(decrPassword(QByteArray::fromHex(sel_password)));
}
void MyAccounts::hidePass()
{
    ui->DecryptedPassword->setText("");
}
