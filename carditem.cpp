#include "carditem.h"

CardItem::CardItem(const QString & nfront, const QString & nback)
{
    set_front_back(nfront, nback);
    QListWidgetItem(nfront.toStdString().data()); //complains about a shadow parameter without converting to char array, means it's using a different constructor, give a c char array
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

void CardItem::set_front_back(const QString &front, const QString &back)
{
    this->front = front;
    this->back = back;
}

