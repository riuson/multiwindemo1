#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "dialog1.h"
#include "dialog2.h"
#include "dialog3.h"
#include "dialogskeeper.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->mDialogs = new DialogsKeeper(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    delete this->mDialogs;
}

void MainWindow::on_pushButton_1_clicked()
{
    QDialog *dialog = new Dialog1();
    this->mDialogs->addDialog(dialog);
    dialog->setWindowFlags(Qt::WindowMinMaxButtonsHint | Qt::WindowCloseButtonHint);
    dialog->show();
}

void MainWindow::on_pushButton_2_clicked()
{
    QDialog *dialog = new Dialog2();
    this->mDialogs->addDialog(dialog);
    dialog->setWindowFlags(Qt::WindowMinMaxButtonsHint | Qt::WindowCloseButtonHint);
    dialog->show();
}

void MainWindow::on_pushButton_3_clicked()
{
    QDialog *dialog = new Dialog3();
    this->mDialogs->addDialog(dialog);
    dialog->setWindowFlags(Qt::WindowMinMaxButtonsHint | Qt::WindowCloseButtonHint);
    dialog->show();
}
