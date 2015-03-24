#ifndef listaEnlazadaCircular_listaEnlazadaCircular_h
#define listaEnlazadaCircular_listaEnlazadaCircular_h

#include "listaEnlazada.h"

template <class T>
class ListaEnlazadaCircular : public ListaEnlazada<T> {
protected:
    Nodo<T> * ultimo = NULL;
    
public:
    
    ListaEnlazadaCircular() : ListaEnlazada<T>() {}
    
    ~ListaEnlazadaCircular();
    
    void insertAt(T value, int pos) override;
    Nodo<T> * deleteAt(int pos) override;
    void clear() override;
    
    Nodo<T> * search(T value) override;
    Nodo<T> * searchPrev(T value) override;
    Nodo<T> * last();
    
    template <class Tn>
    friend std::ostream & operator <<(std::ostream &, ListaEnlazadaCircular<Tn> &);
    
};

template <class T>
ListaEnlazadaCircular<T>::~ListaEnlazadaCircular()
{
    clear();
}

template <class T>
void ListaEnlazadaCircular<T>::insertAt(T value, int pos)
{
    ListaEnlazada<T>::insertAt(value, pos);
    
    if (pos == 0) {

        if (this->tamano == 1) {
            ultimo = this->inicio;
        }
        
        ultimo->setSiguiente(this->inicio);
    }
    else if (pos == (this->tamano-1)) {
        ultimo = ultimo->getSiguiente();
        
    }
}

template <class T>
Nodo<T> * ListaEnlazadaCircular<T>::deleteAt(int pos)
{
    if (pos < 0 || pos >= this->tamano) {
        return NULL;
    }
    
    Nodo<T> * borrado = NULL;
    

    if (pos == 0) {
        borrado = this->inicio;
        
        if (this->tamano == 1) {
            this->inicio = ultimo = NULL;
        }
        else {
            this->inicio = this->inicio->getSiguiente();
            ultimo->setSiguiente(this->inicio);
        }
    }
    else { 
        Nodo<T> * prev = this->atPrev(pos);
        
        if (prev->getSiguiente() == ultimo) {
            ultimo = prev;
        }
        
        borrado = prev->getSiguiente();
        prev->setSiguiente( borrado->getSiguiente() );
    }
    
    borrado->setSiguiente(NULL);
    
    --this->tamano;
    
    return borrado;
}

template <class T>
Nodo<T> * ListaEnlazadaCircular<T>::last() {
    return ultimo;
}

template <class T>
void ListaEnlazadaCircular<T>::clear()
{
    Nodo<T> * aux;
    
    while (this->inicio != ultimo) {
        aux = this->inicio;
        this->inicio = this->inicio->getSiguiente();
        aux->setSiguiente(NULL);
        delete aux;
    }
    
    if (ultimo)
    {
        ultimo->setSiguiente(NULL);
        delete ultimo;
    }
    
    this->inicio = ultimo = NULL;
    
    this->tamano = 0;
}

template <class T>
Nodo<T> * ListaEnlazadaCircular<T>::search(T value)
{
    Nodo<T> * aux = this->inicio;
    
    while (aux != ultimo && (aux->getInfo() != value) ) {
        aux = aux->getSiguiente();
    }
    
    if (aux == ultimo && aux && aux->getInfo() != value) {
        return NULL;
    }
    
    return aux;
}

template <class T>
Nodo<T> * ListaEnlazadaCircular<T>::searchPrev(T value)
{
    Nodo<T> * aux = this->inicio;
    Nodo<T> * prev = aux;
    
    while (prev != ultimo && (aux->getInfo() != value) ) {
        prev = aux;
        aux = aux->getSiguiente();
    }
    
    return prev;
}

template <class T>
std::ostream & operator <<(std::ostream & os, ListaEnlazadaCircular<T> & lista)
{
    
    return os;
}


#endif
