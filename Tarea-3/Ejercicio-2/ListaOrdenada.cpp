#include "ListaEnlazadaOrdenada.h"

template <class T>

void ListaEnlazadaOrdenada<T>::insert(T value, bool compara(T, T)) 
{
    Nodo<T> * aux = this->inicio;
    Nodo<T> * nuevo = new Nodo<T>(value);
    
    if (this->rango == 0 || (aux && compara(value, aux->getDato()))) 
    {
        nuevo->setNext(aux);
        this->inicio = nuevo;
    }
    
    else 
    {
        while (aux->getNext() && compara(aux->getNext()->getDato(), value))
        aux = aux->getNext();
        nuevo->setNext(aux->getNext());
        aux->setNext(nuevo);
    }
    ++this->rango;
};

template <class T>

bool ListaEnlazadaOrdenada<T>::asc(T a, T b) 
{
    return (a < b);
}

