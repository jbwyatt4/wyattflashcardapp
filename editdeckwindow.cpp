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
