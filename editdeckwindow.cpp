#include "editdeckwindow.h"
#include "ui_editdeckwindow.h"
#include "carditem.h"

EditDeckWindow::EditDeckWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditDeckWindow)
{
    ui->setupUi(this);
    connect(&addCardDialog, SIGNAL(sendAddCardData(QStringList)), this, SLOT(receiveAddCardData(QStringList)));

}

EditDeckWindow::~EditDeckWindow()
{
    disconnect(&addCardDialog, SIGNAL(sendAddCardData(QStringList)), this, SLOT(receiveAddCardData(QStringList)));
    delete ui;
}

void EditDeckWindow::editOpenScreen(QListWidgetItem *item)
{
    (void)item; //suppress unused variable warning
    // warning, do not change order of setModal and then show below or the dialog will be behind
    // editdeckwindow
    addCardDialog.setModal(true);
    addCardDialog.show(); //don't know why
}

void EditDeckWindow::on_addCardButton_clicked()
{
    // warning, do not change order of setModal and then show below or the dialog will be behind
    // editdeckwindow
    addCardDialog.setModal(true);
    addCardDialog.show(); //don't know why
}

void EditDeckWindow::on_pushButton_clicked()
{
    close();
}

void EditDeckWindow::receiveData(QListWidgetItem * q) { // from MainWindow
    this->currentItem = q;
    DeckItem d = q->data(Qt::UserRole).value<DeckItem>();
    this->setWindowTitle(d.get_name());
}

void EditDeckWindow::receiveAddCardData(QStringList sl) {

    CardItem * card = new CardItem(sl[0], sl[1]);
    ui->cardListWidget->addItem(card);
}
