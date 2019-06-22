#ifndef GESTIONEGIOCHI_H
#define GESTIONEGIOCHI_H
#include "dlinkedlist.h"
#include "gioco.h"
#include<QtXml>
class GestioneGiochi // il mio modello
{
private:
    DLinkedList<Gioco*>  *lista_giochi;
        bool isDataSaved;
   string path;
public:
    GestioneGiochi(string ="../P2Progetto/ProgettoP2Qontainer/Model/data2.xml");
    ~GestioneGiochi();

    void push_end(Gioco *);
     void saveToFile() ;// non e' const poiche modifica il flag isDataSaved
void loadFromFile(string path);

     Gioco* elementAt(unsigned int);

     string getPath()const;
     bool getIsDataSaved() const;
     void setDataSaved(bool);
     void clear();

     void printAll()const;

     unsigned int getDataSize()const;
         DLinkedList<Gioco*>  * GetLista_giochi() const;

     DLinkedList<Gioco*>::list_iterator begin();
    DLinkedList<Gioco*>::list_iterator end();
    DLinkedList<Gioco*>::const_list_iterator cbegin()const;
   DLinkedList<Gioco*>::const_list_iterator cend()const;


   void setNewPath(string );

   void erase(Gioco*);
};

#endif // GESTIONEGIOCHI_H
