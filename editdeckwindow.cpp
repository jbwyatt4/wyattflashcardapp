#include "editdeckwindow.h"
#include "ui_editdeckwindow.h"

EditDeckWindow::EditDeckWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditDeckWindow)
{
    ui->setupUi(this);

}

EditDeckWindow::~EditDeckWindow()
{
    delete ui;
}

void EditDeckWindow::editOpenScreen(QListWidgetItem *item)
{

}

void EditDeckWindow::on_addCardButton_clicked()
{

}

void EditDeckWindow::on_pushButton_clicked()
{
    close();
}

void EditDeckWindow::receiveData(QListWidgetItem * q) {
    this->setWindowTitle( q->data(Qt::UserRole).value );
}
