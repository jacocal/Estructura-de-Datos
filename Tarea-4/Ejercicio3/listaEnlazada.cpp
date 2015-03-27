#include "listaEnlazada.h"


template <class T>
ListaEnlazada<T>::ListaEnlazada() { }

template <class T>
ListaEnlazada<T>::ListaEnlazada(const ListaEnlazada<T> &l) {
    copy(l);
}

template <class T>
ListaEnlazada<T>::~ListaEnlazada() {
    clear();
}

template <class T>
void ListaEnlazada<T>::copy(const ListaEnlazada<T> & l) {
    inicio = NULL;
    tamano = 0;
    Nodo<T> * aux = l.inicio;
    while (aux) {
        this->insertBack(aux->getInfo());
        aux = aux->getSiguiente();
    }
}

template <class T>
Nodo<T> * ListaEnlazada<T>::start() {
    return inicio;
}

template <class T>
int ListaEnlazada<T>::size() {
    return tamano;
}

template <class T>
bool ListaEnlazada<T>::empty() {
    return (tamano == 0);
}


template <class T>
void ListaEnlazada<T>::insertFront(T value) {
    insertAt(value, 0);
}

template <class T>
void ListaEnlazada<T>::insertBack(T value) {
    insertAt(value, tamano);
}

template <class T>
void ListaEnlazada<T>::insertAt(T value, int pos) {
    if (pos < 0 || pos > tamano)
        return;
    
    if (pos == 0) {
        Nodo<T> * nuevo = new Nodo<T>(value);
        nuevo->setSiguiente(inicio);
        inicio = nuevo;
    }
    else {
        Nodo<T> * prev = atPrev(pos);
        Nodo<T> * nuevo = new Nodo<T>(value);
        nuevo->setSiguiente(prev->getSiguiente());
        prev->setSiguiente(nuevo);
    }
    ++tamano;
}


template <class T>
Nodo<T> * ListaEnlazada<T>::deleteFront() {
    return deleteAt(0);
}

template <class T>
Nodo<T> * ListaEnlazada<T>::deleteBack() {
    return deleteAt(tamano-1);
}

template <class T>
Nodo<T> * ListaEnlazada<T>::deleteAt(int pos) {
    if (pos < 0 || pos >= tamano)
        return NULL;
    
    Nodo<T> * borrado = NULL;
    if (pos == 0) {
        borrado = inicio;
        inicio = inicio->getSiguiente();
    }
    else {
        Nodo<T> * prev = atPrev(pos);
        borrado = prev->getSiguiente();
        prev->setSiguiente(borrado->getSiguiente());
    }
    
    borrado->setSiguiente(NULL);
    --tamano;
    return borrado;
}



template <class T>
Nodo<T> * ListaEnlazada<T>::search(T value) {
    Nodo<T> * aux = inicio;
    while (aux && aux->getInfo() != value) {
        aux = aux->getSiguiente();
    }
    return aux;
}

template <class T>
Nodo<T> * ListaEnlazada<T>::searchPrev(T value) {
    Nodo<T> * aux = inicio;
    Nodo<T> * prev = aux;
    
    while (aux && aux->getInfo() != value) {
        prev = aux;
        aux = aux->getSiguiente();
    }
    return prev;
}

template <class T>
Nodo<T> * ListaEnlazada<T>::at(int pos) {
    int i = 0;
    Nodo<T> * aux = NULL;
    
    if (pos < 0 || pos >= tamano)
        return aux;
    
    aux = inicio;
    while (i < pos) {
        aux = aux->getSiguiente();
        ++i;
    }
    return aux;
}

template <class T>
Nodo<T> * ListaEnlazada<T>::atPrev(int pos) {
    int i = 0;
    Nodo<T> * aux = NULL;
    
    if (pos < 0 || pos > tamano)
        return aux;
    
    aux = inicio;
    while (i < pos-1) {
        aux = aux->getSiguiente();
        ++i;
    }
    return aux;
}

template <class T>
void ListaEnlazada<T>::clear() {
    Nodo<T> * aux;
    while (inicio) {
        aux = inicio;
        inicio = inicio->getSiguiente();
        delete aux;
    }
    tamano = 0;
}

template <class T>
Nodo<T> * ListaEnlazada<T>::operator[](const int i) {
    return at(i);
}

template <class T>
const ListaEnlazada<T> ListaEnlazada<T>::operator=(const ListaEnlazada<T> & l) {
    this->clear();
    copy(l);
    return l;
}

template <class T>
std::ostream& operator<< (std::ostream& os, ListaEnlazada<T>& lista) {
}
