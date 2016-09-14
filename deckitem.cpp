#include "deckitem.h"

DeckItem::DeckItem()
{
// qt seems to require a default cosnturcctor or I just dont remember c++
}

DeckItem::DeckItem(QString name)
{
    this->name = name;
}

QString DeckItem::get_name()
{
    return name;
}
