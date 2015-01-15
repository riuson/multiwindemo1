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

    QString windowTitle() const;

private:
    Ui::WindowExample *ui;
};

#endif // WINDOWEXAMPLE_H
