#include "windowexample.h"
#include "ui_windowexample.h"

WindowExample::WindowExample(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WindowExample)
{
    ui->setupUi(this);
}

WindowExample::~WindowExample()
{
    delete ui;
}

QString WindowExample::windowTitle() const
{
    return QWidget::windowTitle();
}
