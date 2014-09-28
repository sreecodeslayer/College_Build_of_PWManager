#ifndef ADDENTRY_H
#define ADDENTRY_H

#include <QDialog>
#include <QListWidgetItem>

namespace Ui {
class AddEntry;
}

class AddEntry : public QDialog
{
    Q_OBJECT

public:
    explicit AddEntry(QWidget *parent = 0);
    ~AddEntry();

private slots:
    void on_Ok_Button_clicked();

    void on_account_type_list_itemClicked(QListWidgetItem *item);

private:
    Ui::AddEntry *ui;
};

#endif // ADDENTRY_H
