#ifndef Sgal_cola__
#define Sgal_cola__

#include <stdio.h>
#include <iostream>
#include "listaEnlazada.h"

using namespace std;

template <class T>
class Cola: protected ListaEnlazada<T>
{
    
public:
    Cola(); 
    ~Cola(); 
    void enqueue(T n);
    Nodo<T> * inicio();
    Nodo<T> * dequeue();
    int size() override;
    bool empty() override; 


    template <class Tn>
    friend std::ostream & operator <<(std::ostream &, Cola<Tn> &);  
    
};

#endif 
