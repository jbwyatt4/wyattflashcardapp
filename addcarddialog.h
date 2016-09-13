#ifndef ADDCARDDIALOG_H
#define ADDCARDDIALOG_H

#include <QMainWindow>

namespace Ui {
class AddCardDialog;
}

class AddCardDialog : public QMainWindow
{
    Q_OBJECT

public:
    explicit AddCardDialog(QWidget *parent = 0);
    ~AddCardDialog();

private:
    Ui::AddCardDialog *ui;
};

#endif // ADDCARDDIALOG_H
