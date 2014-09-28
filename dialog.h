#ifndef DIALOG_H
#define DIALOG_H
#include "newaccount.h"
#include <QDialog>
#include <QSqlDatabase>
#include <QSqlError>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();
    QSqlDatabase db;

private slots:
    void on_LogInButton_clicked();

    void on_NewAccountButton_clicked();

    void on_QuitButton_clicked();

    bool createConnection();
private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H
