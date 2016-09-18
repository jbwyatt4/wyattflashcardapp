#include "addcarddialog.h"
#include "ui_addcarddialog.h"

AddCardDialog::AddCardDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddCardDialog)
{
    ui->setupUi(this);
}

AddCardDialog::~AddCardDialog()
{
    delete ui;
}

void AddCardDialog::receiveCardData(QStringList sl){

}

void AddCardDialog::on_buttonBox_accepted()
{
    sendAddCardData();
    close();
}

void AddCardDialog::on_buttonBox_rejected()
{
    close();
}
