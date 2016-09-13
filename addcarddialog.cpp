#include "addcarddialog.h"
#include "ui_addcarddialog.h"

AddCardDialog::AddCardDialog(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AddCardDialog)
{
    ui->setupUi(this);
}

AddCardDialog::~AddCardDialog()
{
    delete ui;
}
