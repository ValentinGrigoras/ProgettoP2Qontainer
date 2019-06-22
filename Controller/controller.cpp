#include "controller.h"
#include "View/insertview.h"
#include"View/layoutvisualizzagiochi.h"
#include"Model/ps3.h"
#include"Model/ps4.h"
#include"Model/xbox360.h"
#include"Model/xboxone.h"
#include<QDebug>
#include <QMessageBox>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <iostream>
#include <QFileDialog>
#include <QBuffer>
Controller::Controller(GestioneGiochi* m, QWidget *parent) :
    QWidget(parent),
    menuBar(new MenuBar(this)),
    modello(m),
    inserisciLayout(new LayoutInserisci(this)),
mainLayout(new QHBoxLayout(this)),
  visualizzaLayout( new LayoutVisualizzaGiochi(this)),
dialog(nullptr)
{
menuBar->setStyleSheet("QMenuBar{font-size : 10pt; font-weight: bold; background-color:#00264d; color:#fff} QMenuBar::item::selected{background-color:#0058b3};");
    mainLayout->setMenuBar(menuBar);
    mainLayout->addWidget(inserisciLayout);
    mainLayout->addWidget(visualizzaLayout);
    slotShowInserisci();


    setLayout(mainLayout);

connect(inserisciLayout->getBtnConferma(),SIGNAL(clicked()), this, SLOT(slotAggiungiElemento()));
    connect(visualizzaLayout->getBtnElimina(),SIGNAL(clicked()),this,SLOT(slotEliminaElemento()));
connect(menuBar->getSave(),SIGNAL(triggered()), this, SLOT(slotSaveData()));
 connect(visualizzaLayout->getBtnModifica(),SIGNAL(clicked()),this,SLOT(slotShowModifica()));
slotLoad();
}

Controller::~Controller()
{
    //modello->saveToFile();
}
void Controller::slotShowInserisci() const{
    inserisciLayout->show();
     visualizzaLayout->show();

}
void Controller::slotShowVisualizza() const{
    visualizzaLayout->show();
    inserisciLayout->show();

}

void Controller::slotAggiungiElemento()
{
    int  indiceTipo = inserisciLayout->getTipo()->currentIndex();
    string push_nome = inserisciLayout->getNome()->text().toStdString();
    string  indiceAnno = inserisciLayout->getAnno()->currentText().toStdString();
    string push_sviluppatore = inserisciLayout->getSviluppatore()->text().toStdString();
    string indicePegi = inserisciLayout->getPegi()->currentText().toStdString();
    string  indiceGenere = inserisciLayout->getGenere()->currentText().toStdString();
    string  descrizione = inserisciLayout->getDescrizione()->toPlainText().toStdString();
Gioco* toPush=nullptr;
    switch (indiceTipo) {
    case 0:
        toPush = new Ps3(push_nome,indiceAnno,indiceGenere,indicePegi,push_sviluppatore,inserisciLayout->getMultiplayer()->isChecked(), inserisciLayout->get4k()->isChecked(),inserisciLayout->getOnline()->isChecked(), descrizione);
        break;
    case 1:
        //toPush = new Ps4(push_nome,indiceAnno,indiceGenere,indicePegi,push_sviluppatore,inserisciLayout->getMultiplayer()->isChecked(), inserisciLayout->get4k()->isChecked(),inserisciLayout->getOnline()->isChecked(), 50.0,"Descrizione");
        break;

    }
    cout<<toPush;
    if(toPush!= nullptr){
        modello->push_end(toPush);
        visualizzaLayout->getList()->addGioco(toPush);
        slotDataChanged(true);
        QMessageBox::information(this,"Conferma", "Il gioco è stato inserito correttamente");
    }
    else{
        QMessageBox::information(this,"Errore", "Il tuo oggetto è vuoto");
    }
}

void Controller::slotDataChanged(bool b) const
{
    menuBar->getSave()->setEnabled(b);
}

void Controller::slotSaveData() const
{
     qDebug() <<"Pre Salvaa" << QString::fromStdString(modello->getPath());

     if(!modello->getIsDataSaved()){
         modello->saveToFile();
         slotDataChanged(false);
     }

        qDebug() <<"Dopo Salvaa" << QString::fromStdString(modello->getPath());


}

void Controller::slotShowAboutDialog()
{
    GiochiListItem *  a= visualizzaLayout->getList()->currentItem();

    if(dialog!=nullptr) delete dialog;
    dialog= new LayoutVisualizzaItem(a,this);
    dialog->show();
    slotDataChanged(true);
}

void Controller::slotShowReportBug()
{
    QMessageBox::about(this, "Report","Per segnalare un bug e' pregato di contattare email: valentin.grigoras@studenti.unipd.it, grazie!");
}

void Controller::slotLoad()
{
    if(!modello->getIsDataSaved()){
        QMessageBox::StandardButton reply= QMessageBox::question(this,"Attenzione!","Ci sono modifiche che non sono state salvate, se clicchi YES i dati verranno salvati nel file corrente.",QMessageBox::Yes|QMessageBox::No);
        if(reply==QMessageBox::No)
            return;
    }

    QString file= QFileDialog::getOpenFileName(
                this,
                tr("Choose file"),
                "P2Progetto/ProgettoP2Qontainer/Model",
                "File XML(*.xml)"
                );
       if(file!=""){
           visualizzaLayout->getList()->clear();
           //ricercaLayout->slotResetRicerca();
           modello->clear();

           modello->setNewPath(file.toStdString());
           qDebug() <<QString::fromStdString( modello->getPath());
    modello->loadFromFile( file.toStdString());
    if(modello->getDataSize()==0){
     QMessageBox::warning(this,"Attenzione!","Il file del programma e' vuoto.");
}
  else{
        qDebug() << modello->getDataSize();
        for(unsigned int i=0; i<modello->getDataSize(); i++)
           visualizzaLayout->getList()->addGioco(modello->elementAt(i));
      modello->setDataSaved(true);
        slotShowVisualizza();
        slotDataChanged(false);
    }
}
}

void Controller::slotShowModifica()
{
    GiochiListItem* a= visualizzaLayout->getList()->currentItem();

    if(dialog!=nullptr) delete dialog;
    dialog= new LayoutVisualizzaItem(a,this);
    dialog->show();
    slotDataChanged(true);
}

void Controller::slotEliminaElemento() const
{
    if(visualizzaLayout->getList()->count() && visualizzaLayout->getList()->currentItem()!= nullptr){
        GiochiListItem* item = visualizzaLayout->getList()->takeItem(visualizzaLayout->getList()->currentRow());

        modello->erase(item->getItemAddress());
        delete item;
        visualizzaLayout->getList()->reset();
        slotDataChanged(true);
    }
}

void Controller::slotEliminaDaModello(Gioco * g) const
{
    std::cerr<<"slotEliminaDaModello(Abbigliamento* abb)const"<<std::endl;
    modello->erase(g);
    delete  g;
    //ricercaLayout->slotResetRicerca();
    slotDataChanged(true);
}

//void Controller::slotEliminaDaModello() const
//{
//    //    std::cerr<<"slotEliminaDaModello const"<<std::endl;
//        for(; ricercaLayout->getList()->count()!=0;){
//            AbbigliamentoListItem* itemDaRicerca= ricercaLayout->getList()->takeItem(0);
//            AbbigliamentoListItem* itemDaVisualizza=visualizzaLayout->getList()->takeItem(itemDaRicerca->getItemAddress());
//            delete  itemDaRicerca;
//            delete  itemDaVisualizza;
//        }
//        modello->eliminaTrovati();
//        slotDataChanged(true);
//}

//void Controller::slotEliminaElemento() const
//{

//}

//void Controller::slot_AddGame() const
//{
   //string nome = insert_view->getNome().toUtf8().constData();

//}




