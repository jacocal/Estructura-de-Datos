#ifndef Sgal_listaEnlazadaCircular_h
#define Sgal_listaEnlazadaCircular_h

#include "listaEnlazada.cpp"

template <class T>
class ListaEnlazadaCircular : public ListaEnlazada<T>
{
    
protected:
    
    Nodo<T> * ultimo = NULL;
    
public:
    
    ListaEnlazadaCircular() : ListaEnlazada<T>() {}
    
    ~ListaEnlazadaCircular();
    
    void insertAt(T value, int pos) override;
    Nodo<T> * deleteAt(int pos) override;
    
    
    Nodo<T> * getUltimo();
    
    Nodo<T> * search(T value) override;
    Nodo<T> * searchPrev(T value) override;
    
    void clear() override;
    
    template <class Tn>
    friend std::ostream & operator <<(std::ostream &, ListaEnlazadaCircular<Tn> &);
    
};

#endif
