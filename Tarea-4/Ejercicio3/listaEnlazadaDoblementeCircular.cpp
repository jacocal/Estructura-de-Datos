#include "listaEnlazadaDoblementeCircular.h"


template <class T>
ListaEnlazadaDoblementeCircular<T>::ListaEnlazadaDoblementeCircular(const ListaEnlazadaDoblementeCircular<T> &l)
{
    copy(l);
}


template <class T>
ListaEnlazadaDoblementeCircular<T>::~ListaEnlazadaDoblementeCircular<T>()
{
    this->clear();
}


template <class T>
void ListaEnlazadaDoblementeCircular<T>::insertAt(T value, int pos)
{
    if (pos < 0 || pos > this->tamano)
        return;
    
    if (pos == 0)
    {
        Nodo<T> * nuevo = new Nodo<T>(value);
        nuevo->setSiguiente(this->inicio);
        this->inicio = nuevo;
        if (this->tamano == 0)
        {
            this->ultimo = this->inicio;
        }
        else
        {
        this->inicio->getSiguiente()->setAnterior(this->inicio);
        }
        this->ultimo->setSiguiente(this->inicio);
        this->inicio->setAnterior(this->ultimo);
    }
    else
    {
        Nodo<T> * prev = this->atPrev(pos);
        Nodo<T> * nuevo = new Nodo<T>(value);
        nuevo->setSiguiente(prev->getSiguiente());
        nuevo->setAnterior(prev);
        prev->setSiguiente(nuevo);
        if (pos != this->tamano)
        {
            nuevo->getSiguiente()->setAnterior(nuevo);
        }
        else
        {
            this->ultimo = this->ultimo->getSiguiente();
        }
            this->inicio->setAnterior(this->ultimo);
    }
    ++this->tamano;
}


template <class T>
Nodo<T> * ListaEnlazadaDoblementeCircular<T>::deleteAt(int pos)
{
    if (pos < 0 || pos >= this->tamano) {
        return NULL;
    }
    
    Nodo<T> * borrado = NULL;
    
    if (pos == 0) {
        borrado = this->inicio;
        
        if (this->tamano == 1) {
            this->inicio = this->ultimo = NULL;
        }
        else {
            this->inicio = this->inicio->getSiguiente();
            this->ultimo->setSiguiente(this->inicio);
            this->inicio->setAnterior(this->ultimo);
        }
    }
    else {
        Nodo<T> * prev = this->atPrev(pos);
        
        if (prev->getSiguiente() == this->ultimo) {
            this->ultimo = prev;
        }
        
        borrado = prev->getSiguiente();
        prev->setSiguiente(borrado->getSiguiente());
        borrado->getSiguiente()->setAnterior(prev);
    }
    
    borrado->setSiguiente(NULL);
    borrado->setAnterior(NULL);
    
    --this->tamano;
    
    return borrado;
}


template <class T>
void ListaEnlazadaDoblementeCircular<T>::copy(const ListaEnlazadaDoblementeCircular<T> &l)
{
    this->inicio = NULL;
    this->ultimo = NULL;
    this->tamano = 0;
    Nodo<T> * aux = l.inicio;
    while (this->tamano != l.tamano)
    {
        this->insertBack(aux->getInfo());
        aux = aux->getSiguiente();
    }
}


template <class T>
void ListaEnlazadaDoblementeCircular<T>::clear()
{
    Nodo<T> * aux;
    
    while (this->inicio != this->ultimo)
    {
        aux = this->inicio;
        this->inicio = this->inicio->getSiguiente();
        aux->setAnterior(NULL);
        aux->setSiguiente(NULL);
        delete aux;
    }
    
    if (this->ultimo)
    {
        this->ultimo->setAnterior(NULL);
        this->ultimo->setSiguiente(NULL);
        delete this->ultimo;
    }
    
    this->inicio = this->ultimo = NULL;
    
    this->tamano = 0;
}


template <class T>
bool ListaEnlazadaDoblementeCircular<T>::operator!=(ListaEnlazadaDoblementeCircular<T> l)
{
    return (this->inicio != l.inicio);
}


template <class T>
const ListaEnlazadaDoblementeCircular<T> & ListaEnlazadaDoblementeCircular<T>::operator=(const ListaEnlazadaDoblementeCircular<T> &l)
{
    this->clear();
    copy(l);
    return l;
}

