#ifndef XMLPARSER_H
#define XMLPARSER_H
#include <QString>
#include "gestionegiochi.h"

class XmlParser
{
private:
    QString filename;
   bool  isDataSaved;
public:
    XmlParser(QString, bool);
     DLinkedList<Gioco*> read() const;
       void write(DLinkedList<Gioco*>&) ;
};

#endif // XMLPARSER_H
