#include "editentry.h"
#include "ui_editentry.h"

EditEntry::EditEntry(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditEntry)
{
    ui->setupUi(this);
}

EditEntry::~EditEntry()
{
    delete ui;
}
