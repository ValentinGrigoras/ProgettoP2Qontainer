#ifndef GESTIONEGIOCHI_H
#define GESTIONEGIOCHI_H
#include "dlinkedlist.h"
#include "gioco.h"

class GestioneGiochi // il mio modello
{
private:
    DLinkedList<Gioco*> * lista_giochi;
        bool isDataSaved;
   string path;
public:
    GestioneGiochi(string ="../P2Qantainer/dati.xml");
    ~GestioneGiochi();
    void AggiungiGioco(Gioco*);
    void CancellaGioco(Gioco*);
    void Salva(Gioco*)const;

    void push_end(Gioco *);

     void save();// non e' const poiche modifica il flag isDataSaved
     bool getIsDataSaved() const;
     void setDataSaved(bool);

     DLinkedList<Gioco*>::list_iterator begin();
    DLinkedList<Gioco*>::list_iterator end();
    DLinkedList<Gioco*>::const_list_iterator cbegin()const;
   DLinkedList<Gioco*>::const_list_iterator cend()const;
};

#endif // GESTIONEGIOCHI_H
