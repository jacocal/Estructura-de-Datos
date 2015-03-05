#ifndef lista__nodo__
#define lista__nodo__
#include <iostream>
#include <cstddef>

template <class T> class Nodo;
template <class T>
std::ostream& operator<<(std::ostream&, Nodo<T>&);

template <class T>

class Nodo
{
    T dato;
    Nodo<T> * next;
    
public:

    Nodo();
    Nodo(T dato);
    T getDato();
    Nodo<T> * getNext();
    void setNext(Nodo<T> * value);
    void setDato(T value);
    friend std::ostream& operator<< <>(std::ostream&, Nodo<T>&);
    
};


#endif 
