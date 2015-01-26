#ifndef WINDOWEXAMPLE_H
#define WINDOWEXAMPLE_H

#include <QWidget>
#include "isubwindow.h"

namespace Ui {
class WindowExample;
}

class WindowExample : public QWidget, public ISubWindow
{
    Q_OBJECT
    Q_INTERFACES(ISubWindow)

public:
    explicit WindowExample(QWidget *parent = 0);
    ~WindowExample();

    QWidget *widget();
    QString windowTitle() const;

private:
    Ui::WindowExample *ui;

private slots:
    void on_pushButtonOpenNewDialog_clicked();

signals:
    void windowCreated(ISubWindow *widget);
    void windowClosed(ISubWindow *widget);
};

#endif // WINDOWEXAMPLE_H
