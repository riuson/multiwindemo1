#ifndef ISUBWINDOW
#define ISUBWINDOW

#include <QString>
#include <QWidget>

class ISubWindow
{
public:
    virtual ~ISubWindow() {}
    virtual QWidget *widget() = 0;
    virtual QString windowTitle() const = 0;

signals:
    virtual void windowCreated(ISubWindow *window) = 0;
    virtual void windowClosed(ISubWindow *window) = 0;
};
Q_DECLARE_INTERFACE (ISubWindow,
                     "riuson.multiwindemo/1.0"
                     )

#endif // ISUBWINDOW

