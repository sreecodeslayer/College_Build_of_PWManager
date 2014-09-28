#include "addentry.h"
#include "ui_addentry.h"
#include <QListWidget>
#include <QString>
#include <QDebug>
#include <QListWidgetItem>
AddEntry::AddEntry(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddEntry)
{
    ui->setupUi(this);
}

AddEntry::~AddEntry()
{
    delete ui;
}
QString listitem;
void AddEntry::on_Ok_Button_clicked()
{
    //Get the inputs

}

void AddEntry::on_account_type_list_itemClicked(QListWidgetItem *item)
{
    listitem = ui->account_type_list->currentItem()->text();
    qDebug()<<listitem;
}
