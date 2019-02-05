#include "gestionegiochi.h"

GestioneGiochi::GestioneGiochi()
{

}

GestioneGiochi::~GestioneGiochi()
{
    for (DLinkedList<Gioco*>::list_iterator it = lista_giochi.begin(); it != lista_giochi.end(); it++)
            delete *it;

}
