#ifndef l_listaEnlazada_h
#define l_listaEnlazada_h

#include <iostream>
#include "Nodo.cpp"

template <class T>
class ListaEnlazada 
{
protected:

    Nodo<T> * inicio = NULL;
    int rango = 0;
    
public:

    ListaEnlazada();
    ~ListaEnlazada();
    Nodo<T> * start();
    int size();
    bool empty();
    void insertFront(T value);
    void insertBack(T value);
    void insertAt(T value, int pos);
    void clear();
    Nodo<T> * search(T value);
    Nodo<T> * searchPrev(T value);
    Nodo<T> * at(int pos);
    Nodo<T> * atPrev(int pos);
    Nodo<T> * deleteAt(int pos);
    Nodo<T> * deleteFront();
    Nodo<T> * deleteBack();
    
    Nodo<T> * operator[](const int i);
    
    template <class Tn>
    friend std::ostream& operator<< (std::ostream&, ListaEnlazada<Tn>&);
};

#endif
