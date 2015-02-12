//
//  main.cpp
//  Libros
//
//  Created by Abraham Cherem on 2/12/15.
//  Copyright (c) 2015 Abraham Cherem. All rights reserved.
//

#include <iostream>
#include "Libros.h"

using namespace std;

void agregarLibro(Libros* arregloLibros[], int& posLibro);
void eliminarLibro(Libros* arregloLibros[], int& posLibro, int nLibros);
void buscarPorAutor(Libros* arregloLibros[], int nLibros);
void buscarPorEditorial(Libros* arregloLibros[], int nLibros);

int main()
{
    int aux = 0, conmutador;
    const int max = 10;
    Libros* catalogo[max] = {0};
   
    do{
        cout << "Bienvenido a la biblioteca EL Bibliotecario Feliz " << endl;
        cout << "------------------------------------------------- " << endl;
        cout << "Por favor seleccione una opción: " << endl;
        cout << "1. Agregar un libro" << endl;
        cout << "2. Eliminar un libro" << endl;
        cout << "3. Buscar un libro sacado antes de una fecha" << endl;
        cout << "4. Buscar un libro sacado después de una fecha" << endl;
        cout << "5. Buscar un libro sacado entre  dos fechas" << endl;
        cout << "6. Buscar un libro por autor" << endl;
        cout << "7. Buscar un libro por editorial" << endl;
        cout << "8. Salir" << endl;
        cout << "Su selección: ";
        cin >> conmutador;
        switch (conmutador) {
            case 1:
                if (aux > max-1)
                    cout << "Lo sentimos, la memoria está llena." << endl;
                else
                    agregarLibro(catalogo, aux);
                break;
            case 2:
                eliminarLibro(catalogo, aux, max);
                break;
            case 3:
                int fecha;
                cout << "Introduzca el año del libro: ";
                cin >> fecha;
                if (!Libros::mostrarAntes(catalogo, fecha, max))
                    cout << "Lo sentimos, no se encontró ningún libro." << endl;
                break;
            case 4:
                cout << "Introdzca el año del libro: ";
                cin >> fecha;
                if (!Libros::mostrarDespues(catalogo, fecha, max))
                    cout << "No se encontró ningún libro." << endl;
                break;
            case 5:
                int principio, fin;
                cout << "Introduzca el año de comienzo: ";
                cin >> principio;
                cout << "Introduzca el año de fin: ";
                cin >> fin;
                if (!Libros::mostrarEntre(catalogo, principio, fin, max))
                    cout << "Lo sentimos, no se encontró ningún libro." << endl;
                break;
            case 6:
                buscarPorAutor(catalogo, max);
                break;
            case 7:
                buscarPorEditorial(catalogo, max);
                break;
            case 8:
                cout << "¡Gracias por su visita!";
                exit(1);
                break;
            default:
                cout << "Lo sentimos, opción no disponible." << endl;
                break;
        }
    }while(conmutador != 8);
    
    return 0;
}

void agregarLibro(Libros* arregloLibros[], int& aux) {
    string titulo, autor, editorial;
    int paginas, edicion, añoPublicacion;
    cout << "Título del libro: ";
    cin >> titulo;
    cout << "Autor: ";
    cin >> autor;
    cout << "Número de páginas: ";
    cin >> paginas;
    cout << "Edición: ";
    cin >> edicion;
    cout << "Editorial: ";
    cin >> editorial;
    cout << "Año de publicación: ";
    cin >> añoPublicacion;
    arregloLibros[aux++] = new Libros(titulo, autor, paginas, edicion, editorial, añoPublicacion);
}

void eliminarLibro(Libros* arregloLibros[], int& posLibro, int max) {
    string titulo;
    cout << "Por favor, introduzca el título del libro: ";
    cin >> titulo;
    int index = Libros::mostrarPorTitulo(arregloLibros, titulo, max);
    if (index == -1) {
        cout << "Lo sentimos, no se encontró ningún libro." << endl;
        return;
    }
    else {
        delete arregloLibros[index];
        while (index < max - 1 && index + 1 != 0) {
            arregloLibros[index] = arregloLibros[index + 1];
            ++index;
        }
        posLibro = index;
        cout << "Lo sentimos, no se encontró ningún libro." << endl;
    }
}

void buscarPorAutor(Libros* arregloLibros[], int max) {
    string autor;
    cout << "Introduce el autor: ";
    cin >> autor;
    if (!Libros::mostrarPorAutor(arregloLibros, autor, max))
        cout << "Lo sentimos, no se encontró ningún libro." << endl;
}

void buscarPorEditorial(Libros* arregloLibros[], int max) {
    string editorial;
    cout << "Introduce la editorial: ";
    cin >> editorial;
    if (!Libros::mostrarPorEditorial(arregloLibros, editorial, max))
        cout << "Lo sentimos, no se encontró ningún libro." << endl;
}

