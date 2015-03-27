#ifndef listaEnlazada_listaEnlazada_h
#define listaEnlazada_listaEnlazada_h

#include <iostream>
#include "nodo.cpp"

template <class T>
class ListaEnlazada
{
    
protected:
    
    Nodo<T> * inicio = NULL;
    int tamano = 0;
    
    void copy(const ListaEnlazada<T> &);
    
    class Iterator
    {
        ListaEnlazada<T> * data;
        int position;
    public:
        
        Iterator(ListaEnlazada<T> * data, int position) : data(data), position(position) { }
        
        Nodo<T> operator*() const { return *(data->at(position)); }
        const Iterator& operator++() { ++position; return *this; }
        bool operator!=(const Iterator& it) const { return position != it.position; }
    };
    
public:
    
    ListaEnlazada();
    ListaEnlazada(const ListaEnlazada<T> &);
    ~ListaEnlazada();
    
    Nodo<T> * start();
    virtual int size();
    virtual bool empty();
    
    void insertFront(T value);
    void insertBack(T value);
    virtual void insertAt(T value, int pos);
    
    Nodo<T> * deleteFront();
    Nodo<T> * deleteBack();
    virtual Nodo<T> * deleteAt(int pos);
    
    virtual Nodo<T> * search(T value);
    virtual Nodo<T> * searchPrev(T value);
    
    Nodo<T> * at(int pos);
    Nodo<T> * atPrev(int pos);
    
    
    virtual void clear();
    Nodo<T> * operator[](const int i);
    const ListaEnlazada<T> operator=(const ListaEnlazada<T> &);
    
    
    template <class Tn>
    friend std::ostream& operator<< (std::ostream&, ListaEnlazada<Tn>&);
    
    Iterator begin() { return { this, 0 }; }
    Iterator end() { return { this, tamano }; }
    
};

#endif
