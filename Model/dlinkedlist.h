#ifndef DLINKEDLIST_H
#define DLINKEDLIST_H
#include "exceptions.h"
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
    class const_list_iterator{
        friend DLinkedList;
    private:
        const Nodo* cp;
        bool past_the_end;
        const_list_iterator(Nodo* p=nullptr, bool pte=false);
    public:
        const_list_iterator();
        const_list_iterator& operator++();
        const_list_iterator operator++(int);
        const_list_iterator& operator--();
        const_list_iterator operator--(int);
        const Nodo& operator*() const;
        const Nodo* operator->() const;
    };

    class list_iterator{
        friend DLinkedList;
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
      Nodo& operator*() const;
      Nodo* operator->()const;
      //convertitore di tipo: da list_iterator a const_list_iterator
      operator const_list_iterator()const;
    };

    bool operator== (const DLinkedList<T>&)const;
    bool operator!= (const DLinkedList<T>&)const;

    bool isEmpty()const;

    list_iterator begin();
    const_list_iterator begin()const;

    list_iterator end();
    const_list_iterator end()const;

    //METODI DI MODIFICA DEL DOUBLY LINKED LIST
    void push_back(const T& ogg);
    void push_front(const T& ogg);
    void pop_back();
    void pop_front();

    list_iterator erase(list_iterator it);
    list_iterator insert(list_iterator it, const T& ogg);

    friend const_list_iterator;
    friend list_iterator;

};
//implementazione metodi di nodo
//COSTRUTTORE DI DEFAULT
template <class T>
DLinkedList<T>::Nodo::Nodo():next(nullptr), prev(nullptr){}

//COSTRUTTORE A 1,2,3 PARAMETRI
template<class T>
DLinkedList<T>::Nodo::Nodo(const T& i, Nodo* n, Nodo* p):info(i), next(n), prev(p){}

//implementazione metodi di list_iterator
//COSTRUTTORE DI DEFAULT
template<class T>
DLinkedList<T>::list_iterator::list_iterator(): p(nullptr), past_the_end(false){}

//COSTRUTTORE A 1,2,3 PARAMETRI
template<class T>
DLinkedList<T>::list_iterator::list_iterator(Nodo* ptr, bool pte):p(ptr), past_the_end(pte){}

//OPERATORE DI DEREFERENZIAZIONE DI LIST_ITERATOR
template<class T>
typename DLinkedList<T>::Nodo& DLinkedList<T>::list_iterator::operator*() const {return &p;}

//OPERATORE DI ACCESSO A MEMBRO DI LIST:ITERATOR
template <class T>
typename DLinkedList<T>::Nodo* DLinkedList<T>::list_iterator::operator->() const {return p;} // gli do l'indirizzo dell'oggetto

//OPERATORE DI DEREFERENZIAZIONE DI LIST_ITERATOR
template<class T>
const typename  DLinkedList<T>::Nodo& DLinkedList<T>::const_list_iterator::operator*() const {return &cp;}

//OPERATORE DI ACCESSO A MEMBRO DI LIST:ITERATOR
template <class T>
const typename  DLinkedList<T>::Nodo* DLinkedList<T>::const_list_iterator::operator->() const {return cp;} // gli do l'indirizzo dell'oggetto

//OPERATORE PRE INCREMENTO
template<class T>
typename DLinkedList<T>::list_iterator& DLinkedList<T>::list_iterator::operator++(){
    if(past_the_end) throw PastTheEnd();

        if(!p) throw InvalidIterator();

            if(p->next) p=p->next; else{ p=p+1; past_the_end=true;}
     return *this;
}

//OPERATORE POST INCREMENTO
template<class T>
typename DLinkedList<T>::list_iterator DLinkedList<T>::list_iterator::operator++(int){

   if(past_the_end) throw PastTheEnd();

       if(!p) throw InvalidIterator();

   list_iterator aux(*this);

            if(p->next){
                p=p->next;
            }
             else{ p=p+1; past_the_end=true;}

     return aux;
}
//OPERATORE PRE DECREMENTO
template<class T>
typename DLinkedList<T>::list_iterator& DLinkedList<T>::list_iterator::operator--(){
    if(past_the_end)
    {
        p = p-1;
        past_the_end = false;
    }
    else { (p && !p->prev)? throw InvalidIterator():p=p->prev;}
return *this;
}

//OPERATORE POST DECREMENTO
template<class T>
typename DLinkedList<T>::list_iterator DLinkedList<T>::list_iterator::operator--(int){
list_iterator aux(*this);
if(past_the_end)
{
    p = p-1;
    past_the_end = false;
}
else { (p && !p->prev)? throw InvalidIterator():p=p->prev;}
return aux;

}

//OPERATORE DI CONVERSIONE DA LIST_ITERATOR A CONST_LIST_ITERATOR
template<class T>
DLinkedList<T>::list_iterator::operator const_list_iterator()const{
    return const_list_iterator(p,past_the_end);
}

//METODO BEGIN DEL LIST_ITERATOR
template <class T>
typename DLinkedList<T>::list_iterator DLinkedList<T>::begin(){
  return list_iterator(first,false);
}

//METODO BEGIN DEL CONST_LIST_ITERATOR
template <class T>
typename DLinkedList<T>::const_list_iterator DLinkedList<T>::begin()const{
  return const_list_iterator(first,false);
}

//METODO BEGIN DEL LIST_ITERATOR
template <class T>
typename DLinkedList<T>::list_iterator DLinkedList<T>::end(){
  return list_iterator(last+1,true);
}

//METODO BEGIN DEL CONST_LIST_ITERATOR
template <class T>
typename DLinkedList<T>::const_list_iterator DLinkedList<T>::end()const{
  return const_list_iterator(last+1,true);
}
//OPERATORE PRE INCREMENTO
template<class T>
typename DLinkedList<T>::const_list_iterator& DLinkedList<T>::const_list_iterator::operator++(){
    if(past_the_end) throw PastTheEnd();

        if(!cp) throw InvalidIterator();

            if(cp->next) cp=cp->next; else{ cp=cp+1; past_the_end=true;}
     return *this;
}

//OPERATORE POST INCREMENTO
template<class T>
typename DLinkedList<T>::const_list_iterator DLinkedList<T>::const_list_iterator::operator++(int){

   if(past_the_end) throw PastTheEnd();

       if(!cp) throw InvalidIterator();

   list_iterator aux(*this);

            if(cp->next){
                cp=cp->next;
            }
             else{ cp=cp+1; past_the_end=true;}

     return aux;
}
//OPERATORE PRE DECREMENTO
template<class T>
typename DLinkedList<T>::const_list_iterator& DLinkedList<T>::const_list_iterator::operator--(){
    if(past_the_end)
    {
        cp = cp-1;
        past_the_end = false;
    }
    else { (cp && !cp->prev)? throw InvalidIterator():cp=cp->prev;}
return *this;
}

//OPERATORE POST DECREMENTO
template<class T>
typename DLinkedList<T>::const_list_iterator DLinkedList<T>::const_list_iterator::operator--(int){
    list_iterator aux(*this);
    if(past_the_end)
    {
        cp = cp-1;
        past_the_end = false;
    }
    else { (cp && !cp->prev)? throw InvalidIterator():cp=cp->prev;}
    return aux;

}
//PUSH BACK DI DLINKED LIST
template<class T>
void DLinkedList<T>::push_back(const T& ogg){
    last= new Nodo(ogg, last, nullptr);
    (first == nullptr)? first=last:(last->prev)->next=last;
}
//PUSH FRONT DI DLINKED LIST
template<class T>
void DLinkedList<T>::push_front(const T& ogg){
    first=new Nodo(ogg,nullptr,first);
      last==nullptr ? last=first : (first->next)->prev=first;
}
//POP BACK DI DLINKED LIST
template<class T>
void DLinkedList<T>::pop_back(){
    if (first==last){
        delete first;
        first=last=nullptr;
      }else
      {
        last=last->prev;
        delete last->next;
        last->next=nullptr;
      }
}
//POP FRONT DI DLINKED LIST
template <class T>
void DLinkedList<T>::pop_front(){
    if (first==last){
        delete first;
        first=last=nullptr;
      }else{
        first=first->next;
        delete first->prev;
        first->prev=nullptr;
      }
}

//METODO D'APPOGGIO DI DLINKED LIST
template <class T>
bool DLinkedList<T>::isEmpty()const{
    return first==last;
}

//OPERATORE DI UGUAGLIANZA TRA 2 DLINKED LIST
template<class T>
bool DLinkedList<T>::operator==(const DLinkedList<T>& dl2 )const{
   if(first!=dl2.first || last!= dl2.last) return false;
    Nodo* p_dl1 = first->next;
    Nodo* p_dl2 = dl2.first->next;
    while(p_dl1 && p_dl2){
        if (p_dl1->info!=p_dl2->info)
             return false;
           p_dl1=p_dl1->next; p_dl2=p_dl2->next;

    }
return (!p_dl1 && !p_dl2); //this is dope :)

}
//OPERATORE DI DISUGUAGLIANZA TRA 2 DLINKED LIST
template <class T>
bool DLinkedList<T>::operator!=(const DLinkedList<T>& l) const{
  return !(*this==l);
}
//METODO ERASE DI DILINKED LIST (DA VERIFICARE)
template <class T>
typename DLinkedList<T>::list_iterator DLinkedList<T>::erase(typename DLinkedList<T>::list_iterator it){
      if(it==nullptr)throw InvalidIterator();
list_iterator aux;
      if(*it == first)
      {
          if(!(*it->next)){
          pop_front();
          *it = first=last;
          *it.past_the_end = false;
          return it;
          }
          *aux = *it->next;
          *aux->prev = nullptr;
          delete it;
          return aux;
      }
      else if(*it == last)
      {
          pop_back();
          *it = last+1;
          return nullptr;
      }
      else
      {
          *aux = *it->next;
          *aux->prev = *it->prev;
          delete it;
      }
return aux;
}
template <class T>
typename DLinkedList<T>::list_iterator DLinkedList<T>::insert(typename DLinkedList<T>::list_iterator it, const T& ogg){

    if(*it==first)
    {
        push_front(ogg);
        *it=first;
    }
    else if(*it->past_the_end)
    {
        push_back(ogg);
        *it=last;
    }
    else{
        *it->prev->next = new Nodo(ogg,*it->prev,*it);
        *it->prev = *it->prev->next;
        it--;
    }
return it;

}

#endif // DLINKEDLIST_H
