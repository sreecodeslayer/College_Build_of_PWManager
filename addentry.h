#ifndef ADDENTRY_H
#define ADDENTRY_H

#include <QDialog>
#include <QListWidgetItem>
#include <QSqlDatabase>
/*.#include <crypto++/aes.h>
#include <crypto++/modes.h>
#include <crypto++/filters.h>
#include <crypto++/hex.h>
#include <crypto++/sha.h>
#include <crypto++/md5.h>*/

namespace Ui {
class AddEntry;
}

class AddEntry : public QDialog
{
    Q_OBJECT

public:
    int current_user_id;
    explicit AddEntry(QWidget *parent = 0,int current_user=0);

    QString decrypt(const QString&);

    QString encrypt(const QString& );

    ~AddEntry();

    QSqlDatabase db;

private slots:    
    void on_Ok_Button_clicked();

    void on_account_type_list_itemClicked(QListWidgetItem *item);

    void on_Cancel_Button_clicked();

    QString encrPassword();

    QString decrPassword(QByteArray);

    bool createConnection();

private:
    Ui::AddEntry *ui;
};

#endif // ADDENTRY_H
