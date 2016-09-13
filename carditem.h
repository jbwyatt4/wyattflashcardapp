#ifndef CARDITEM_H
#define CARDITEM_H

#include <QMetaType>
#include <QString>

class CardItem
{
public:
    CardItem();
    QString get_card_front();
    QString get_card_back();
    void set_front_back();

private:
    QString front;
    QString back;
};

Q_DECLARE_METATYPE(CardItem)

#endif // CARDITEM_H
