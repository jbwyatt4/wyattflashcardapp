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

void CardViewer::receiveData(DeckItem * l) {
    clearData();
    QVectorIterator<CardItem *> i(l->cardList);
    while(i.hasNext()) {
        cardList.addItem( i.next() );
    }

    // 0 case
    if (cardList.count() < 1) {
        ui->ViewerDisplay->setText(tr("No cards"));
        updateMyDisplay();
        flipActiveButtons(false);
    // n > 1 case
    } else {
        nextCard();
    }
}

CardItem * CardViewer::getCurrentCard(int i) {
    QListWidgetItem * ci = NULL;
    ci = cardList.takeItem(i);
    return dynamic_cast<CardItem*>(ci);
}

void CardViewer::clearData() {

}

// instead of shuffling, just pick at random
int CardViewer::pickRandom() {
    srand ( time(NULL) );

    if (cardList.count() < 1) {
        return -1;
    }

    int count = this->cardList.count();
    return rand() % count;
}

/**
 * @brief CardViewer::setCurrentCard
 * @param ci
 *
 * Assumes ci exists
 */
void CardViewer::setCurrentCard(CardItem * ci) {
    QString s;
    s = ci->get_card_front();
    setCardText();
    cardItem = ci;
}

void CardViewer::flipCard() {
    isFrontShowing = !isFrontShowing;
}

/**
 * @brief CardViewer::on_nextButton_clicked
 * We assume this button will not be clicked if there are no cards left
 */
void CardViewer::on_nextButton_clicked()
{
    if(cardList.count() < 1) {
        // print "No More Cards" message
        QMessageBox msgBox;
        msgBox.setText(tr("No more cards."));
        msgBox.exec();
        // exit
        this->close();
    } else {
        nextCard();
    }
}

void CardViewer::updateButtons() {
    if(!hasCards() || cardItem == NULL) {
        flipActiveButtons(false);
    }
    if(hasCards()) {
        flipActiveButtons(true);
    }
}

/**
 * @brief CardViewer::updateMyDisplayButtons
 *
 * Updates both the display and buttons
 */
void CardViewer::updateMyDisplay() {
    ui->cards_left_indicator->setText(QString::number(cardList.count()));
}

bool CardViewer::hasCards() {
    if (cardList.count() > 0) {
        return true;
    } else {
        return false;
    }
}

void CardViewer::flipActiveButtons(bool buttonStatus) {
    buttonStatus = !buttonStatus;

    ui->shuffleButton->setDisabled(buttonStatus);
    ui->flipButton->setDisabled(buttonStatus);
    ui->nextButton->setDisabled(buttonStatus);
}

/**
 * Checks if back or front is set
 */
void CardViewer::setCardText() {
    if(isFrontShowing) {
        ui->ViewerDisplay->setText(this->cardItem->get_card_front());
    } else {
        ui->ViewerDisplay->setText(this->cardItem->get_card_back());
    }
}

void CardViewer::reject()
{
    //clearData();
    QDialog::reject();
}

void CardViewer::on_flipButton_clicked()
{
    isFrontShowing = !isFrontShowing;
    setCardText();
}

void CardViewer::on_shuffleButton_clicked()
{
    cardList.addItem( this->cardItem );
    nextCard();
}

void CardViewer::nextCard() {
    int i = pickRandom();
    cardNumber = i;
    cardItem = getCurrentCard(i);
    isFrontShowing = true;
    setCurrentCard(cardItem);
    updateMyDisplay();
}
