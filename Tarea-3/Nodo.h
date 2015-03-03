//
//  Nodo.h
//  ListaEnlazada
//
//  Created by Abraham Cherem on 3/3/15.
//  Copyright (c) 2015 Abraham Cherem. All rights reserved.
//

#ifndef ListaEnlazada_Nodo_h
#define ListaEnlazada_Nodo_h

#include <iostream>

template <class T> class Nodo;
template <class T>
std::ostream& operator<<(std::ostream&, Nodo<T>&);

template <class T>
class Nodo {
    T info;
    Nodo<T> * siguiente;
public:
    Nodo();
    Nodo(T info);
    
    T getInfo();
    void setInfo(T value);
    
    Nodo<T> * getSiguiente();
    void setSiguiente(Nodo<T> * value);
    
    friend std::ostream& operator<< <>(std::ostream&, Nodo<T>&);
};

#endif
