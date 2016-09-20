#ifndef CARDITEM_H
#define CARDITEM_H

#include <QMetaType>
#include <QString>
#include <QVector>
#include <QListWidgetItem>

class CardItem
{
public:
    QVector<QListWidgetItem> cardList;

    CardItem();
    ~CardItem();
    QString get_card_front();
    QString get_card_back();
    void set_front_back(QString front, QString back);
    void deleteAllCards();

private:
    QString front;
    QString back;
};

Q_DECLARE_METATYPE(CardItem)

#endif // CARDITEM_H
