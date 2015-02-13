#pragma once
#include<iostream>
#include<string>
#include<ostream>
using namespace std;

class Libro
{
    private:
        string titulo;
        string editorial;
        int añoPublicacion;
        int numPáginas;
        string edición;
        
    public:
        Libro();
        Persona(string titulo, string editorial,int añoPublicacion, int numPáginas, string edición) :
        titulo (titulo),  editorial(editorial), añoPublicacion(añoPublicacion),  numPaginas(numPaginas),  
        edicion(edicion) {};
        bool operator >(Libro & libro;
        bool operator <(Libro & libro);
        friend ostream & operator << (ostream & os, Libro & libro);

};
