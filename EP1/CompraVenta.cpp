//
//  main.cpp
//  Libros
//
//  Created by Abraham Cherem on 2/12/15.
//  Copyright (c) 2015 Abraham Cherem. All rights reserved.
//

#include <iostream>
#include "CompraVenta.h"

using namespace std;

void agregarTransaccion(Transaccion* arregloTransaccion[], int& posTransaccion);
void eliminarTransaccion(Transaccion* arregloTransaccion[], int& posTransaccion, int nTransaccion);

int main()
{
    int aux = 0, conmutador;
    const int max = 10;
    Transaccion* catalogo[max] = {0};
    
    do{
        cout << "Bienvenido a la automotriz Quiero LLorar " << endl;
        cout << "------------------------------------------------- " << endl;
        cout << "Por favor seleccione una opción: " << endl;
        cout << "1. Agregar una Transaccion" << endl;
        cout << "2. Eliminar una Transaccion" << endl;
        cout << "3. Buscar una Transaccion" << endl;
        cout << "8. Salir" << endl;
        cout << "Su selección: ";
        cin >> conmutador;
        switch (conmutador) {
            case 1:
                if (aux > max-1)
                    cout << "Lo sentimos, la memoria está llena." << endl;
                else
                    agregarTransaccion(catalogo, aux);
                break;
            case 2:
                eliminarTransaccion(catalogo, aux, max);
                break;
            case 3:
                int fecha;
                cout << "Introduzca el comprador de la Transaccion ";
                cin >> fecha;
                if (!Transaccion::mostrarComprador(catalogo, comprador, max))
                    cout << "Lo sentimos, no se encontró ninguna Transaccion." << endl;
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

void agregarTransaccion(Transaccion* arregloTransaccion[], int& aux) {
    string comprador, tipo;
    int monto;
    cout << "Agregue el tipo de transaccion: ";
    cin >> tipo;
    cout << "Agregue al comprador: ";
    cin >> comprador;
    cout << "agregue el monto: ";
    cin >> monto;
    arregloTransaccion[aux++] = new Transaccion(monto, tipo, comprador);
}

void eliminarTransaccion(Transaccion* arregloTransaccion[], int& posTransaccion, int max) {
    string comprador;
    cout << "Por favor, introduzca el comprador: ";
    cin >> comprador;
    int index = Transaccion::mostrarPorTransaccion(arregloTransaccion, comprador, max);
    if (index == -1) {
        cout << "Lo sentimos, no se encontró ningún comprador." << endl;
        return;
    }
    else {
        delete arregloTransaccion[index];
        while (index < max - 1 && index + 1 != 0) {
            arregloTransaccion[index] = arregloTransaccion[index + 1];
            ++index;
        }
        posLibro = index;
        cout << "Lo sentimos, no se encontró ninguna transaccion." << endl;
    }
}
