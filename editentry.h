#ifndef EDITENTRY_H
#define EDITENTRY_H

#include <QDialog>
#include <QSqlDatabase>
#include <QListWidgetItem>

namespace Ui {
class EditEntry;
}

class EditEntry : public QDialog
{
    Q_OBJECT

public:
    explicit EditEntry(QWidget *parent = 0);
    ~EditEntry();
    QSqlDatabase db;

private slots:
    void on_EditButton_clicked();

    bool createConnection();

    void on_account_type_list_itemClicked(QListWidgetItem *item);

    QString encr_Password(QString acc_pass);

    QString decr_Password(QByteArray encr_pass);

    void on_CancelButton_clicked();

private:
    Ui::EditEntry *ui;
};

#endif // EDITENTRY_H
