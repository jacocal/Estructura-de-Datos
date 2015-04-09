#ifndef CircularDoubleLinkedList_h
#define CircularDoubleLinkedList_h

#include "CircularLinkedList.h"
using namespace vcn;

template <class T>
class CircularDoubleLinkedList : public CircularLinkedList<T> {
public:
    CircularDoubleLinkedList() : CircularLinkedList<T>() { }
    CircularDoubleLinkedList(const CircularDoubleLinkedList<T> &);
    ~CircularDoubleLinkedList();
    
    void copy(const CircularDoubleLinkedList<T> &);
    
    void insertAt(T value, int pos) override;
    Node<T> * deleteAt(int pos) override;
    void clear() override;
    const CircularDoubleLinkedList<T> & operator=(const CircularDoubleLinkedList<T> &);
    bool operator!=(CircularDoubleLinkedList<T> l);
};

template <class T>
CircularDoubleLinkedList<T>::CircularDoubleLinkedList(const CircularDoubleLinkedList<T> &l) {
    copy(l);
}

template <class T>
CircularDoubleLinkedList<T>::~CircularDoubleLinkedList<T>() {
    this->clear();
}

template <class T>
void CircularDoubleLinkedList<T>::copy(const CircularDoubleLinkedList<T> &l) {
    this->first = NULL;
    this->last = NULL;
    this->size = 0;
    Node<T> * aux = l.first;
    while (this->size != l.size) {
        this->insertBack(aux->getInfo());
        aux = aux->getNext();
    }
}

template <class T>
void CircularDoubleLinkedList<T>::insertAt(T value, int pos)
{
    if (pos < 0 || pos > this->size)
        return;
    
    // Insertar al first
    if (pos == 0) {
        Node<T> * nuevo = new Node<T>(value);
        nuevo->setNext(this->first);
        this->first = nuevo;
        if (this->size == 0)
            this->last = this->first;
        else
            this->first->getNext()->setPrev(this->first);
        this->last->setNext(this->first);
        this->first->setPrev(this->last);
    }
    else {
        Node<T> * prev = this->atPrev(pos);
        Node<T> * nuevo = new Node<T>(value);
        nuevo->setNext(prev->getNext());
        nuevo->setPrev(prev);
        prev->setNext(nuevo);
        if (pos != this->size)
            nuevo->getNext()->setPrev(nuevo);
        else {
            this->last = this->last->getNext();
            this->first->setPrev(this->last);
        }
    }
    ++this->size;
}

/*template <class T>
 void CircularDoubleLinkedList<T>::insertAt(T value, int pos)
 {
 CircularLinkedList<T>::insertAt(value, pos);
 if (pos == 0)
 this->at(pos)->setPrev(this->last);
 else
 this->at(pos)->setPrev(this->atPrev(pos));
 if (this->size != 1 && pos != this->size-1)
 this->at(pos+1)->setPrev(this->at(pos));
 if (pos == this->size-1)
 this->first->setPrev(this->last);
 }*/

template <class T>
Node<T> * CircularDoubleLinkedList<T>::deleteAt(int pos)
{
    if (pos < 0 || pos >= this->size) {
        return NULL;
    }
    
    Node<T> * deleted = NULL;
    
    if (pos == 0) {
        deleted = this->first;
        
        if (this->size == 1) {
            this->first = this->last = NULL;
        }
        else {
            this->first = this->first->getNext();
            this->last->setNext(this->first);
            this->first->setPrev(this->last);
        }
    }
    else {
        Node<T> * prev = this->atPrev(pos);
        
        if (prev->getNext() == this->last) {
            this->last = prev;
        }
        
        deleted = prev->getNext();
        prev->setNext(deleted->getNext());
        deleted->getNext()->setPrev(prev);
    }
    
    deleted->setNext(NULL);
    deleted->setPrev(NULL);
    
    --this->size;
    
    return deleted;
}

template <class T>
void CircularDoubleLinkedList<T>::clear()
{
    Node<T> * aux;
    
    while (this->first != this->last) {
        aux = this->first;
        this->first = this->first->getNext();
        aux->setPrev(NULL);
        aux->setNext(NULL);
        delete aux;
    }
    
    if (this->last) {
        this->last->setPrev(NULL);
        this->last->setNext(NULL);
        delete this->last;
    }
    
    this->first = this->last = NULL;
    
    this->size = 0;
}

template <class T>
const CircularDoubleLinkedList<T> & CircularDoubleLinkedList<T>::operator=(const CircularDoubleLinkedList<T> &l) {
    this->clear();
    copy(l);
    return l;
}

template <class T>
bool CircularDoubleLinkedList<T>::operator!=(CircularDoubleLinkedList<T> l) {
    return (this->first != l.first);
}

#endif
