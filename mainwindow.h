#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "aboutdialog.h"
#include "addcarddialog.h"
#include "deckitem.h"
#include <QStyle>
#include <QDesktopWidget>
#include <QDesktopServices>
#include <QUrl>
#include <QListWidget>
#include <QListWidgetItem>
#include <QInputDialog>
#include <QMainWindow>
#include <string>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    bool buttonStatus;

    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    int addDeck();

    bool has_decks();

    int decks_amt();

    void flipActiveButtons();

    void checkButtons();

private slots:
    void on_actionAbout_triggered();

    void on_actionQuit_triggered();

    void on_runDeckButton_clicked();

    void on_addDeckButton_clicked();

    void on_actionHow_to_Use_triggered();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
