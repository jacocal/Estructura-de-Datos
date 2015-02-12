//
//  Libros.cpp
//  Libros
//
//  Created by Abraham Cherem on 2/12/15.
//  Copyright (c) 2015 Abraham Cherem. All rights reserved.
//

#include "Libros.h"

using namespace std;


bool Libros::operator<(int fecha) {
    return añoPublicacion < fecha;
}

bool Libros::operator>(int fecha) {
    return añoPublicacion > fecha;
}


int Libros::getAñoPublicacion()
{
    return añoPublicacion;
}

string Libros::getAutor()
{
    return autor;
}

int Libros::getEdicion()
{
    return edicion;
}

string Libros::getTitulo()
{
    return titulo;
}

int Libros::getNumPaginas()
{
    return numPaginas;
}

string Libros::getEditorial()
{
    return editorial;
}

ostream& operator<<(ostream& os, Libros& Libros) {
    os << Libros.titulo;
    return os;
}

bool Libros::mostrarAntes(Libros* arregloLibros[], int añoPublicacion, int aux) {
    bool search = false;
    for (int i = 0; i < aux; ++i) {
        if (arregloLibros[i] != 0 && *(arregloLibros[i]) < añoPublicacion) {
            cout << *arregloLibros[i] << endl;
            search = true;
        }
    }
    return search;
}

bool Libros::mostrarDespues(Libros* arregloLibros[], int añoPublicacion, int aux) {
    bool search = false;
    for (int i = 0; i < aux; ++i) {
        if (arregloLibros[i] != 0 && *(arregloLibros[i]) > añoPublicacion) {
            cout << *arregloLibros[i] << endl;
            search = true;
        }
    }
    return search;
}

bool Libros::mostrarEntre(Libros* arregloLibros[], int principio, int fin, int aux) {
    bool search = false;
    for (int i = 0; i < aux; ++i) {
        if (arregloLibros[i] != 0 && *(arregloLibros[i]) > principio && *(arregloLibros[i]) < fin) {
            cout << *arregloLibros[i] << endl;
            search = true;
        }
    }
    return search;
}

bool Libros::mostrarPorAutor(Libros* arregloLibros[], string autor, int aux) {
    bool search = false;
    for (int i = 0; i < aux; ++i) {
        if (arregloLibros[i] != 0 && arregloLibros[i]->getAutor() == autor) {
            cout << *arregloLibros[i] << endl;
            search = true;
        }
    }
    return search;
}

bool Libros::mostrarPorEditorial(Libros* arregloLibros[], string editorial, int aux) {
    bool search = false;
    for (int i = 0; i < aux; ++i) {
        if (arregloLibros[i] != 0 && arregloLibros[i]->getEditorial() == editorial) {
            cout << *arregloLibros[i] << endl;
            search = true;
        }
    }
    return search;
}

int Libros::mostrarPorTitulo(Libros* arregloLibros[], string titulo, int max) {
    int i = 0;
    int encontrado = -1;
    while (i < max && encontrado == -1) {
        if (arregloLibros[i] != 0 && arregloLibros[i]->getTitulo() == titulo) {
            encontrado = i;
        }
        ++i;
    }
    return encontrado;
}

