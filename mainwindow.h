#ifndef MAINWINDOW_H
#define MAINWINDOW_H
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
#include <QDir>
#include <QtGlobal>
#include <QStandardPaths>
#include <QJsonObject>
#include <QFile>
#include <QJsonDocument>
#include <QDebug>
#include <QTextStream>
#include <QIODevice>

#include "aboutdialog.h"
#include "addcarddialog.h"
#include "editdeckwindow.h"
#include "deckitem.h"
#include "cardviewer.h"
#include "misc.h"

#define JW_DEBUG

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    bool buttonStatus;

    QVector<DeckItem *> deckCardList;  // dynamic array that holds all the decks

    DeckItem * itemSelected;

    EditDeckWindow edw;
    CardViewer cardViewer;

    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    DeckItem *addDeck(QString title);
    void removeDeck(DeckItem *item);

    bool has_decks();

    int decks_amt();

    void flipActiveButtons();
    void flipActiveButtons(bool buttonStatus);
    void checkButtons();

    void select_item(DeckItem *item);
    void deselect_item();

    void gotoEditDeckWindow(DeckItem *item);

    void saveDecks();
    void loadDecks();
    bool checkFolder(QString path);
    QString dataLocation();
    bool checkForDuplicateDeck(QString text);


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

    void on_renameDeckButton_clicked();

signals:
    void get_itemselected(DeckItem *);
    void runCardViewer(DeckItem *);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
