#ifndef CARDVIEWER_H
#define CARDVIEWER_H

#include <QDialog>

namespace Ui {
class CardViewer;
}

class CardViewer : public QDialog
{
    Q_OBJECT

public:
    explicit CardViewer(QWidget *parent = 0);
    ~CardViewer();

private slots:
    void on_leaveButton_clicked();

private:
    Ui::CardViewer *ui;
    bool isFrontShowing;
};

#endif // CARDVIEWER_H
