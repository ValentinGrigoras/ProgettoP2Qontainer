#ifndef DLINKEDLIST_H
#define DLINKEDLIST_H

template <class T>
class DLinkedList{
private:
    class Nodo{
    public:
        T info;
        Nodo * next;
        Nodo* prev;
        Nodo(); // implica che il costruttore di default di T sia disponibile
        Nodo(const T&, Nodo * n=nullptr, Nodo * p=nullptr);// costrutture a 1,2,3 parametri
        //mi va bene il distruttore standard

    };
    Nodo * first, *last;
public:
    class list_iterator{
    private:
        Nodo* p;
        bool past_the_end;
        list_iterator(Nodo* ptr=nullptr, bool pte=false);
    public:
      list_iterator();// past the end rappresentato come false in modo da poter fare operator --
      list_iterator& operator++(); // pre-increment, ++iterator
      list_iterator operator++(int); //post-increment, iterator++
      list_iterator& operator--(); //pre-decrement, --iterator
      list_iterator operator--(int); //post-decrement, interator--
      T& operator*() const;
      T* operator->()const;
    };

};
template <class T>
DLinkedList<T>::Nodo::Nodo():next(nullptr), prev(nullptr){}

template<class T>
DLinkedList<T>::Nodo::Nodo(const T& i, Nodo* n, Nodo* p):info(i), next(n), prev(p){}

template<class T>
DLinkedList<T>::list_iterator::list_iterator(): p(nullptr), past_the_end(false){}

template<class T>
DLinkedList<T>::list_iterator::list_iterator(Nodo* ptr, bool pte):p(ptr), past_the_end(pte){}

template<class T>
T& DLinkedList<T>::list_iterator::operator*() const {return p->info;}

template <class T>
T* DLinkedList<T>::list_iterator::operator->()const {return &p->info;} // gli do l'indirizzo dell'oggetto

template<class T>
typename DLinkedList<T>::list_iterator& DLinkedList<T>::list_iterator::operator++(){

}


#endif // DLINKEDLIST_H
