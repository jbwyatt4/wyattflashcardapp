#include "editdeckwindow.h"
#include "ui_editdeckwindow.h"
#include "carditem.h"

EditDeckWindow::EditDeckWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditDeckWindow)
{
    buttonStatus = false;
    ui->setupUi(this);
    connect(&addCardDialog, SIGNAL(sendAddCardData(QStringList)), this, SLOT(receiveAddCardData(QStringList)));
    checkButtons();

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
    this->itemSelected = q;
    //DeckItem * d = &q->data(Qt::UserRole).value<DeckItem>();
    //this->currentDeck = d;
    //this->setWindowTitle(d->get_name());
    // we may also need to select the item in the list widget to avoid bugs with the user clicking
    // not sure how to do this
}

void EditDeckWindow::receiveAddCardData(QStringList sl) {

    CardItem * card = new CardItem(sl[0], sl[1]);
    this->itemSelected = card;
    //this->cardList.append(*card);
    ui->cardListWidget->addItem(card);
    checkButtons();
}

void EditDeckWindow::checkButtons() {
    if(!has_cards() || itemSelected == NULL) {
        flipActiveButtons(false);
    }
    if(has_cards()) {
        flipActiveButtons(true);
    }
}

void EditDeckWindow::flipActiveButtons() {
    buttonStatus = !buttonStatus;
    flipActiveButtons(buttonStatus);
}

void EditDeckWindow::flipActiveButtons(bool buttonStatus) {
    buttonStatus = !buttonStatus;

    ui->editCardButton->setDisabled(buttonStatus);
    ui->deleteCardButton->setDisabled(buttonStatus);
}

bool EditDeckWindow::has_cards()
{
    if (cards_amt() > 0) {
        return true;
    } else {
        return false;
    }
}

int EditDeckWindow::cards_amt()
{
    return 0;//this->cardList.count();
}
