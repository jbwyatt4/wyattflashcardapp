#ifndef EDITDECKWINDOW_H
#define EDITDECKWINDOW_H

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
#include <QString>
#include <QVector>
#include <QMessageBox>

namespace Ui {
class EditDeckWindow;
}

class EditDeckWindow : public QDialog
{
    Q_OBJECT

public:
    explicit EditDeckWindow(QWidget *parent = 0);
    ~EditDeckWindow();

    AddCardDialog addCardDialog;

private slots:
    void editOpenScreen(QListWidgetItem *item);

    void on_addCardButton_clicked();

    void on_pushButton_clicked();

    void receiveData(QListWidgetItem *q); // MainWindow to EditDeckWindow

    //void receiveAddCardData(QStringList sl ); // AddCardDialog to EditDeckWindow

    void receiveAddCardData(QStringList sl);
private:
    Ui::EditDeckWindow *ui;
    QListWidgetItem * currentItem = NULL;

};

#endif // EDITDECKWINDOW_H
