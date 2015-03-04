//
//  ListaEnlazada.cpp
//  ListaEnlazada
//
//  Created by Sebastián Galguera on 3/1/15.
//  Copyright (c) Sebastián Galguera. All rights reserved.
//

#include <stdio.h>
#include "ListaEnlazada.h"

template <class T>
ListaEnlazada<T>::ListaEnlazada() { }

template <class T>
ListaEnlazada<T>::~ListaEnlazada() {
    clear();
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
void ListaEnlazada<T>::insertAt(T value, int pos) {
    if (pos < 0 || pos > tamano)
        return;
    
    // Insertar al inicio
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
Nodo<T> * ListaEnlazada<T>::at(int pos) {
    int i = 0;
    Nodo<T> * aux = nullptr;
    
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
    Nodo<T> * aux = nullptr;
    
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
Nodo<T> * ListaEnlazada<T>::operator[](const int i) {
    return at(i);
}

template <class T>
std::ostream& operator<< (std::ostream& os, ListaEnlazada<T>& lista) {
    Nodo<T> * aux = lista.inicio;
    
    while (aux) {
        os << *aux << " ";
        aux = aux->getSiguiente();
    }
    return os;
}
