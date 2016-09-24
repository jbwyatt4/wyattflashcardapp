#ifndef DECKITEM_H
#define DECKITEM_H

#include <QMetaType>
#include <QString>
#include <QVector>
#include <QListWidgetItem>

#include "carditem.h"

class DeckItem : public QListWidgetItem
{
public:
    DeckItem();
    explicit DeckItem(QString name);
    ~DeckItem();
    QString get_name();

    QVector<CardItem *> cardList;  // dynamic array that holds all the cards in a deck

    void removeAllCards();
 private:
    QString name;
};

#endif // DECKITEM_H
