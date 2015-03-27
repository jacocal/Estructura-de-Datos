#ifndef T4E4_nodo_h
#define T4E4_nodo_h

#include <iostream>

template <class T> class Nodo;
template <class T>
std::ostream& operator<<(std::ostream&, Nodo<T>&);

template <class T>
class Nodo
{
    T info;
    Nodo<T> * anterior;
    Nodo<T> * siguiente;
    
public:
    
    Nodo();
    Nodo(T info);
    
    T getInfo();
    
    void setInfo(T value);
    void setSiguiente(Nodo<T> * value);
    void setAnterior(Nodo<T> * value);
    
    Nodo<T> * getSiguiente();
    Nodo<T> * getAnterior();
    
    friend std::ostream& operator<< <>(std::ostream&, Nodo<T>&);
    
};

#endif
