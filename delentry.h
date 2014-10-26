#ifndef DELENTRY_H
#define DELENTRY_H

#include <QDialog>
#include <QSqlDatabase>

namespace Ui {
class DelEntry;
}

class DelEntry : public QDialog
{
    Q_OBJECT

public:
    int current_user_id;
    explicit DelEntry(QWidget *parent = 0,int current_user=1);
    ~DelEntry();
    QSqlDatabase db;


private slots:
    void on_DeleteButton_clicked();

    bool createConnection();

    void on_CancelButton_clicked();

    void on_DeleteAllButton_clicked();

private:
    Ui::DelEntry *ui;
};

#endif // DELENTRY_H
