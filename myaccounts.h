#ifndef MYACCOUNTS_H
#define MYACCOUNTS_H

#include <QMainWindow>

namespace Ui {
class MyAccounts;
}

class MyAccounts : public QMainWindow
{
    Q_OBJECT

public:
    explicit MyAccounts(QWidget *parent = 0);
    ~MyAccounts();

private:
    Ui::MyAccounts *ui;
};

#endif // MYACCOUNTS_H
