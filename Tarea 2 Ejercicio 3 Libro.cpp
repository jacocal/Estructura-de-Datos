#include "Libro.h"

bool Libro::operator < (Libro & libro){
    return titulo < libro.titulo;
}

ostream & operator <<(ostream & os, Libro & libro){
    os << libro.autor << ", " << libro.titulo << libro.año << endl;
    return os;
}

bool Libro::operator >(Libro & libro){
    if (titulo > libro.titulo){
        return true;
    }else if(apellidos == libro.titulo){
        if(titulo < libro.titulo){
            return true;
        }else{
            return false;
        }
    }
    return false;
}
