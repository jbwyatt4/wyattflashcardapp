#include "mainwindow.h"
#include "ui_mainwindow.h"

// see this to setup an icon in qlistwidgetview
// https://www.youtube.com/watch?v=2YRAJt-LbkM

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
// warning, goes to left monitor on two monitor setup
this->setGeometry(
    QStyle::alignedRect(
        Qt::LeftToRight,
        Qt::AlignCenter,
        this->size(),
        qApp->desktop()->availableGeometry()
    )
);
  ui->setupUi(this);
  itemSelected = NULL;
  buttonStatus = false; // a variable for flipActiveButtons
  //default is true
  // if you dont have decks, disable buttons
  checkButtons();

  // edw is not a poniter, so use reference
  connect(this, SIGNAL(get_itemselected(DeckItem *)), &edw, SLOT(receiveData(DeckItem *)));
  connect(this, SIGNAL(runCardViewer(DeckItem *)), &cardViewer, SLOT(receiveData(DeckItem *)));

}

MainWindow::~MainWindow()
{
  disconnect(this, SIGNAL(get_itemselected(DeckItem *)), &edw, SLOT(receiveData(DeckItem *)));
  disconnect(this, SIGNAL(runCardViewer(DeckItem *)), &cardViewer, SLOT(receiveData(DeckItem *)));

  // Review, destructor is called on exiting program, confirmed with both Xbox and File->Quit
  // no need to list this function mutiple times
  saveDecks();

  delete ui;
}

void MainWindow::on_actionAbout_triggered()
{
  AboutDialog aboutDialog;
  aboutDialog.exec();
}

void MainWindow::on_actionQuit_triggered()
{
    close();
}

void MainWindow::on_actionHow_to_Use_triggered()
{
    QString link = "https://www.youtube.com/watch?v=VYwdcBxHobs";
    QDesktopServices::openUrl(QUrl(link));
}

void MainWindow::flipActiveButtons() {
    buttonStatus = !buttonStatus;
    flipActiveButtons(buttonStatus);
}

// flips the clickable status of certain buttons such as modify, delete, etc
void MainWindow::flipActiveButtons(bool buttonStatus) {
    buttonStatus = !buttonStatus;

    ui->deleteButton->setDisabled(buttonStatus);
    ui->modifyDeckButton->setDisabled(buttonStatus);
    ui->runDeckButton->setDisabled(buttonStatus);
    ui->addCardDeckButton->setDisabled(buttonStatus);
    ui->renameDeckButton->setDisabled(buttonStatus);
}

void MainWindow::checkButtons() {
    if(!has_decks() || itemSelected == NULL) {
        flipActiveButtons(false);
    }
    if(has_decks()) {
        flipActiveButtons(true);
    }
}

void MainWindow::addDeck(QString title)
{
    DeckItem * deck = new DeckItem(title);
    ui->deckListWidget->addItem(deck);
    this->deckCardList.append(deck);
    ui->deckListWidget->setCurrentItem(deck);
    select_item(deck);
}

void MainWindow::removeDeck(DeckItem *item)
{
    // code to handle memory deletion of the flashcards should be in destructor

    // FUTURE put code to delete json file here

    deselect_item();
    // not the correct way to remove an item, qt will try to manage it, it isn't good at it with inherited objects
    // in cardlist in the deck, when you delete a card it leaves behind a dead object with qstrings set to "" if you use the below method for cards, untested for the decks in decklist
    //ui->deckListWidget->removeItemWidget(item);
    // first set the current item to get the row
    this->ui->deckListWidget->setCurrentItem(item);
    // then have qt pop off the object from the list, we already have the reference so we don't ahve to catch it
    this->ui->deckListWidget->takeItem(this->ui->deckListWidget->currentRow());
    // now delete
    delete item;
    this->itemSelected = NULL;
}


// returns true if more than 0 decks
bool MainWindow::has_decks()
{
    if (decks_amt() > 0) {
        return true;
    } else {
        return false;
    }
}

int MainWindow::decks_amt()
{
    return this->deckCardList.count();
}

void MainWindow::select_item(DeckItem *item)
{
    itemSelected = item;
    checkButtons();
}

// Called when we delete
void MainWindow::deselect_item()
{
    itemSelected = NULL;
    checkButtons();
}

void MainWindow::gotoEditDeckWindow(DeckItem *item) {

    emit(get_itemselected(item));
    edw.setModal(true);
    this->hide();
    edw.exec();
    this->show();
}

void MainWindow::on_runDeckButton_clicked()
{
    emit(runCardViewer(itemSelected));
    cardViewer.setModal(true);
    cardViewer.exec();

}

void MainWindow::on_addDeckButton_clicked()
{
    bool ok;

    QString text = QInputDialog::getText(this, tr("Type Name"),
                     tr("New Flash Card Deck Name:"), QLineEdit::Normal,
                     NULL, &ok);
    if(ok) {
      // handle no input
      if(text.isEmpty()) {
          QMessageBox msgBox;
          msgBox.setText(tr("Please put in a name."));
          msgBox.exec();
      } else {
        addDeck(text);
      }
    } else {
    //not sure how to handle not ok
    }
}

void MainWindow::on_deckListWidget_itemClicked(QListWidgetItem *item)
{
    if (item != NULL) {
        DeckItem *a = dynamic_cast<DeckItem*>(item);
        select_item(a);
    }
}

void MainWindow::on_deleteButton_clicked()
{
    removeDeck(this->itemSelected);
    flipActiveButtons(false); // deselect buttons after delete
}

void MainWindow::on_addCardDeckButton_clicked()
{
    gotoEditDeckWindow(this->itemSelected);
}

void MainWindow::on_modifyDeckButton_clicked()
{
    gotoEditDeckWindow(this->itemSelected);
}

void MainWindow::on_actionSave_triggered()
{

}

void MainWindow::on_renameDeckButton_clicked()
{
    bool ok;

    QString text = QInputDialog::getText(this, tr("Type Name"),
                     tr("New Flash Card Deck Name:"), QLineEdit::Normal,
                     NULL, &ok);
    if(ok) {
      // handle no input
      if(text.isEmpty()) {
          QMessageBox msgBox;
          msgBox.setText(tr("Please put in a name."));
          msgBox.exec();
      } else {
        this->itemSelected->setText(text);
      }
    } else {
    //not sure how to handle not ok
    }
}

/**
 * @brief MainWindow::checkFolder
 * @param path
 *
 * Checks and adds a folder if not there. OS dependent. true is success
 */
bool MainWindow::checkFolder(QString path) {
    QDir dir(path);
    if (!dir.exists()) {
        // returns true on success
        return dir.mkpath(".");
    }
    return true;
}

void MainWindow::saveDecks() {
    //QMessageBox msgBox;
    //msgBox.setText(tr( QStandardPaths.displayName(QStandardPaths.standardLocations(9) ));
    //msgBox.exec();
    bool result = false;
    result = checkFolder(dataLocation());
    result = checkFolder(dataLocation() + "/decks");

    if (!result) {
        QMessageBox msgBox;
        msgBox.setText(tr("ERROR: Unable to save to file or directory, decks not saved! Please check your write permissions."));
        msgBox.exec();

    }
}

QString MainWindow::dataLocation() {
    #ifdef Q_OS_LINUX
    return QString(QDir::homePath() + "/.local/share/WyattTechCourses/WyattSimpleFlashcardApp");
    #endif
    #ifdef Q_OS_WIN
    return QString(QDir::homePath() + "/AppData/Local/WyattTechCourses/WyattSimpleFlashcardApp");
    #endif

}
