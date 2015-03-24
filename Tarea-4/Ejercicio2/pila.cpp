#include "pila.h"

template <class T>
Pila<T>::Pila() : ListaEnlazada<T>() { }

template <class T>
Pila<T>::~Pila() {
    this->clear();
}

template <class T>
void Pila<T>::push(T value) {
    this->insertFront(value);
}

template <class T>
Nodo<T> * Pila<T>::pop() {
    return this->deleteFront();
}

template <class T>
Nodo<T> * Pila<T>::top() {
    return this->start();
}

template <class T>
int Pila<T>::size() {
    return ListaEnlazada<T>::size();
}

template <class T>
bool Pila<T>::empty() {
    return ListaEnlazada<T>::empty();
}

template <class T>
bool Pila<T>::operator!=(Pila<T> l) {
    return (this->inicio != l.inicio);
}

template <class T>
std::ostream& operator<< (std::ostream& os, Pila<T>& pila) {
    return os;
}
