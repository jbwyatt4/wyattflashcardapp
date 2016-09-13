#ifndef DECKITEM_H
#define DECKITEM_H

#include <QMetaType>
#include <QString>

// where I got the info for using qvariant with qlistwidgetitem
// http://www.herculesoft.com/blog/add-extra-data-on-qlistwidgetitem-with-its-setdata.html

class DeckItem
{
public:
    DeckItem();
    QString get_name();

 private:
};

Q_DECLARE_METATYPE(DeckItem)


#endif // DECKITEM_H
