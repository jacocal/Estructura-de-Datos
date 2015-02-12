//
//  Libros.h
//  Libros
//
//  Created by Abraham Cherem on 2/12/15.
//  Copyright (c) 2015 Abraham Cherem. All rights reserved.
//


#ifndef Libros_Libros_H
#define Libros_Libros_H

#include <iostream>
using namespace std;

class Libros {
    string titulo;
    string autor;
    int  numPaginas;
    int edicion;
    string editorial;
    int añoPublicacion;
    
public:
    Libros() {};
    Libros(string titulo, string autor, int  numPaginas, int edicion, string editorial, int añoPublicacion):titulo(titulo), autor(autor), numPaginas(numPaginas), edicion(edicion), editorial(editorial), añoPublicacion(añoPublicacion){};
   
    
    friend ostream& operator<<(ostream&, Libros&);
    bool operator>(int);
    bool operator<(int);
    
    int getAñoPublicacion();
    string getAutor();
    int getEdicion();
    string getTitulo();
    int getNumPaginas();
    string getEditorial();
    
    static bool mostrarAntes(Libros* arregloLibros[], int aPublicacion, int n);
    static bool mostrarDespues(Libros* arregloLibros[], int aPublicacion, int n);
    static bool mostrarEntre(Libros* arregloLibros[], int inicio, int fin, int n);
    static bool mostrarPorAutor(Libros* arregloLibros[], string autor, int n);
    static bool mostrarPorEditorial(Libros* arregloLibros[], string editorial, int n);
    static int  mostrarPorTitulo(Libros* arregloLibros[], string editorial, int aux);
    
};

#endif //Libros_Libros_H
