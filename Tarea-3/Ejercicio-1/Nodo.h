//
//  Nodo.h
//  ListaEnlazada
//
//  Created by Sebastián Galguera on 3/1/15.
//  Copyright (c) 2015 Sebastián Galguera. All rights reserved.
//

#ifndef tarea_Nodo_h
#define tarea_Nodo_h

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
