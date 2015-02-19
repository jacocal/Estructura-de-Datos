//
//  CompraVenta.h
//  Examen
//
//  Created by Abraham Cherem on 2/19/15.
//  Copyright (c) 2015 Abraham Cherem. All rights reserved.
//
//
//  Libros.h
//  Libros
//
//  Created by Abraham Cherem on 2/12/15.
//  Copyright (c) 2015 Abraham Cherem. All rights reserved.
//


#ifndef Compra_Venta_H
#define Compra_Venta_H

#include <iostream>
using namespace std;

class Transaccion {
    string tipo;
    int  monto;
    string comprador;
    
public:
    Transaccion() {};
    Transaccion(string tipo, int  monto, string comprador){};
    
    
    friend ostream& operator<<(ostream&, Transaccion&);
    bool operator>(int);
    bool operator<(int);
    
    int getMonto();
    string getTipo();
    string getComprador();
    
    static bool mostrarPorComprador(Transaccion* arregloTransaccion[], string comprador, int n);
    
    
};

#endif //Compra_Venta_H
