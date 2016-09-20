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

// used for editing
void AddCardDialog::receiveCardData(QStringList sl){
    ui->cardFront->setText(sl[0]);
    ui->cardBack->setText(sl[1]);
}

void AddCardDialog::on_buttonBox_accepted()
{
    QStringList sl;
    sl.append(ui->cardFront->text());
    sl.append(ui->cardBack->text());
    emit sendAddCardData(sl);
    close();
    clearLineEdits();
}

void AddCardDialog::on_buttonBox_rejected()
{
    close();
    clearLineEdits();
}

// dialog will keep the last input we gave it w/o this
void AddCardDialog::clearLineEdits() {
    ui->cardFront->setText("");
    ui->cardBack->setText("");
}
