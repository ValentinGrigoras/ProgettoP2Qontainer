#ifndef GESTIONEGIOCHI_H
#define GESTIONEGIOCHI_H
#include "dlinkedlist.h"
#include "gioco.h"

class GestioneGiochi // il mio modello
{
private:
    DLinkedList<Gioco*> lista_giochi;

public:
    GestioneGiochi();
    ~GestioneGiochi();
    void AggiungiGioco(Gioco*);
    void CancellaGioco(Gioco*);
    void Salva(Gioco*)const;
};

#endif // GESTIONEGIOCHI_H
