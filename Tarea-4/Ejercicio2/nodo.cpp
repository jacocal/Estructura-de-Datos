#include <stdio.h>
#include "nodo.h"

template <class T>
Nodo<T>::Nodo() {
    this->siguiente = NULL;
}

template <class T>
Nodo<T>::Nodo(T info) : info(info) {
    this->siguiente = NULL;
}

template <class T>
T Nodo<T>::getInfo() {
    return info;
}

template <class T>
void Nodo<T>::setInfo(T value) {
    info = value;
}

template <class T>
Nodo<T> * Nodo<T>::getSiguiente() {
    return siguiente;
}

template <class T>
void Nodo<T>::setSiguiente(Nodo<T> * value) {
    siguiente = value;
}

template <class T>
std::ostream& operator <<(std::ostream& os, Nodo<T>& nodo) {
    os << nodo.info;
    return os;
}
