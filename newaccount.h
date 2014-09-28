#ifndef NEWACCOUNT_H
#define NEWACCOUNT_H

#include <QDialog>

namespace Ui {
class NewAccount;
}

class NewAccount : public QDialog
{
    Q_OBJECT

public:
    explicit NewAccount(QWidget *parent = 0);
    ~NewAccount();

private slots:
    void on_RegisterButton_clicked();

    void on_CancelButton_clicked();

    bool confirm_password_check();

    void on_ConfirmPasswordBox_textEdited(const QString &arg1);

    bool createConnection();

    //void createPersonTable(int M_id);
private:
    Ui::NewAccount *ui;
};

#endif // NEWACCOUNT_H
