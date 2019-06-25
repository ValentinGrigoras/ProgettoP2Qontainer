#include "controller.h"
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
#include<QRegExpValidator>

Controller::Controller(GestioneGiochi* m, QWidget *parent) :
    QWidget(parent),
    menuBar(new MenuBar(this)),
    modello(m),
    inserisciLayout(new LayoutInserisci(this)),
    ricercaLayout(new LayoutRicerca(this)),
    mainLayout(new QHBoxLayout(this)),
    visualizzaLayout( new LayoutVisualizzaGiochi(this)),

dialog(nullptr)
{
    menuBar->setStyleSheet("QMenuBar{font-size : 10pt; font-weight: bold; background-color:#00264d; color:#fff} QMenuBar::item::selected{background-color:#0058b3};");

    mainLayout->setMenuBar(menuBar);
    mainLayout->addWidget(ricercaLayout);
    mainLayout->addWidget(inserisciLayout);
    mainLayout->addWidget(visualizzaLayout);


    setLayout(mainLayout);

    slotShowInserisci();

    connect(visualizzaLayout->getBtnElimina(),SIGNAL(clicked()),this,SLOT(slotEliminaElemento()));
    connect(visualizzaLayout->getBtnElimina(),SIGNAL(clicked()),this,SLOT(slotResetRicerca()));
    connect(visualizzaLayout->getBtnElimina(),SIGNAL(clicked()),ricercaLayout,SLOT(slotResetRicerca()));
    connect(inserisciLayout->getBtnConferma(),SIGNAL(clicked()), this, SLOT(slotAggiungiElemento()));

    connect(menuBar->getSave(),SIGNAL(triggered()), this, SLOT(slotSaveData()));
    connect(menuBar->getRicerca(),SIGNAL(triggered()),this,SLOT(slotShowRicerca()));

    connect(visualizzaLayout->getBtnModifica(),SIGNAL(clicked()),this,SLOT(slotShowModifica()));

    connect(ricercaLayout->getCerca(),SIGNAL(clicked()),this,SLOT(slotRicerca()));
    connect(ricercaLayout->getReset(),SIGNAL(clicked()), ricercaLayout, SLOT(slotResetRicerca()));
    connect(ricercaLayout->getReset(),SIGNAL(clicked()), this, SLOT(slotResetRicerca()));

    connect(inserisciLayout->getTipo(),SIGNAL(activated(QString)),this,SLOT( ChangeComboContent(QString)));
    setFixedSize(inserisciLayout->width()+visualizzaLayout->width()+100, inserisciLayout->height()+80);

    QMessageBox msgBox;
    msgBox.setText("Il contenitore parte inizialmente vuoto. Se si vuole aggiungere dei dati di default, andare su 'File -> Carica da file' e selezionare il file default.xml presente nella cartella root del progetto. Grazie! ");
    msgBox.exec();
}
Controller::~Controller(){}

void Controller::ChangeComboContent(QString p)
{
    inserisciLayout->getAnno()->CreateComboBox(p.toStdString());

}

void Controller::slotShowInserisci() const{
    inserisciLayout->show();
    visualizzaLayout->show();
    ricercaLayout->hide();
}
void Controller::slotAggiungiElemento()
{
    if(! inserisciLayout->getNome()->text().isEmpty() &&
            ! inserisciLayout->getSviluppatore()->text().isEmpty() &&
            ! inserisciLayout->getDescrizione()->document()->isEmpty())
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
                        toPush = new Ps4(push_nome,indiceAnno,indiceGenere,indicePegi,push_sviluppatore,inserisciLayout->getMultiplayer()->isChecked(), inserisciLayout->get4k()->isChecked(),inserisciLayout->getOnline()->isChecked(), descrizione);
                        break;
                    case 2:
                        toPush = new Xbox360(push_nome,indiceAnno,indiceGenere,indicePegi,push_sviluppatore,inserisciLayout->getMultiplayer()->isChecked(), inserisciLayout->get4k()->isChecked(),inserisciLayout->getOnline()->isChecked(), descrizione);
                        break;
                    case 3:
                        toPush = new XboxOne(push_nome,indiceAnno,indiceGenere,indicePegi,push_sviluppatore,inserisciLayout->getMultiplayer()->isChecked(), inserisciLayout->get4k()->isChecked(),inserisciLayout->getOnline()->isChecked(), descrizione);
                        break;
                }
                cout<<toPush;
                if(toPush!= nullptr){
                    modello->push_end(toPush);
                    visualizzaLayout->getList()->addGioco(toPush);
                    slotDataChanged(true);
                    QMessageBox::information(this,"Conferma", "Il gioco è stato inserito correttamente");
                }
    }
    else{
        QMessageBox::information(this,"Errore", "Attenzione! Compila tutti i campi");
    }
}

void Controller::slotDataChanged(bool b) const
{
        menuBar->getSave()->setEnabled(b);
}

void Controller::slotSaveData() const
{
         modello->saveToFile();
         slotDataChanged(false);
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

                   modello->clear();

                   modello->setNewPath(file.toStdString());
                   modello->loadFromFile( file.toStdString());
                    if(modello->getDataSize()==0){
                    QMessageBox::warning(this,"Attenzione!","Il file del programma e' vuoto.");
            }
          else{
                            for(unsigned int i=0; i<modello->getDataSize(); i++)
                                     visualizzaLayout->getList()->addGioco(modello->elementAt(i));

              modello->setDataSaved(true);
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

void Controller::slotRicerca()
{
    if(modello->getDataSize()==0){
        QMessageBox::warning(this, "Attenzione!","Non sono presenti elementi nel modello per poter fare la ricerca.");
    }else{
            ricercaLayout->getList()->clear();
            for(auto it = modello->GetLista_giochi()->begin(); it !=  modello->GetLista_giochi()->end(); ++it){
                modello->GetLista_search()->push_back(*it);
}
        if(ricercaLayout->getCbNome()->isChecked() && ! ricercaLayout->getCercaPerNome()->text().isEmpty()){

                modello-> filterByName( ricercaLayout->getCercaPerNome()->text().toStdString());
        }



 if(ricercaLayout->getCbTipo()->isChecked())
                modello->filterByType(ricercaLayout->getCercaPerTipo()->currentText().toStdString());
  if(ricercaLayout->getCbPegi()->isChecked())
                 modello->filterByPegi(ricercaLayout->getCercaPerPegi()->currentText().toStdString());

    }

    qDebug() <<modello->GetLista_search()->getSize();
    if(modello->GetLista_search()->getSize()==0){
           QMessageBox::warning(this, "Informazione",
                                "Non ci sono giochi che corrispondono ai parametri di ricerca.");
    }
    else {
        for(auto it = modello->GetLista_search()->cbegin(); it != modello->GetLista_search()->cend(); ++it)
            ricercaLayout->getList()->addGioco(*it);
    }

}

void Controller::slotResetRicerca() const
{
        modello->resetSearchRes();
}

void Controller::slotShowRicerca() const
{
        ricercaLayout->show();
        inserisciLayout->hide();
        visualizzaLayout->hide();
}

void Controller::slotEliminaElemento() const // visualizzazione
{
        if(visualizzaLayout->getList()->count() && visualizzaLayout->getList()->currentItem()!= nullptr){
                GiochiListItem* item = visualizzaLayout->getList()->takeItem(visualizzaLayout->getList()->currentRow());
                modello->GetLista_giochi()->erase(item->getItemAddress());
                delete item;
                visualizzaLayout->getList()->reset();
                slotDataChanged(true);
        }
}

void Controller::slotEliminaDaModello() const // ricerca
{
         GiochiListItem* item = ricercaLayout->getList()->currentItem();

      modello->GetLista_giochi()->erase(item->getItemAddress());
      ricercaLayout->getList()->reset();
      visualizzaLayout->getList()->reset();
      delete item;

         slotDataChanged(true);
}




