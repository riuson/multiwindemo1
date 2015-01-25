#ifndef ISUBWINDOW
#define ISUBWINDOW

#include <QString>

class ISubWindow
{
public:
    virtual QString windowTitle() const = 0;

signals:
    void windowCreated(QWidget *window);
};
Q_DECLARE_INTERFACE (ISubWindow,
                     "riuson.multiwindemo/1.0"
                     )

#endif // ISUBWINDOW

