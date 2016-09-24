#ifndef CARDITEM_H
#define CARDITEM_H

#include <QString>
#include <QVector>
#include <QListWidgetItem>

class CardItem : public QListWidgetItem
{
public:
    CardItem();
    explicit CardItem(QString nfront, QString nback);
    ~CardItem();
    QString get_card_front();
    QString get_card_back();
    void set_front_back(QString front, QString back);

private:
    QString front;
    QString back;
};

#endif // CARDITEM_H
