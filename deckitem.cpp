#include "deckitem.h"

DeckItem::DeckItem()
{
// qt seems to require a default consturcctor or I just dont remember c++
}

DeckItem::DeckItem(QString name)
{
    // please do not try setTitleText in the constructor.
    this->name = name;
    QListWidgetItem(name.toStdString().data()); //complains about a shadow parameter without converting to char array, means it's using a different constructor, give a c char array
    this->setText(name);

}

DeckItem::~DeckItem() {
    removeAllCards();
}

void DeckItem::setTitleText(QString name) {
    this->name = name;
    this->setText(name);
}

QString DeckItem::get_name()
{
    return name;
}

/**
 * @brief DeckItem::removeAllCards
 * Deletes all cards by calling delete on them
 */
void DeckItem::removeAllCards() {
    /*QVector<CardItem>::iterator it = this->cardList.end();
    QVector<CardItem>::iterator end = this->cardList.begin();
    while(it != end) {
       //delete cardList.at(*it);
    }*/
}
