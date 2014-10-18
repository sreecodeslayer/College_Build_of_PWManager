#ifndef DELENTRY_H
#define DELENTRY_H

#include <QDialog>

namespace Ui {
class DelEntry;
}

class DelEntry : public QDialog
{
    Q_OBJECT

public:
    explicit DelEntry(QWidget *parent = 0);
    ~DelEntry();

private:
    Ui::DelEntry *ui;
};

#endif // DELENTRY_H
