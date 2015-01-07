#include "dialog1.h"
#include "ui_dialog1.h"
#include "dialogskeeper.h"
#include "dialog2.h"

Dialog1::Dialog1(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog1)
{
    ui->setupUi(this);

    this->mDialogs = new DialogsKeeper(this);
}

Dialog1::~Dialog1()
{
    delete ui;
    delete this->mDialogs;
}

void Dialog1::on_pushButton_1_clicked()
{
    QDialog *dialog = new Dialog2();
    this->mDialogs->addDialog(dialog);
    dialog->setWindowFlags(Qt::WindowMinMaxButtonsHint | Qt::WindowCloseButtonHint);
    dialog->show();
}
