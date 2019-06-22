#ifndef MENUBAR_H
#define MENUBAR_H
#include <qmenubar.h>
#include <qwidget.h>


class MenuBar : public QMenuBar
{
    Q_OBJECT
        QWidget* parent;

        QMenu* menu;
        QMenu* help;

        QAction* save;
        QAction* load ;
        QAction* exit;

        QMenu* tools;
        QAction* reportBug;
        QAction* about;
        QAction* ricerca;
        QAction* inserisci;
public:
    MenuBar(QWidget* = nullptr);
    QMenu *getMenu() const;
    QMenu *getHelp() const;
    QAction *getSave() const;
    QAction *getLoad() const;
    QMenu *getTools() const;
    QAction *getCalcolaPrezzo() const;
    QAction *getReportBug() const;
    QAction *getAbout() const;
    QAction *getExit() const;
};

#endif // MENUBAR_H
