#include "cardviewer.h"
#include "ui_cardviewer.h"

CardViewer::CardViewer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CardViewer)
{
    ui->setupUi(this);
    isFrontShowing = true;
}

CardViewer::~CardViewer()
{
    delete ui;
}

void CardViewer::on_leaveButton_clicked()
{
    this->close();
}
