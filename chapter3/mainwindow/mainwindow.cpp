#include "mainwindow.h"

#include <QtGui>

#include "finddialog.h"
#include "gotocelldialog.h"
#include "sortdialog.h"
#include "spreadsheet.h

MainWindow::MainWindow()
{
    spreadsheet = new SpreadSheet;
    setCentralWidget(spreadsheet);

    createActions();
    createMenus();
    createContextMenu();
    createToolBars();
    createStatusBar();

    readSettings();

    findDIalog = nullptr;

    setWindowIcon(QIcon(":/images/icon.png"));
    setCurrentFile("");
}

void MainWindow::createActions()
{
    newAction = new QAction(tr("&new"), this);
    newAction->setIcon(QIcon(":/images/new.png"));
    newAction->setShortcut(QKeySequence::New);
    newAction->setStatusTip(tr("Create a new spreadsheet file"));
    connect(newAction, SIGNAL(triggered(bool)), this, SLOT(newFile()));
}

