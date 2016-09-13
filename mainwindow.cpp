
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
  buttonStatus = false; // a variable for flipActiveButtons
  //default is false because true disables buttons

  // if you dont have decks, disable buttons

  checkButtons();

  QVariant qv;
  DeckItem d;
  QListWidgetItem *item = new QListWidgetItem();
  item->setText("settext text");
  qv.setValue(d);
  item->setData(Qt::UserRole, qv);
  ui->deckListWidget->addItem(item);
}

MainWindow::~MainWindow()
{
  delete ui;
}

void MainWindow::on_actionAbout_triggered()
{
  AboutDialog aboutDialog2;
  aboutDialog2.exec();
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

// flips the clickable status of certain buttons such as modify, delete, etc
void MainWindow::flipActiveButtons() {
    buttonStatus = !buttonStatus;
    ui->deleteButton->setDisabled(buttonStatus);
    ui->modifyDeckButton->setDisabled(buttonStatus);
    ui->runDeckButton->setDisabled(buttonStatus);
}

void MainWindow::checkButtons() {
    if(!has_decks() && buttonStatus == false) {
        flipActiveButtons();
    }
    if(has_decks() && buttonStatus == true) {
        flipActiveButtons();
    }
}

int MainWindow::addDeck()
{
    return 0;
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
    return 0;
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

      } else {

      }
    } else {
    //not sure how to handle not ok
    }
    // if (ok && !text.isEmpty())
    //   {}
}
