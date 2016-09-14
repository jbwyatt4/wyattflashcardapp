#ifndef DECKITEM_H
#define DECKITEM_H

#include <QMetaType>
#include <QString>
#include <QVector>
#include <QListWidgetItem>

// where I got the info for using qvariant with qlistwidgetitem
// http://www.herculesoft.com/blog/add-extra-data-on-qlistwidgetitem-with-its-setdata.html

class DeckItem
{
public:
    DeckItem();
    DeckItem(QString name);
    QString get_name();

    QVector<QListWidgetItem> cardList;  // dynamic array that holds all the cards in a deck
 private:
    QString name;
};

Q_DECLARE_METATYPE(DeckItem)


#endif // DECKITEM_H
