#ifndef MYACCOUNTS_H
#define MYACCOUNTS_H

#include <QMainWindow>
#include<QSqlDatabase>

namespace Ui {
class MyAccounts;
}

class MyAccounts : public QMainWindow
{
    Q_OBJECT
    QSqlDatabase db;

public:
    explicit MyAccounts(QWidget *parent = 0);
    ~MyAccounts();
private slots:
    void populateTable();
    bool createConnection();
private:
    Ui::MyAccounts *ui;
};

#endif // MYACCOUNTS_H
