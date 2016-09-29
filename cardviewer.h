#ifndef CARDVIEWER_H
#define CARDVIEWER_H

#include <QDialog>
#include <QVector>
#include <QVectorIterator>
#include <QMessageBox>
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
    void clearData();
    int pickRandom();
    void flipCard();
    void setCurrentCard(CardItem * ci);
    void updateMyDisplayButtons();
    bool hasCards();
    void flipActiveButtons(bool);
    CardItem * getCurrentCard(int i);
    void setCardText();
    void reject();
    void nextCard();

private slots:
    void on_leaveButton_clicked();

    void receiveData(DeckItem *l);

    void on_nextButton_clicked();

    void on_flipButton_clicked();

    void on_shuffleButton_clicked();

private:
    Ui::CardViewer *ui;
    bool isFrontShowing;
    QListWidget cardList;
    CardItem * cardItem = NULL;
    int cardNumber;
    bool buttonStatus;
};

#endif // CARDVIEWER_H
