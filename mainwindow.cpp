/****************************************************************************
**
** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies).
** Contact: http://www.qt-project.org/legal
**
** This file is part of the examples of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** You may use this file under the terms of the BSD license as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of Digia Plc and its Subsidiary(-ies) nor the names
**     of its contributors may be used to endorse or promote products derived
**     from this software without specific prior written permission.
**
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
** $QT_END_LICENSE$
**
****************************************************************************/

#include <QtWidgets>

#include "mainwindow.h"
#include "isubwindow.h"
#include "windowexample.h"

MainWindow::MainWindow()
{
    this->mBarWindows = new QToolBar("Linker ToolBar", this);
    this->addToolBar(Qt::BottomToolBarArea, this->mBarWindows);

    this->mdiArea = new QMdiArea;

    this->setCentralWidget(this->mdiArea);

    this->connect(this->mdiArea, SIGNAL(subWindowActivated(QMdiSubWindow*)), SLOT(on_subWindowActivated(QMdiSubWindow*)));

    windowMapper = new QSignalMapper(this);
    this->connect(windowMapper, SIGNAL(mapped(QWidget*)), this, SLOT(setActiveSubWindow(QWidget*)));
    this->createMenus();

    this->setWindowTitle(tr("MDI"));
    this->setUnifiedTitleAndToolBarOnMac(true);
}

void MainWindow::newWindow()
{
    QWidget *child = createNewWindow();
    child->show();
    this->updateWindowToolbar();
}

void MainWindow::updateWindowMenu()
{
    this->windowMenu->clear();

    QList<QMdiSubWindow *> windows = this->mdiArea->subWindowList();

    for (int i = 0; i < windows.size(); ++i) {
        ISubWindow *subWindow = qobject_cast<ISubWindow *>(windows.at(i)->widget());

        if (subWindow != NULL) {
            QString text = subWindow->windowTitle();
            QAction *action  = this->windowMenu->addAction(text);
            action->setCheckable(true);
            action ->setChecked(subWindow == activeSubWindow());
            connect(action, SIGNAL(triggered()), this->windowMapper, SLOT(map()));
            this->windowMapper->setMapping(action, windows.at(i));
        }
    }
}

void MainWindow::updateWindowToolbar()
{
    for (int i = this->mBarWindows->actions().length() - 1; i >= 0; i--) {
        this->mBarWindows->removeAction(this->mBarWindows->actions().at(i));
    }

    QList<QMdiSubWindow *> windows = this->mdiArea->subWindowList();

    for (int i = 0; i < windows.size(); ++i) {
        ISubWindow *subWindow = qobject_cast<ISubWindow *>(windows.at(i)->widget());

        if (subWindow != NULL) {
            QString text = subWindow->windowTitle();
            QAction *action = this->mBarWindows->addAction(text, this->windowMapper, SLOT(map()));
            action->setCheckable(true);
            action->setChecked(subWindow == activeSubWindow());
            this->windowMapper->setMapping(action, windows.at(i));
        }
    }
}

QWidget *MainWindow::createNewWindow()
{
    QWidget *child = new WindowExample(this);
    this->mdiArea->addSubWindow(child);

    this->connect(child, SIGNAL(windowCreated(QWidget*)), SLOT(on_windowCreated(QWidget*)));

    return child;
}

void MainWindow::createMenus()
{
    this->fileMenu = this->menuBar()->addMenu(tr("&File"));

    QAction *actionNewWindow = this->fileMenu->addAction(tr("&New Custom Window"));
    actionNewWindow->setStatusTip(tr("Create a new custom window"));
    this->connect(actionNewWindow, SIGNAL(triggered()), SLOT(newWindow()));

    this->windowMenu = this->menuBar()->addMenu(tr("&Window"));
    this->updateWindowMenu();
    this->connect(this->windowMenu, SIGNAL(aboutToShow()), SLOT(updateWindowMenu()));
}

ISubWindow *MainWindow::activeSubWindow()
{
    if (QMdiSubWindow *activeSubWindow = this->mdiArea->activeSubWindow())
        return qobject_cast<ISubWindow *>(activeSubWindow->widget());
    return 0;
}

void MainWindow::setActiveSubWindow(QWidget *window)
{
    if (!window)
        return;

    this->mdiArea->setActiveSubWindow(qobject_cast<QMdiSubWindow *>(window));
}

void MainWindow::on_subWindowActivated(QMdiSubWindow *window)
{
    this->updateWindowToolbar();
}

void MainWindow::on_windowCreated(QWidget *window)
{
    window->setParent(this);
    this->mdiArea->addSubWindow(window);
    window->show();
    this->connect(window, SIGNAL(windowCreated(QWidget*)), SLOT(on_windowCreated(QWidget*)));
}
