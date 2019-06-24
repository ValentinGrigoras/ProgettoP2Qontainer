#include "menubar.h"

MenuBar::MenuBar(QWidget* p):
    parent(p),
    menu(new QMenu("File", this)),
    help(new QMenu("Aiuto", this)),
    save( new QAction("Salva su file", menu)),
    load( new QAction("Carica da file", menu)),
    exit(new QAction("Esci", menu)),
    reportBug(new QAction("Report Bug",help)),
    ricerca( new QAction("Ricerca",p)),
    inserisci(new QAction("Inserisci",p))
{
    QList<QAction*>actionList;

    actionList.push_back(save);
    actionList.push_back(load);
    actionList.push_back(exit);
    menu->addActions(actionList);
    actionList.clear();

    addMenu(menu);
    addAction(inserisci);
    addAction(ricerca);
    actionList.push_back(reportBug);

    help->addActions(actionList);

    actionList.clear();
    addMenu(help);

    connect(exit,SIGNAL(triggered()),parent,SLOT(close()));
    connect(save,SIGNAL(triggered()),parent,SLOT(slotSaveData()));
    connect(reportBug, SIGNAL(triggered()), parent, SLOT(slotShowReportBug()));
    connect(load,SIGNAL(triggered()),parent, SLOT(slotLoad()));
   connect(ricerca, SIGNAL(triggered()), parent,SLOT(slotShowRicerca()));
    connect(inserisci, SIGNAL(triggered()), parent,SLOT(slotShowInserisci()));

}
QMenu *MenuBar::getMenu() const{
    return menu;
}

QMenu *MenuBar::getHelp() const{
    return help;
}

QAction *MenuBar::getSave() const{
    return save;
}

QAction *MenuBar::getLoad() const{
    return load;
}


QAction *MenuBar::getReportBug() const{
    return reportBug;
}

QAction *MenuBar::getExit() const{
    return exit;
}

QAction *MenuBar::getRicerca() const
{
    return ricerca;
}

