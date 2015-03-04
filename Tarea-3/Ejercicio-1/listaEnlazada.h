//
//  ListaEnlazada.h
//  ListaEnlazada
//
//  Created by Sebastián Galguera on 3/1/15.
//  Copyright (c) 2015 Sebastián Galguera. All rights reserved.
//

#ifndef ListaEnlazada_ListaEnlazada_h
#define ListaEnlazada_ListaEnlazada_h

#include <iostream>
#include "Nodo.cpp"

template <class T>
class ListaEnlazada {
protected:
    Nodo<T> * inicio = nullptr;
    int tamano = 0;
public:
    ListaEnlazada();
    ~ListaEnlazada();
    
    Nodo<T> * start();
    int size();
    bool empty();
    
    void insertAt(T value, int pos);
    void clear();
    Nodo<T> * at(int pos);
    Nodo<T> * atPrev(int pos);
    
    Nodo<T> * operator[](const int i);
    
    template <class Tn>
    friend std::ostream& operator<< (std::ostream&, ListaEnlazada<Tn>&);
};

#endif
