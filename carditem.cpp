#include "carditem.h"

CardItem::CardItem()
{}

// delete all custom items
CardItem::~CardItem(){
    void deleteAllCards();
}

QString CardItem::get_card_front()
{
    return front;
}

QString CardItem::get_card_back()
{
    return back;
}

void CardItem::set_front_back(QString front, QString back)
{
    this->front = front;
    this->back = back;
}

void CardItem::deleteAllCards() {

}
