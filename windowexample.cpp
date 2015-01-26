#include "windowexample.h"
#include "ui_windowexample.h"

WindowExample::WindowExample(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WindowExample)
{
    ui->setupUi(this);
    this->setAttribute(Qt::WA_DeleteOnClose);
}

WindowExample::~WindowExample()
{
    delete ui;
}

QWidget *WindowExample::widget()
{
    return this;
}

QString WindowExample::windowTitle() const
{
    return QWidget::windowTitle();
}

void WindowExample::on_pushButtonOpenNewDialog_clicked()
{
    WindowExample *w = new WindowExample();
    emit this->windowCreated(w);
}

void WindowExample::on_pushButtonClose_clicked()
{
    emit this->windowClosed(this);
}
