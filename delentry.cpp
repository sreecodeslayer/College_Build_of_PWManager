#include "delentry.h"
#include "ui_delentry.h"

DelEntry::DelEntry(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DelEntry)
{
    ui->setupUi(this);
}

DelEntry::~DelEntry()
{
    delete ui;
}
