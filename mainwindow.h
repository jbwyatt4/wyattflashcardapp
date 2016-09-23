#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "aboutdialog.h"
#include "addcarddialog.h"
#include "editdeckwindow.h"
#include "deckitem.h"
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

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    bool buttonStatus;

    QVector<QListWidgetItem> deckCardList;  // dynamic array that holds all the decks

    QListWidgetItem * itemSelected;

    EditDeckWindow edw;

    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void addDeck(QString title);
    void removeDeck(QListWidgetItem *item);

    bool has_decks();

    int decks_amt();

    void flipActiveButtons();
    void flipActiveButtons(bool buttonStatus);
    void checkButtons();

    void select_item(QListWidgetItem *item);
    void deselect_item();

    void gotoEditDeckWindow(QListWidgetItem *item);

private slots:
    void on_actionAbout_triggered();

    void on_actionQuit_triggered();

    void on_runDeckButton_clicked();

    void on_addDeckButton_clicked();

    void on_actionHow_to_Use_triggered();

    void on_deckListWidget_itemClicked(QListWidgetItem *item);

    void on_deleteButton_clicked();

    void on_addCardDeckButton_clicked();

    void on_modifyDeckButton_clicked();

    void on_actionSave_triggered();

signals:
    void get_itemselected(QListWidgetItem *);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
