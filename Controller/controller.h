#ifndef CONTROLLER_H
#define CONTROLLER_H
#include <QObject>
#include "Model/gestionegiochi.h"
#include "View/menubar.h"
#include "View/layoutinserisci.h"
#include"View/layoutvisualizzagiochi.h"
class InsertView;
class MainView;

class Controller : public QWidget
{
    Q_OBJECT
private:
MenuBar* menuBar;
GestioneGiochi * modello;
LayoutInserisci* inserisciLayout;
QHBoxLayout* mainLayout;
LayoutVisualizzaGiochi *visualizzaLayout;
LayoutVisualizzaItem* dialog;
public:
Controller(GestioneGiochi*, QWidget* =nullptr);
~Controller();
signals:

public slots:
 void slotShowInserisci()const;
 void slotShowVisualizza()const;
void slotAggiungiElemento();
  void slotDataChanged(bool)const;
      void slotSaveData()const;
        void slotShowAboutDialog();
        void slotShowReportBug();
        void slotLoad();
         void slotShowModifica();
         void slotEliminaElemento()const;
         void slotEliminaDaModello(Gioco*)const;
        //void slotEliminaDaModello()const;
};

#endif // CONTROLLER_H
