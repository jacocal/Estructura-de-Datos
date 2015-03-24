#include "cola.h"

template <class T>
Cola<T>::Cola():ListaEnlazada<T>()
{
    
}


template <class T>
Cola<T>::~Cola()
{
    this->clear();
}

template <class T>
void Cola<T>::enqueue(T n)
{
    this->insertBack(n);
}

template <class T>
Nodo<T> * Cola<T>::dequeue()
{
    return this->deleteFront();
}

template <class T>
Nodo<T> * Cola<T>::inicio()
{
    return this->start();
}

template <class T>
int Cola<T>::size()
{
    return ListaEnlazada<T>::size();
}

template <class T>
bool Cola<T>::empty()
{
    return ListaEnlazada<T>::empty();
}

template <class T>
std::ostream & operator <<(std::ostream & os, Cola<T> & col)
{
    return os;
}
