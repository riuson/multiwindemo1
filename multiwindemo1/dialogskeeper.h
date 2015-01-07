#ifndef DIALOGSKEEPER_H
#define DIALOGSKEEPER_H

#include <QObject>
#include <QDialog>

class DialogsKeeper : public QObject
{
    Q_OBJECT
public:
    explicit DialogsKeeper(QObject *parent = 0);
    ~DialogsKeeper();

private:
    QList<QDialog *> mDialogs;

signals:

public slots:
    void addDialog(QDialog *dialog);
    void removeDialog(QDialog *dialog);
    void removeAll();

private slots:
    void dialog_finished(int result);
};

#endif // DIALOGSKEEPER_H
