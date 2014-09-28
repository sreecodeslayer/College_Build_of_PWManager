#include "myaccounts.h"
#include "ui_myaccounts.h"

MyAccounts::MyAccounts(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MyAccounts)
{
    ui->setupUi(this);
}

MyAccounts::~MyAccounts()
{
    delete ui;
}
