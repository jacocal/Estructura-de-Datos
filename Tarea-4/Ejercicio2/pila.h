#ifndef Sgal_pila_h
#define Sgal_pila_h

#include <iostream>
#include "listaEnlazada.h"

template <class T>
class Pila : protected ListaEnlazada<T> 
{
public:

    Pila();
    ~Pila();
    
    void push(T value);
    Nodo<T> * pop();
    Nodo<T> * top();
    
    int size() override;
    bool empty() override;
    
    bool operator!=(Pila<T> l);
    
    template <class Tn>
    friend std::ostream& operator<< (std::ostream&, Pila<Tn>&);
};

#endif
