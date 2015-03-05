#include <iostream>
#include "ListaEnlazada.h"

template <class T>

ListaEnlazada<T>::ListaEnlazada()
{ 
}

template <class T>

ListaEnlazada<T>::~ListaEnlazada() 
{
    clear();
}

template <class T>

Nodo<T> * ListaEnlazada<T>::start()
{
    return inicio;
}

template <class T>

int ListaEnlazada<T>::size() 
{
    return rango;
}

template <class T>

bool ListaEnlazada<T>::empty()
{
    return (rango == 0);
}

template <class T>

void ListaEnlazada<T>::insertFront(T value)
{
    insertAt(value, 0);
}

template <class T>

void ListaEnlazada<T>::insertBack(T value) 
{
    insertAt(value, rango);
}

template <class T>

void ListaEnlazada<T>::insertAt(T value, int pos)
{
    if (pos < 0 || pos > rango)
    {
        return;
    }
    
    if (pos == 0)
    {
        Nodo<T> * nuevo = new Nodo<T>(value);
        nuevo->setNext(inicio);
        inicio = nuevo;
    }
    
    else 
    {
        Nodo<T> * prev = atPrev(pos);
        Nodo<T> * nuevo = new Nodo<T>(value);
        nuevo->setNext(prev->getNext());
        prev->setNext(nuevo);
    }
    
    ++rango;
}

template <class T>

void ListaEnlazada<T>::clear() 
{
    Nodo<T> * aux;
    while (inicio) 
    {
        aux = inicio;
        inicio = inicio->getNext();
        delete aux;
    }
    rango = 0;
}

template <class T>

Nodo<T> * ListaEnlazada<T>::search(T value)
{
    Nodo<T> * aux = inicio;
    while (aux && aux->getDato != value)
    {
        aux = aux->getNext;
    }
    return aux;
}

template <class T>

Nodo<T> * ListaEnlazada<T>::searchPrev(T value)
{
    Nodo<T> * aux = inicio;
    Nodo<T> * prev = aux;
    
    while (aux && aux->getDato != value) 
    {
        prev = aux;
        aux = aux->getNext;
    }
    return prev;
}

template <class T>

Nodo<T> * ListaEnlazada<T>::at(int pos) 
{
    int i = 0;
    Nodo<T> * aux = NULL;
    
    if (pos < 0 || pos >= rango)
    {
        return aux;
    }
    aux = inicio;
    while (i < pos)
    {
        aux = aux->getNext();
        ++i;
    }
    return aux;
}

template <class T>

Nodo<T> * ListaEnlazada<T>::atPrev(int pos) 
{
    int i = 0;
    Nodo<T> * aux = NULL;
    
    if (pos < 0 || pos > rango)
    {
        return aux;
    }
    aux = inicio;
    while (i < pos-1)
    {
        aux = aux->getNext();
        ++i;
    }
    return aux;
}

template <class T>

Nodo<T> * ListaEnlazada<T>::deleteAt(int pos)
{
    if (pos < 0 || pos >= rango)
    {
        return NULL;
    }
    
    Nodo<T> * borrado = NULL;
    
    if (pos == 0)
    {
        borrado = inicio;
        inicio = inicio->getNext();
    }
    
    else 
    {
        Nodo<T> * prev = atPrev(pos);
        borrado = prev->getNext();
        prev->setNext(borrado->getNext());
    }
    
    borrado->setNext(NULL);
    --rango;
    return borrado;
}

template <class T>

Nodo<T> * ListaEnlazada<T>::deleteFront() 
{
    return deleteAt(0);
}

template <class T>

Nodo<T> * ListaEnlazada<T>::deleteBack()
{
    return deleteAt(rango-1);
}

template <class T>

Nodo<T> * ListaEnlazada<T>::operator[](const int i) 
{
    return at(i);
}

template <class T>
std::ostream& operator<< (std::ostream& os, ListaEnlazada<T>& lista) 
{
    Nodo<T> * aux = lista.inicio;
    
    while (aux)
    {
        os << *aux << " ";
        aux = aux->getNext();
    }
    return os;
}

