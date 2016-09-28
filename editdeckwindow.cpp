#include "editdeckwindow.h"
#include "ui_editdeckwindow.h"

EditDeckWindow::EditDeckWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditDeckWindow)
{
    buttonStatus = false;
    ui->setupUi(this);
    // get data from addCardDialog
    connect(&addCardDialog, SIGNAL(sendAddCardData(QStringList)), this, SLOT(receiveAddCardData(QStringList)));
    connect(&addCardDialog, SIGNAL(sendEditCardData(QStringList)), this, SLOT(receiveEditCardData(QStringList)));
    // send data to addCardDialog
    connect(this, SIGNAL(sendEditCardDataToEdit(QStringList)), &addCardDialog, SLOT(receiveCardData(QStringList)));

    checkButtons();

}

EditDeckWindow::~EditDeckWindow()
{
    disconnect(&addCardDialog, SIGNAL(sendAddCardData(QStringList)), this, SLOT(receiveAddCardData(QStringList)));
    disconnect(&addCardDialog, SIGNAL(sendEditCardData(QStringList)), this, SLOT(receiveEditCardData(QStringList)));
    disconnect(this, SIGNAL(sendEditCardDataToEdit(QStringList)), &addCardDialog, SLOT(receiveCardData(QStringList)));

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
    clearData();
}

void EditDeckWindow::receiveData(DeckItem *q) { // from MainWindow
    this->currentDeck = q;
    this->setWindowTitle(this->currentDeck->get_name());
    ui->cardListWidget->clear();

    QVectorIterator<CardItem *> i(this->currentDeck->cardList);
    while(i.hasNext()) {
        this->ui->cardListWidget->addItem(i.next());
    }
    // because buttons are grayed out when none is selected do not have to select list item widget
}

void EditDeckWindow::receiveAddCardData(QStringList sl) {

    CardItem * card = new CardItem(sl[0], sl[1]);
    this->itemSelected = card;

    this->currentDeck->cardList.append(card);

    ui->cardListWidget->addItem(card);
    checkButtons();
    ui->cardListWidget->setCurrentItem(card);
}

void EditDeckWindow::receiveEditCardData(QStringList sl) {

    this->ui->cardListWidget->setCurrentItem(this->itemSelected);
    this->ui->cardListWidget->takeItem(this->ui->cardListWidget->currentRow());
    //this->currentDeck->itemSelected;
    this->itemSelected->set_front_back(sl[0], sl[1]);
    this->itemSelected->setText(sl[0]);

    // have to remove and readd element? I think you should seek help on irc for this one
    ui->cardListWidget->addItem(this->itemSelected);
    checkButtons();
    ui->cardListWidget->setCurrentItem(this->itemSelected);
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
    if (this->currentDeck == NULL) {
        return 0;
    } else {
        return this->currentDeck->cardList.count();
    }

}

void EditDeckWindow::on_editCardButton_clicked()
{
    QStringList sl;
    sl.append(this->itemSelected->get_card_front());
    sl.append(this->itemSelected->get_card_back());
    emit(sendEditCardDataToEdit(sl));
    addCardDialog.setModal(true);
    addCardDialog.show(); //don't know why
}

void EditDeckWindow::clearData() {
    // do not use, deletes all data in the reference
    //this->ui->cardListWidget->clear();

    for(; this->ui->cardListWidget->count() > 0 ;) {
        this->ui->cardListWidget->takeItem(0);
    }
}

// Overrides close button provided by OS
void EditDeckWindow::reject()
{
    clearData();
    QDialog::reject();

    // message box ask to close, likely wont use in this program
    /*QMessageBox::StandardButton resBtn = QMessageBox::Yes;
    if (changes) {
        resBtn = QMessageBox::question( this, APP_NAME,
                                        tr("Are you sure?\n"),
                                        QMessageBox::Cancel | QMessageBox::No | QMessageBox::Yes,
                                        QMessageBox::Yes);
    }
    if (resBtn == QMessageBox::Yes) {
        QDialog::reject();
    }*/
}
