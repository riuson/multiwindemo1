#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "dialog1.h"
#include "dialog2.h"
#include "dialog3.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    qDeleteAll(this->mDialogs);
}

void MainWindow::on_pushButton_1_clicked()
{
    QDialog *dialog = new Dialog1();
    this->mDialogs.append(dialog);
    dialog->setWindowFlags(Qt::WindowMinMaxButtonsHint | Qt::WindowCloseButtonHint);
    this->connect(dialog, SIGNAL(finished(int)), SLOT(dialog_finished(int)));
    dialog->show();
}

void MainWindow::on_pushButton_2_clicked()
{
    QDialog *dialog = new Dialog2();
    this->mDialogs.append(dialog);
    dialog->setWindowFlags(Qt::WindowMinMaxButtonsHint | Qt::WindowCloseButtonHint);
    this->connect(dialog, SIGNAL(finished(int)), SLOT(dialog_finished(int)));
    dialog->show();
}

void MainWindow::on_pushButton_3_clicked()
{
    QDialog *dialog = new Dialog3();
    this->mDialogs.append(dialog);
    dialog->setWindowFlags(Qt::WindowMinMaxButtonsHint | Qt::WindowCloseButtonHint);
    this->connect(dialog, SIGNAL(finished(int)), SLOT(dialog_finished(int)));
    dialog->show();
}

void MainWindow::dialog_finished(int result)
{
    QObject *obj = sender();
    QDialog *dialog = qobject_cast<QDialog *>(obj);

    if (this->mDialogs.contains(dialog)) {
        this->mDialogs.removeOne(dialog);
        delete dialog;
    }
}
