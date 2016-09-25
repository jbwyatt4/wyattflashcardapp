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

void CardViewer::receiveData(QVector<DeckItem *> l) {
    QVectorIterator<CardItem *> i(l.cardList);
    while(i.hasNext()) {
        cardList.append( i.next() );
    }

    //pickRandom();
}

void clearVector() {

}

// instead of shuffling, just pick at random
CardItem * CardViewer::pickRandom() {
    srand ( time(NULL) );

    if (cardList.isEmpty()) {
        return NULL;
    }

    CardItem * ci = NULL;
    int count = this->cardList.count();
    int i = rand() % count;
    ci = this->cardList.at(i);
    this->cardList.remove(i);
    return ci;
}

void CardViewer::flipCard() {
    isFrontShowing = !isFrontShowing;
}
