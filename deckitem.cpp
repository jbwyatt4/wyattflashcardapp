#include "deckitem.h"

/*DeckItem::DeckItem()
{
// qt seems to require a default consturcctor or I just dont remember c++
}*/

DeckItem::DeckItem(const QString &name)
{
    this->name = name;
}

QString DeckItem::get_name()
{
    return name;
}
