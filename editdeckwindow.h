#ifndef EDITDECKWINDOW_H
#define EDITDECKWINDOW_H

#include <QStyle>
#include <QDesktopWidget>
#include <QDesktopServices>
#include <QUrl>
#include <QListWidget>
#include <QListWidgetItem>
#include <QInputDialog>
#include <QMainWindow>
#include <QString>
#include <QVector>
#include <QMessageBox>
#include <QVectorIterator>

#include "addcarddialog.h"
#include "deckitem.h"
#include "carditem.h"

namespace Ui {
class EditDeckWindow;
}

class EditDeckWindow : public QDialog
{
    Q_OBJECT

public:
    bool buttonStatus;

    explicit EditDeckWindow(QWidget *parent = 0);
    ~EditDeckWindow();

    AddCardDialog addCardDialog;
    void checkButtons();
    int cards_amt();
    bool has_cards();
    void flipActiveButtons();
    void flipActiveButtons(bool buttonStatus);
    void clearData();

private slots:
    void editOpenScreen(QListWidgetItem *item);

    void on_addCardButton_clicked();

    void on_pushButton_clicked();

    void receiveData(DeckItem *q); // MainWindow to EditDeckWindow

    void receiveAddCardData(QStringList sl);

    void receiveEditCardData(QStringList sl);

    void on_editCardButton_clicked();

    void on_cardListWidget_itemClicked(QListWidgetItem *item);

signals:
    void sendEditCardDataToEdit(QStringList);

private:
    void reject();

    Ui::EditDeckWindow *ui;
    DeckItem * currentDeck = NULL;
    CardItem * itemSelected = NULL;


};

#endif // EDITDECKWINDOW_H
