#ifndef LIST_ITERATOR_H
#define LIST_ITERATOR_H
#include "nodo.h"
template<class T>

class list_iterator{
private:
    Nodo<T> * ptr;
    bool past_the_end;
    list_iterator(const Nodo<T> * p=nullptr, bool pte=false);
public:
    list_iterator();

};

#endif // LIST_ITERATOR_H
