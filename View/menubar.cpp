#include "menubar.h"

MenuBar::MenuBar(QWidget* p):
    parent(p),
    menu(new QMenu("File", this)),
    help(new QMenu("Help", this)),
    save( new QAction("Save", menu)),
    load( new QAction("Load", menu)),
    exit(new QAction("Exit", menu)),
    tools(new QMenu("Tools",this)),
    calcolaPrezzo(new QAction("Calcola totale", tools)),
    reportBug(new QAction("Report Bug",help)),
    about(new QAction("About",help)),
    visualizza(new QAction("Visualizza",p)),
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
    addAction(visualizza);
    addAction(ricerca);
    tools->addAction(calcolaPrezzo);
    addMenu(tools);
    actionList.push_back(reportBug);
    actionList.push_back(about);

    help->addActions(actionList);

    actionList.clear();
    addMenu(help);
/*
    connect(exit,SIGNAL(triggered()),parent,SLOT(close()));
    connect(save,SIGNAL(triggered()),parent,SLOT(slotSaveData()));
    connect(about,SIGNAL(triggered()), parent,SLOT(slotShowAboutDialog()));
    connect(reportBug, SIGNAL(triggered()), parent, SLOT(slotShowReportBug()));
    connect(calcolaPrezzo,SIGNAL(triggered()), parent, SLOT(slotCalcolaPrezzo()));
    connect(load,SIGNAL(triggered()),parent, SLOT(slotLoad()));*/
    connect(visualizza, SIGNAL(triggered()), parent,SLOT(slotShowVisualizza()));
   // connect(ricerca, SIGNAL(triggered()), parent,SLOT(slotShowRicerca()));
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

QMenu *MenuBar::getTools() const{
    return tools;
}

QAction *MenuBar::getCalcolaPrezzo() const{
    return calcolaPrezzo;
}

QAction *MenuBar::getReportBug() const{
    return reportBug;
}

QAction *MenuBar::getAbout() const{
    return about;
}


QAction *MenuBar::getExit() const{
    return exit;
}

