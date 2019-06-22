#include "layoutvisualizzaitem.h"
#include "layoutinserisci.h"
#include "layoutvisualizzaitem.h"
#include <QLabel>
#include <QFormLayout>
#include <QString>
#include <QFileInfo>
#include <QFileDialog>
#include <QBuffer>
#include <model/gioco.h>
#include <model/ps3.h>
#include <model/ps4.h>
#include <model/xboxone.h>
#include <model/xbox360.h>

LayoutVisualizzaItem::LayoutVisualizzaItem(GiochiListItem* a, QWidget* parent):
    listItem(a),
    btnClose(new QPushButton("Chiudi senza salvare",parent)),
    salvaModifica( new QPushButton("Salva modifiche",parent)),
    g(a->getItemAddress()),
    immagine(new QLabel(parent)),
    descrizione(new QTextEdit(parent))

{
 QVBoxLayout* mainLayout= new QVBoxLayout();

 descrizione->setText(QString::fromStdString(g->getDescrizione()));
 mainLayout->addWidget(new QLabel("Descrizione: "));
 mainLayout->addWidget(descrizione);

 QHBoxLayout* btnLayout= new QHBoxLayout();
 btnLayout->addWidget(salvaModifica);
 btnLayout->addWidget(btnClose);



 mainLayout->addLayout(btnLayout);


 setLayout(mainLayout);
 setModal(true);
 setFont(QFont("Times",14,3));
 connect(btnClose,SIGNAL(clicked()),this,SLOT(close()));
 connect(salvaModifica,SIGNAL(clicked()),this,SLOT(slotSalvaModifica()));
 connect(salvaModifica,SIGNAL(clicked()), this,SLOT(close()));

}

void LayoutVisualizzaItem::slotSalvaModifica()const{

    g->setDescrizione(descrizione->toPlainText().toStdString());
        listItem->update();

}

