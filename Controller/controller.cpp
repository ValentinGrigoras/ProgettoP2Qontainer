#include "controller.h"
#include "View/insertview.h"
#include"View/layoutvisualizzagiochi.h"
#include"Model/ps3.h"
#include"Model/ps4.h"
#include"Model/xbox360.h"
#include"Model/xboxone.h"

#include <QMessageBox>
Controller::Controller(GestioneGiochi* m, QWidget *parent) :
    QWidget(parent),
    menuBar(new MenuBar(this)),
    modello(m),
    inserisciLayout(new LayoutInserisci(this)),
mainLayout(new QHBoxLayout(this)),
  visualizzaLayout( new LayoutVisualizzaGiochi(this))
{

    mainLayout->setMenuBar(menuBar);
    mainLayout->addWidget(inserisciLayout);
    mainLayout->addWidget(visualizzaLayout);
    slotShowInserisci();


    setLayout(mainLayout);



}

Controller::~Controller()
{

}
void Controller::slotShowInserisci() const{
    inserisciLayout->show();
     visualizzaLayout->hide();

}
void Controller::slotShowVisualizza() const{
    visualizzaLayout->show();
    inserisciLayout->hide();

}

void Controller::slotAggiungiElemento()
{
    int indiceTipo = inserisciLayout->getTipo()->currentIndex();
    string push_nome = inserisciLayout->getNome()->text().toStdString();
    int indiceAnno = inserisciLayout->getAnno()->currentIndex();
    string push_sviluppatore = inserisciLayout->getSviluppatore()->text().toStdString();
    string indicePegi = inserisciLayout->getPegi()->currentText().toStdString();
    string  indiceGenere = inserisciLayout->getGenere()->currentText().toStdString();
Gioco* toPush=nullptr;
    switch (indiceTipo) {
    case 1:
        toPush = new Ps3(push_nome,indiceAnno,indiceGenere,indicePegi,push_sviluppatore,inserisciLayout->getMultiplayer()->isChecked(), inserisciLayout->get4k()->isChecked(),inserisciLayout->getOnline()->isChecked(), 50.0,"Descrizione");

        break;
    default:
        break;
    }
    if(toPush!= nullptr){
        modello->push_end(toPush);
        visualizzaLayout->getList()->addGioco(toPush);
        slotDataChanged(true);
        QMessageBox::information(this,"Conferma", "Il gioco è stato inserito correttamente");
    }
}

void Controller::slotDataChanged(bool b) const
{
    menuBar->getSave()->setEnabled(b);
}

void Controller::slotSaveData() const
{
    if(!modello->getIsDataSaved()){
        modello->save();
        slotDataChanged(false);
    }
}
//void Controller::slot_AddGame() const
//{
   //string nome = insert_view->getNome().toUtf8().constData();

//}




