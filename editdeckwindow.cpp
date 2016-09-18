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

    //this->hide();//dont really need to hide it
    //addCardDialog.exec();

}

void EditDeckWindow::on_addCardButton_clicked()
{
    addCardDialog.setModal(true);
    addCardDialog.show();
}

void EditDeckWindow::on_pushButton_clicked()
{
    close();
}

void EditDeckWindow::receiveData(QListWidgetItem * q) {
    this->currentItem = q;
    DeckItem d = q->data(Qt::UserRole).value<DeckItem>();
    this->setWindowTitle(d.get_name());
}

//void receiveAddCardData(QStringList sl) {
//    QVariant qv;
    /*CardItem d(title);
    QListWidgetItem *item = new QListWidgetItem();
    item->setText(title);
    qv.setValue(d);
    item->setData(Qt::UserRole, qv);
    ui->deckListWidget->addItem(item);*/
//}
