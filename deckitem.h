#ifndef DECKITEM_H
#define DECKITEM_H

#include <QMetaType>
#include <QString>
#include <QVector>
#include <QListWidgetItem>

#include "carditem.h"

// where I got the info for using qvariant with qlistwidgetitem
// http://www.herculesoft.com/blog/add-extra-data-on-qlistwidgetitem-with-its-setdata.html

class DeckItem : public QListWidgetItem
{
public:
    //DeckItem();
    explicit DeckItem(const QString & name);
    QString get_name();

    QVector<CardItem> cardList;  // dynamic array that holds all the cards in a deck
 private:
    QString name;
};

#endif // DECKITEM_H
