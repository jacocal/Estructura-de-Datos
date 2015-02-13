#include<iostream>
#include<ostream>
#include<algorithm>
#include "Libro.h"
#include "Ordenamiento.h"

int main(){
    const int n = 10;
    int enteros[n];
    
    Libro libro[n];
    libro[0] = Libro("El Padrino", "Mario Puzzo", 1969, 212, México 2002);
    libro[1] = Libro("Love is a dog from hell", "Charles Bukowski", 1980, 125, México 1992);
    libro[2] = Libro("La insoportable levedad del ser", "Milan Kundera", 1954, 281, México 1970);
    
    
    for(auto p: libro){
        cout << p;
    }
    
    Ordenamiento<Libro>::seleccion(libro, n, Ordenamiento<Libro>::asc);
    for(auto p: libro){
        cout << p;
    }
    
    return 0;
}
