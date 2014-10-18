#ifndef EDITENTRY_H
#define EDITENTRY_H

#include <QDialog>

namespace Ui {
class EditEntry;
}

class EditEntry : public QDialog
{
    Q_OBJECT

public:
    explicit EditEntry(QWidget *parent = 0);
    ~EditEntry();

private:
    Ui::EditEntry *ui;
};

#endif // EDITENTRY_H
