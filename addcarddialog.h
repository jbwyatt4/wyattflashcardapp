#ifndef ADDCARDDIALOG_H
#define ADDCARDDIALOG_H

#include <QDialog>

namespace Ui {
class AddCardDialog;
}

class AddCardDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddCardDialog(QWidget *parent = 0);
    ~AddCardDialog();

    void clearLineEdits();

signals:
    void sendAddCardData(QStringList sl);

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

    void receiveCardData(QStringList sl);


private:
    Ui::AddCardDialog *ui;
};

#endif // ADDCARDDIALOG_H
