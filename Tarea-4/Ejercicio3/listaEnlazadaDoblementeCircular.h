#ifndef Sgal_listaEnlazadaDoblementeCircular_h
#define Sgal_listaEnlazadaDoblementeCircular_h

#include "listaEnlazadaCircular.cpp"

template <class T>
class ListaEnlazadaDoblementeCircular : public ListaEnlazadaCircular<T>
{
    
public:
    
    ListaEnlazadaDoblementeCircular() : ListaEnlazadaCircular<T>() { }
    ListaEnlazadaDoblementeCircular(const ListaEnlazadaDoblementeCircular<T> &);
    ~ListaEnlazadaDoblementeCircular();
    
    void insertAt(T value, int pos) override;
    Nodo<T> * deleteAt(int pos) override;
    
    void copy(const ListaEnlazadaDoblementeCircular<T> &);
    void clear() override;
    
    bool operator!=(ListaEnlazadaDoblementeCircular<T> l);
    const ListaEnlazadaDoblementeCircular<T> & operator=(const ListaEnlazadaDoblementeCircular<T> &);
    
};

#endif
