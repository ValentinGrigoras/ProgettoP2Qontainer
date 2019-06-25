#include "layoutvisualizzaitem.h"
#include "layoutinserisci.h"
#include "layoutvisualizzaitem.h"
#include <QLabel>
#include <QFormLayout>
#include <QString>
#include <QFileInfo>
#include <QFileDialog>
#include <QBuffer>
#include <Model/gioco.h>
#include <Model/ps3.h>
#include <Model/ps4.h>
#include <Model/xboxone.h>
#include <Model/xbox360.h>

LayoutVisualizzaItem::LayoutVisualizzaItem(GiochiListItem* a, QWidget* parent):
    listItem(a),
    btnClose(new QPushButton("Chiudi senza salvare",parent)),
    salvaModifica( new QPushButton("Salva modifiche",parent)),
    g(a->getItemAddress()),
    descrizione(new QTextEdit(parent)),
  sviluppatore(new QTextEdit(parent))

{
        QVBoxLayout* mainLayout= new QVBoxLayout();
        QLabel * svilupp = new QLabel(tr("Sviluppatore"));
        sviluppatore->setText(QString::fromStdString(g->getSviluppatore()));
        descrizione->setText(QString::fromStdString(g->getDescrizione()));
        mainLayout->addWidget(new QLabel("Descrizione: "));
        mainLayout->addWidget(descrizione);
        mainLayout->addWidget(svilupp);
        mainLayout->addWidget(sviluppatore);
        QHBoxLayout* btnLayout= new QHBoxLayout();
        btnLayout->addWidget(salvaModifica);
        btnLayout->addWidget(btnClose);

        mainLayout->addLayout(btnLayout);


        setLayout(mainLayout);
        setModal(true);
        setFont(QFont("lucida",14,3));
        connect(btnClose,SIGNAL(clicked()),this,SLOT(close()));
        connect(salvaModifica,SIGNAL(clicked()),this,SLOT(slotSalvaModifica()));
        connect(salvaModifica,SIGNAL(clicked()), this,SLOT(close()));

}

void LayoutVisualizzaItem::slotSalvaModifica()const{

        g->setDescrizione(descrizione->toPlainText().toStdString());
        g->setDescrizione(sviluppatore->toPlainText().toStdString());
        listItem->update();

}

