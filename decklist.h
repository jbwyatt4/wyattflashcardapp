#ifndef DECKLIST_H
#define DECKLIST_H

#include <QDialog>

namespace Ui {
class DeckList;
}

class DeckList : public QDialog
{
    Q_OBJECT

public:
    explicit DeckList(QWidget *parent = 0);
    ~DeckList();

private slots:
    void on_pushButton_clicked();

private:
    Ui::DeckList *ui;
};

#endif // DECKLIST_H