#ifndef CARDVIEWER_H
#define CARDVIEWER_H

#include <QDialog>
#include <QVector>
#include <QVectorIterator>
#include <time.h>

#include "carditem.h"
#include "deckitem.h"

namespace Ui {
class CardViewer;
}

class CardViewer : public QDialog
{
    Q_OBJECT

public:
    explicit CardViewer(QWidget *parent = 0);
    ~CardViewer();
    void clearVector();
    CardItem * pickRandom();
    void flipCard();

private slots:
    void on_leaveButton_clicked();

    void receiveData(DeckItem *l);

private:
    Ui::CardViewer *ui;
    bool isFrontShowing;
    QVector<CardItem *> cardList;
};

#endif // CARDVIEWER_H
