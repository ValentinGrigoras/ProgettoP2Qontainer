#ifndef DLINKEDLIST_H
#define DLINKEDLIST_H

#include "Exceptions/invaliditerator.h"
#include "Exceptions/pasttheend.h"
#include<iostream>
#include<qdebug.h>

using namespace std;
template <class T>
class DLinkedList{

private:
    class Nodo{
        public:
            T info;
            Nodo* prev, *next;
            Nodo(); //implica che il costruttore di default di T sia disponibile
            Nodo(const T&, Nodo* =nullptr, Nodo* =nullptr); //
            T& operator*();
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
        const T& operator*() const;
        const T* operator->() const;
        bool operator==(const_list_iterator) const;
            bool operator!=(const_list_iterator) const;


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
      T& operator*() const;
      T* operator->()const;
      //convertitore di tipo: da list_iterator a const_list_iterator
      operator const_list_iterator()const;
      bool operator==(list_iterator) const;
          bool operator!=(list_iterator) const;

    };
DLinkedList();

void Destroy();//distruttore
void PrintAll();
    bool operator== (const DLinkedList<T>&)const;
    bool operator!= (const DLinkedList<T>&)const;

    bool isEmpty()const;

  const_list_iterator cbegin()const;
const_list_iterator cend()const;

 list_iterator begin();
   list_iterator end();

    T& at(unsigned int);

unsigned int getSize() const;

 void clear();
  DLinkedList<T> & operator= (const DLinkedList<T> &);//costruttore di assegnazione

    //METODI DI MODIFICA DEL DOUBLY LINKED LIST
    void push_back(const T& ogg);
    void push_front(const T& ogg);
    void pop_back();
    void pop_front();

    list_iterator erase(list_iterator it);
    void erase(T);
    list_iterator insert(list_iterator it, const T& ogg);

    friend const_list_iterator;
    friend list_iterator;

};
template <class T>
DLinkedList<T>::Nodo::Nodo(): prev(nullptr), next(nullptr) {}

template <class T>
DLinkedList<T>::Nodo::Nodo(const T& i, Nodo* p, Nodo* n): info(i), prev(p), next(n) {}

template <class T>
T& DLinkedList<T>::Nodo::operator*(){
    return info;
}

template <class T>
DLinkedList<T>::DLinkedList(): first(nullptr),last(nullptr) {}
//implementazione metodi di list_iterator
//COSTRUTTORE DI DEFAULT
template<class T>
DLinkedList<T>::list_iterator::list_iterator(): p(nullptr), past_the_end(false){}

//COSTRUTTORE A 1,2,3 PARAMETRI
template<class T>
DLinkedList<T>::list_iterator::list_iterator(Nodo* ptr, bool pte):p(ptr), past_the_end(pte){}

template <class T>
DLinkedList<T>::const_list_iterator::const_list_iterator(): cp(nullptr), past_the_end(false) {}

template <class T>
DLinkedList<T>::const_list_iterator::const_list_iterator(Nodo * i, bool p): cp(i), past_the_end(p) {}

//OPERATORE DI ACCESSO A MEMBRO DI LIST:ITERATOR
template <class T>
T* DLinkedList<T>::list_iterator::operator->() const {return &(p->info);} // gli do l'indirizzo dell'oggetto

//OPERATORE DI DEREFERENZIAZIONE DI LIST_ITERATOR
template<class T>
T& DLinkedList<T>::list_iterator::operator*() const {return p->info;}



//OPERATORE DI DEREFERENZIAZIONE DI LIST_ITERATOR
template <class T>
const T& DLinkedList<T>::const_list_iterator::operator*() const{
    return cp->info;
}
//OPERATORE DI ACCESSO A MEMBRO DI LIST:ITERATOR
template <class T>
const T* DLinkedList<T>::const_list_iterator::operator->() const{
    return &(cp->info);
}

//OPERATORE PRE INCREMENTO
template<class T>
typename DLinkedList<T>::list_iterator& DLinkedList<T>::list_iterator::operator++(){

    qDebug() <<"sono in operator++ di dlinked";
    if(past_the_end) throw PastTheEnd();

        if(!p) throw InvalidIterator();

            if(p->next) p=p->next; else{ p=p+1; past_the_end=true;}
     return *this;
}

//OPERATORE POST INCREMENTO
template<class T>
typename DLinkedList<T>::list_iterator DLinkedList<T>::list_iterator::operator++(int){
qDebug() <<"sono in operator++ post di dlinked";
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
    qDebug() <<"sono in operator-- di dlinked";
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
    qDebug() <<"sono in operator-- post  di dlinked";
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

////METODO BEGIN DEL CONST_LIST_ITERATOR
template <class T>
typename DLinkedList<T>::const_list_iterator DLinkedList<T>::cbegin()const{
  return const_list_iterator(first);
}

//METODO END DEL LIST_ITERATOR
template <class T>
typename DLinkedList<T>::list_iterator DLinkedList<T>::end(){
  return list_iterator(last+1,true);
}

////METODO END DEL CONST_LIST_ITERATOR
template <class T>
typename DLinkedList<T>::const_list_iterator DLinkedList<T>::cend()const{
  return const_list_iterator(last+1);
}
//OPERATORE PRE INCREMENTO
template<class T>
typename DLinkedList<T>::const_list_iterator& DLinkedList<T>::const_list_iterator::operator++(){
    qDebug() <<"sono in operator++ pre di dlinked";

    if(past_the_end) throw PastTheEnd();

        if(!cp)
        {
            qDebug() << "sono in pre";
            throw InvalidIterator();
}
            if(cp->next) cp=cp->next; else{ cp=cp+1; past_the_end=true;}
     return *this;
//    if(!past_the_end && cp) {
//  if(cp->next == nullptr) {cp = cp+1; past_the_end=true;}
//  else cp = cp->next;
//    }
//    return *this;
}

//OPERATORE POST INCREMENTO
template<class T>
typename DLinkedList<T>::const_list_iterator DLinkedList<T>::const_list_iterator::operator++(int){
qDebug() <<"sono in operator++ post di dlinked";
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

    qDebug() <<"sono in operator-- pre  di dlinked";
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
    qDebug() <<"sono in operator --  di dlinked";
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
template <class T>
void DLinkedList<T>::push_back(const T& t){
    qDebug() <<"sono in pushback di dlinked";
    last=new Nodo(t,last,nullptr);
    first==nullptr ? first=last : (last->prev)->next=last;
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
if(first){
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
}
//POP FRONT DI DLINKED LIST
template <class T>
void DLinkedList<T>::pop_front(){
    qDebug() << "sono dentro pop front di dlist";
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
    qDebug() <<"sono in erase di dlinked";
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
qDebug() <<"sono in insert  di dlinked";
    if(it.p==first)
    {
        push_front(ogg);
        it.p=first;
    }
    else if(it.past_the_end)
    {
        push_back(ogg);
        it.p=last;
    }
    else{
        it.p->prev->next = new Nodo(ogg,it.p->prev,it.p);
        it.p->prev = it.p->prev->next;
        it--;
    }
return it;

}
template <class T>
bool DLinkedList<T>::list_iterator::operator==(typename DLinkedList<T>::list_iterator it) const{
  return p==it.p;
}
template <class T>
bool DLinkedList<T>::list_iterator::operator!=(typename DLinkedList<T>::list_iterator it) const{
  return p!=it.p;
}
template <class T>
bool DLinkedList<T>::const_list_iterator::operator==(typename DLinkedList<T>::const_list_iterator it) const{
    return cp==it.cp;
}
template <class T>
bool DLinkedList<T>::const_list_iterator::operator!=(typename DLinkedList<T>::const_list_iterator it) const{
    return cp!=it.cp;
}
template <typename T>
void DLinkedList<T>::erase(T oggetto){
    qDebug() <<"sono in erase";
    for(auto it= begin() ; (*it)!= oggetto && it!=end(); ++it){
         if ((*it)== oggetto)return erase(oggetto);
    }

}

template <typename T>
T& DLinkedList<T>::at(unsigned int index){
auto it = begin();
unsigned int i = 0;
while(it!= end() &&  i != index)
{
    qDebug() << "sono in at method";
    ++it;
    i++;
}
    return *it;
}
template <typename T>
unsigned int DLinkedList<T>::getSize()const{
    unsigned int dim = 0;
for(auto it = cbegin(); it!=cend(); ++it){
    qDebug() << "Sono dentro getSize di DList";
    dim++;
}
return dim;
}
template <typename T>
void DLinkedList<T>::clear(){
  while(!isEmpty())
      qDebug() << "Sono dentro clear di DList";
      pop_front();
    }



template<typename T>
void DLinkedList<T>::Destroy(){
    while(first == nullptr){
        pop_back();
    }
}

template <typename T>
DLinkedList<T>& DLinkedList<T>::operator=(const DLinkedList<T>& t){
    qDebug() <<"sono in operator= di dlinked";
if (this != &t)
{
    clear();
    for(const_list_iterator cit = t.cbegin(); cit !=t.cend(); ++cit)
        push_back(*cit);
}
     return *this;
}
template<typename T>
void DLinkedList<T>::PrintAll(){
    qDebug() <<"sono in PrintAll di container";
    if(isEmpty())  qDebug() <<"La lista è vuota";
    else{
    for(auto it = begin(); it!=end(); ++it){
        qDebug() << *it << endl;
    }
    }
}

#endif // DLINKEDLIST_H




