#ifndef EDITDECKWINDOW_H
#define EDITDECKWINDOW_H

#include <QDialog>

namespace Ui {
class EditDeckWindow;
}

class EditDeckWindow : public QDialog
{
    Q_OBJECT

public:
    explicit EditDeckWindow(QWidget *parent = 0);
    ~EditDeckWindow();

private:
    Ui::EditDeckWindow *ui;
};

#endif // EDITDECKWINDOW_H
