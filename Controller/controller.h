#ifndef CONTROLLER_H
#define CONTROLLER_H
#include <QObject>
#include "Model/gestionegiochi.h"
#include "View/menubar.h"
#include "View/layoutinserisci.h"
#include"View/layoutvisualizzagiochi.h"
#include"View/layoutricerca.h"
//class InsertView;
//class MainView;

class Controller : public QWidget
{
    Q_OBJECT
private:
MenuBar* menuBar;
GestioneGiochi * modello;
LayoutInserisci* inserisciLayout;
LayoutRicerca* ricercaLayout;
QHBoxLayout* mainLayout;
LayoutVisualizzaGiochi *visualizzaLayout;
LayoutVisualizzaItem* dialog;
public:
Controller(GestioneGiochi*, QWidget* =nullptr);
~Controller();
signals:

public slots:
 void slotShowInserisci()const;
// void slotShowVisualizza()const;
 void slotShowRicerca()const;

// void resetSearchList();

void slotAggiungiElemento();
  void slotDataChanged(bool)const;
      void slotSaveData()const;
        void slotShowReportBug();
        void slotLoad();
         void slotShowModifica();
         void slotRicerca();
        void slotResetRicerca()const;

         void slotEliminaElemento()const;
         //void slotEliminaDaModello(Gioco*)const;
        void slotEliminaDaModello()const;
};

#endif // CONTROLLER_H
