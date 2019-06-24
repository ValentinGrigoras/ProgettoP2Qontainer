#include "gestionegiochi.h"

#include <QSaveFile>
#include <QXmlStreamReader>

#include <QFile>
#include <QDebug>
#include"Exceptions/openfileexception.h"
#include "Model/ps3.h"
#include "Model/ps4.h"
#include "Model/xbox360.h"
#include "Model/xboxone.h"


GestioneGiochi::GestioneGiochi(string g):lista_giochi(new DLinkedList<Gioco*>()),lista_search(new DLinkedList<Gioco*>()),isDataSaved(true),path(g)
{

}

GestioneGiochi::~GestioneGiochi()
{
    for (DLinkedList<Gioco*>::list_iterator it = lista_giochi->begin(); it != lista_giochi->end(); it++)
    {

            delete *it;
}
}

void GestioneGiochi::push_end(Gioco * g)
{
    lista_giochi->push_back(g);

isDataSaved=false;
}

void GestioneGiochi::saveToFile()
{
    QSaveFile file(QString::fromStdString(path));
    if(!file.open(QIODevice::WriteOnly)) {
        throw OpenFileException("Errore");
    }
    qDebug() <<"ciao " << QString::fromStdString(path);

       QXmlStreamWriter writer(&file);

          writer.setAutoFormatting(true); // Per leggibilità del file XML
          writer.writeStartDocument();    // Scrive le intestazioni XML
          writer.writeComment("File di salvataggio dell'applicazione. Non modificare a mano.");

          writer.writeStartElement("root");

          auto it =lista_giochi-> cbegin();
          while(it!= lista_giochi->cend()){
                 Gioco* toSave = *it;


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
           writer.writeStartElement("s4k");
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

               ++it;
          }
          writer.writeEndDocument();  // chiude eventuali tag lasciati aperti e aggiunge una riga vuota alla fine

          file.commit(); // Scrive il file temporaneo su disco
          isDataSaved=true;
}

void GestioneGiochi::loadFromFile(string path)
{
    //The QDomDocument class represents an XML document.
    QDomDocument xmlBOM;
    // Load xml file as raw data
    QFile f(QString::fromStdString(path));
    if (!f.open(QIODevice::ReadOnly ))
    {
        // Error while loading file
        std::cerr << "Error while loading file" << std::endl;

    }

    // Set data into the QDomDocument before processing
    xmlBOM.setContent(&f);
    f.close();

    // Extract the root markup
    QDomElement root=xmlBOM.documentElement(); // root tag

    // Get the first child of the root (Markup COMPONENT is expected)
    QDomElement Component=root.firstChild().toElement();

    // Loop while there is a child
    while(!Component.isNull())
    {

        // Check if the child tag name is Gioco
        if (Component.tagName()=="Gioco")
        {
     Gioco* toPush;
            // Read and display the component ID
            QString platform=Component.attribute("tipo","no name");

            // Get the first child of the component
            QDomElement Child=Component.firstChild().toElement();

            QString name;
            QString year;
            QString game_type;
            QString pegi;
            QString developer;
            QString multiplayer;
            QString s4k;;
            QString online;
            QString description;

            // Read each child of the component node
            while (!Child.isNull())
            {
                // Read Name and value
                if (Child.tagName()=="nome")
                {name=Child.firstChild().toText().data();

                }
                if (Child.tagName()=="anno") year=Child.firstChild().toText().data();
                if (Child.tagName()=="genere") game_type=Child.firstChild().toText().data();
                if (Child.tagName()=="pegi") pegi=Child.firstChild().toText().data();
                if (Child.tagName()=="sviluppatore") developer=Child.firstChild().toText().data();
                if (Child.tagName()=="multiplayer") multiplayer=Child.firstChild().toText().data();
                if (Child.tagName()=="s4k") s4k=Child.firstChild().toText().data();
                if (Child.tagName()=="online") online=Child.firstChild().toText().data();
                if (Child.tagName()=="descrizione") description=Child.firstChild().toText().data();

                // Next child
                Child = Child.nextSibling().toElement();
            }
            if(platform == "Ps3") {
                toPush = new Ps3(name.toStdString(),year.toStdString(),game_type.toStdString(),pegi.toStdString(),developer.toStdString(),(multiplayer.toStdString()=="si")?true:false,(s4k.toStdString()=="si")?true:false,(online.toStdString()=="si")?true:false,description.toStdString());
            }
            else if(platform == "Ps4") {
                toPush = new Ps4(name.toStdString(),year.toStdString(),game_type.toStdString(),pegi.toStdString(),developer.toStdString(),(multiplayer.toStdString()=="si")?true:false,(s4k.toStdString()=="si")?true:false,(online.toStdString()=="si")?true:false,description.toStdString());
            }
           else  if(platform == "Xbox360") {
                toPush = new Xbox360(name.toStdString(),year.toStdString(),game_type.toStdString(),pegi.toStdString(),developer.toStdString(),(multiplayer.toStdString()=="si")?true:false,(s4k.toStdString()=="si")?true:false,(online.toStdString()=="si")?true:false,description.toStdString());
            }
           else if(platform == "XboxOne") {
                toPush = new XboxOne(name.toStdString(),year.toStdString(),game_type.toStdString(),pegi.toStdString(),developer.toStdString(),(multiplayer.toStdString()=="si")?true:false,(s4k.toStdString()=="si")?true:false,(online.toStdString()=="si")?true:false,description.toStdString());
            }
             lista_giochi->push_back(toPush);
           }
        Component = Component.nextSiblingElement();

    }
    isDataSaved=true;
}



Gioco *GestioneGiochi::elementAt(unsigned int index)
{
    isDataSaved=false;
    return lista_giochi->at(index);
}

string GestioneGiochi::getPath() const
{
    return path;
}

bool GestioneGiochi::getIsDataSaved() const
{
    return isDataSaved;
}

void GestioneGiochi::setDataSaved(bool data)
{
    isDataSaved=data;
}

void GestioneGiochi::clear()
{
    isDataSaved=false;

    if(!lista_giochi->isEmpty()){
        lista_giochi->clear();
    }

}

void GestioneGiochi::printAll() const
{
    qDebug() << "sono in printAll di Gestione Giochi";
lista_giochi->PrintAll();
}

unsigned int GestioneGiochi::getDataSize() const
{
return lista_giochi->getSize();
}

DLinkedList<Gioco *> *GestioneGiochi::GetLista_giochi() const
{
    return lista_giochi;
}

DLinkedList<Gioco *> *GestioneGiochi::GetLista_search() const
{
    return  lista_search;
}


  DLinkedList<Gioco*>::list_iterator GestioneGiochi::begin()
{
    isDataSaved=false;
    return  lista_giochi->begin();
  }

  DLinkedList<Gioco*>::list_iterator GestioneGiochi::end()
  {
      isDataSaved=false;
      return lista_giochi->end();
  }

  void GestioneGiochi::setNewPath(string str)
  {
      path= str;
      qDebug() << "prima di destroy in setNewPAth";

  }

  void GestioneGiochi::erase(Gioco *it)
  {
      isDataSaved=false;
      lista_giochi->erase(it);
  }

  void GestioneGiochi::resetSearchRes()
  {
lista_search->clear();
       //lista_search = new DLinkedList<Gioco*>();
  }

  void GestioneGiochi::filterByName(string nome)
  {
      for(auto it= lista_search->begin(); it!= lista_search->end(); ++it){
          if(nome != (*it)->getNome()){
              it = lista_search->erase(it);
                 --it;
          }
      }
  }

  void GestioneGiochi::filterByType(string tipo)
  {
      for(auto it= lista_search->cbegin(); it!= lista_search->cend(); ++it){
          if(tipo != (*it)->getTipo()){
              lista_search->erase(*it);
              --it;
          }
      }
  }

  void GestioneGiochi::filterByPegi(string pegi)
  {
      for(auto it= lista_search->cbegin(); it!= lista_search->cend(); ++it){
          if(pegi != (*it)->getClassificazionePegi()){
              lista_search->erase(*it);
              --it;
          }
      }
  }

  void GestioneGiochi::filterByYear(string year)
  {
      for(auto it= lista_search->cbegin(); it!= lista_search->cend(); ++it){
          if(year != (*it)->getAnnoRilascio()){
              lista_search->erase(*it);
              --it;
          }
      }
  }

  void GestioneGiochi::setSearchList(DLinkedList<Gioco *> * second)
  {
      lista_search = second;
  }
