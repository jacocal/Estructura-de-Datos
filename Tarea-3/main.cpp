//
//  main.cpp
//  ListaEnlazada
//
//  Created by Abraham Cherem on 3/3/15.
//  Copyright (c) 2015 Abraham Cherem. All rights reserved.
//

#include <iostream>
#include "ListaEnlazada.cpp"

using namespace std;

void invertir(Nodo<int> * inicio) {
    if (!inicio->getSiguiente()) {
        cout << *inicio << " ";
        return;
    }
    invertir(inicio->getSiguiente());
    cout << *inicio << " ";
}

int main()
{
    
    cout << "Bienvenido a la máquina para invertir T9-00219" << endl;
    cout << "Por favor ingrese los valores límites de primos:\n " << endl;
    cout << "Valor Inicial: ";
    int limiteInicial;
    cin >> limiteInicial;
    cout << "Valor Final: ";
    int limiteFinal;
    cin >> limiteFinal;
    cout << endl;
    ListaEnlazada<int> * lista = new ListaEnlazada<int>;
    
    
    
    int pos;
    for (int prime = 2; prime < 100; prime++)
        for (int primeProve =2; primeProve < prime; primeProve++)
        {
            if (prime % primeProve == 0)
            {
                break;
            }
            else if (prime == primeProve +1)
            {
                lista->insertAt(prime, pos);
                pos++;
            }
            
        }

    
    cout << "Orden original: " << *lista << endl;
    cout << "Orden inverso: ";
    
    invertir(lista->start());
    
    delete lista;
    return 0;
}
