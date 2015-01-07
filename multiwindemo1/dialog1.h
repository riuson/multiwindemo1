#ifndef DIALOG1_H
#define DIALOG1_H

#include <QDialog>

namespace Ui {
class Dialog1;
}

class DialogsKeeper;

class Dialog1 : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog1(QWidget *parent = 0);
    ~Dialog1();

private slots:
    void on_pushButton_1_clicked();

private:
    Ui::Dialog1 *ui;
    DialogsKeeper *mDialogs;
};

#endif // DIALOG1_H
