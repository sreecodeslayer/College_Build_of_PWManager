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

    void on_action_New_triggered();

    void on_action_Close_triggered();

    void on_listWidget_clicked(const QModelIndex &index);

    void on_actionDelete_Entry_triggered();

    void on_AddEntryButton_clicked();

    void on_DeleteButton_clicked();

    void on_EditButton_clicked();

private:
    Ui::MyAccounts *ui;
};

#endif // MYACCOUNTS_H
