#include "decklist.h"
#include "ui_decklist.h"

DeckList::DeckList(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DeckList)
{
    ui->setupUi(this);
}

DeckList::~DeckList()
{
    delete ui;
}
