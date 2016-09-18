
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
  itemselected = NULL;
  buttonStatus = false; // a variable for flipActiveButtons
  //default is true
  // if you dont have decks, disable buttons
  checkButtons();

  // edw is not a poniter, so use reference
  connect(this, SIGNAL(get_itemselected(QListWidgetItem *)), &edw, SLOT(receiveData(QListWidgetItem *)));

}

MainWindow::~MainWindow()
{
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
    ui->deleteButton->setDisabled(!buttonStatus);
    ui->modifyDeckButton->setDisabled(!buttonStatus);
    ui->runDeckButton->setDisabled(!buttonStatus);
    ui->addCardDeckButton->setDisabled(!buttonStatus);
}

void MainWindow::checkButtons() {
    if(!has_decks() || itemselected == NULL) {
        flipActiveButtons(false);
    }
    if(has_decks()) {
        flipActiveButtons(true);
    }
}

void MainWindow::addDeck(QString title)
{
    QVariant qv;
    DeckItem d(title);
    QListWidgetItem *item = new QListWidgetItem();
    item->setText(title);
    qv.setValue(d);
    item->setData(Qt::UserRole, qv);
    ui->deckListWidget->addItem(item);

    this->deckCardList.append(*item);

    //DeckItem e = item->data(Qt::UserRole).value<DeckItem>();

    return;
}

void MainWindow::removeDeck(QListWidgetItem *item)
{
    // code to handle memory deletion of the flashcards should be in destructor

    // FUTURE put code to delete json file here

    deselect_item();
    ui->deckListWidget->removeItemWidget(item);
    delete item;
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

void MainWindow::select_item(QListWidgetItem *item)
{
    itemselected = item;
    checkButtons();
}

// Called when we delete
void MainWindow::deselect_item()
{
    itemselected = NULL;
    checkButtons();
}

void MainWindow::gotoEditDeckWindow(QListWidgetItem *item) {

    emit(get_itemselected(item));
    edw.setModal(true);
    this->hide();
    edw.exec();
    this->show();
}

void MainWindow::on_runDeckButton_clicked()
{

    //deckview dv;
    //dv.setModal(true);
    //dv.exec();
    //or to use heap memory
    //deckview *dv = new deckview(this);
    //dv->show();

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
          msgBox.setText("Please put in a name.");
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
        select_item(item);
    }
}

void MainWindow::on_deleteButton_clicked()
{
    removeDeck(this->itemselected);
}

void MainWindow::on_addCardDeckButton_clicked()
{
    gotoEditDeckWindow(this->itemselected);
}

void MainWindow::on_modifyDeckButton_clicked()
{
    gotoEditDeckWindow(this->itemselected);
}

void MainWindow::on_actionSave_triggered()
{

}
