#include <iostream>
#include <cstddef>
#include "Nodo.h"

template <class T>

Nodo<T>::Nodo() 
{
    this->next = NULL;
}

template <class T>

Nodo<T>::Nodo(T dato) : dato(dato) 
{
    this->next = NULL;
}

template <class T>

Nodo<T> * Nodo<T>::getNext() 
{
    return next;
}

template <class T>

T Nodo<T>::getDato()
{
    return dato;
}

template <class T>

void Nodo<T>::setNext(Nodo<T> * value)
{
    next = value;
}

template <class T>

void Nodo<T>::setDato(T value) 
{
    dato = value;
}

template <class T>

std::ostream& operator <<(std::ostream& os, Nodo<T>& nodo)
{
    os << nodo.dato;
    return os;
}
