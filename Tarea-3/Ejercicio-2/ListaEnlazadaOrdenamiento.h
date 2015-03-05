#ifndef ListaEnlazadaOrdenamiento_h
#define ListaEnlazadaOrdenamiento_h

#include "ListaEnlazada.h"

template <class T>

class ListaEnlazadaOrdenada : public ListaEnlazada<T> 
{
    public:
        void insert(T value, bool(*)(T, T));
        static bool asc(T, T);
};

#endif
