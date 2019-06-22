#include "xmlparser.h"
#include <QFile>
#include <QSaveFile>
#include <QXmlStreamReader>
#include <QXmlStreamWriter>
#include <QDebug>
#include "Model/ps3.h"
#include"Model/ps4.h"
#include "Model/xbox360.h"
#include"Model/xboxone.h"

#include<QDebug>
XmlParser::XmlParser(string filepath, bool datasaved): filename (filepath), isDataSaved(datasaved)
{
}

void XmlParser::write(DLinkedList<Gioco *> *& list )
{
    /* QSaveFile rispetto a QFile è più adatto per effettuare scritture su disco. Gestisce meglio
          i casi di errore, garantendo che non vengano persi i dati del file in caso di errori in scrittura */
       QSaveFile file(QString::fromStdString(filename));

       // Apre un file. Se non si apre lancia una eccezione.
       if(!file.open(QIODevice::WriteOnly)) {
           throw std::exception();
           // NB: la cosa giusta da fare sarebbe creare un tipo eccezione. std::exception è troppo generica.
       }
       QXmlStreamWriter writer(&file);

          writer.setAutoFormatting(true); // Per leggibilità del file XML
          writer.writeStartDocument();    // Scrive le intestazioni XML
          writer.writeComment("File di salvataggio dell'applicazione. Non modificare a mano.");
writer.writeStartElement("root");
          auto it = list->begin();
          while(it!= list->end()){
                 Gioco* toSave = *it;
qDebug() << "Sono dentro il while";
            writer.writeStartElement("Gioco");
           writer.writeAttribute("tipo", QString::fromStdString(toSave->getTipo()));

           writer.writeStartElement("nome");
           writer.writeCharacters(QString::fromStdString(toSave->getNome()));
           writer.writeEndElement();
           writer.writeStartElement("anno");
           writer.writeCharacters(QString::fromStdString(toSave->getAnnoRilascio()));
           writer.writeEndElement();
           writer.writeStartElement("genere");
           writer.writeCharacters(QString::fromStdString(toSave->getGenere()));
           writer.writeEndElement();
           writer.writeStartElement("pegi");
           writer.writeCharacters(QString::fromStdString(toSave->getClassificazionePegi()));
           writer.writeEndElement();
           writer.writeStartElement("sviluppatore");
           writer.writeCharacters(QString::fromStdString(toSave->getSviluppatore()));
           writer.writeEndElement();
           writer.writeStartElement("multiplayer");
           writer.writeCharacters(QString::fromStdString(toSave->getMultiplayer()?"yes":"no"));
           writer.writeEndElement();
           writer.writeStartElement("4k");
           writer.writeCharacters(QString::fromStdString(toSave->get4k()?"yes":"no"));
           writer.writeEndElement();
           writer.writeStartElement("online");
           writer.writeCharacters(QString::fromStdString(toSave->getOnline()?"yes":"no"));
           writer.writeEndElement();
           writer.writeStartElement("descrizione");
           writer.writeCharacters(QString::fromStdString(toSave->getDescrizione()));
           writer.writeEndElement();
            writer.writeEndElement();
               if (writer.hasError()) {// se c'è stato un problema in scrittura interrompe ed esce
                          throw std::exception();}
               qDebug() <<"sono in write di parser prima di ++it" ;
               ++it;
          }
          writer.writeEndDocument();  // chiude eventuali tag lasciati aperti e aggiunge una riga vuota alla fine

          file.commit(); // Scrive il file temporaneo su disco
          isDataSaved=true;
}

