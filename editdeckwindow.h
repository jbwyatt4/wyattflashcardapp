#ifndef EDITDECKWINDOW_H
#define EDITDECKWINDOW_H

#include <QDialog>
#include <QListWidget>
#include <QListWidgetItem>
#include <QString>
#include <QVector>

namespace Ui {
class EditDeckWindow;
}

class EditDeckWindow : public QDialog
{
    Q_OBJECT

public:
    explicit EditDeckWindow(QWidget *parent = 0);
    ~EditDeckWindow();

public slots:
    void editOpenScreen(QListWidgetItem *item);

private slots:
    void on_addCardButton_clicked();

    void on_pushButton_clicked();

    void receiveData(QListWidgetItem *q);


private:
    Ui::EditDeckWindow *ui;
};

#endif // EDITDECKWINDOW_H
