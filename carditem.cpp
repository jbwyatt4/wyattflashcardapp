#include "carditem.h"

CardItem::CardItem(QString front, QString back)
{
    set_front_back(front, back);
    QListWidgetItem(front);

}

// delete all custom items
CardItem::~CardItem(){

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

