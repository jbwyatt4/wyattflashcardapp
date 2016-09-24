#include "carditem.h"

CardItem::CardItem()
{
// this needs to be defined for some reason for QT
}

CardItem::CardItem(QString nfront, QString nback)
{
    set_front_back(nfront, nback);
    QListWidgetItem(); //complains about a shadow parameter without converting to char array, means it's using a different constructor, give a c char array
    this->setText(nfront);

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

