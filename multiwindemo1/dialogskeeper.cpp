#include "dialogskeeper.h"

DialogsKeeper::DialogsKeeper(QObject *parent) : QObject(parent)
{

}

DialogsKeeper::~DialogsKeeper()
{
    this->removeAll();
}

void DialogsKeeper::addDialog(QDialog *dialog)
{
    this->mDialogs.append(dialog);
    this->connect(dialog, SIGNAL(finished(int)), SLOT(dialog_finished(int)));
}

void DialogsKeeper::removeDialog(QDialog *dialog)
{
    if (this->mDialogs.contains(dialog)) {
        this->mDialogs.removeOne(dialog);
        delete dialog;
    }
}

void DialogsKeeper::removeAll()
{
    qDeleteAll(this->mDialogs);
}

void DialogsKeeper::dialog_finished(int result)
{
    QObject *obj = sender();
    QDialog *dialog = qobject_cast<QDialog *>(obj);
    this->removeDialog(dialog);
}

