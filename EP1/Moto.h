//
//  Moto.h
//  Examen
//
//  Created by Abraham Cherem on 2/19/15.
//  Copyright (c) 2015 Abraham Cherem. All rights reserved.
//

#ifndef __Examen__Moto__
#define __Examen__Moto__

#include <stdio.h>
#include <string>

class Moto {
    int placa;
    int marca;
    int modelo;
    int kilometraje;
    int cilindraje;
    std::string comprador;
    Servicio* servicios;
public:
    Moto();
    Moto(int placa, int marca, int modelo, int kilometraje, int cilindraje, std::string comprador);
    ~Moto();
    void setServicio(int tipo, float costo);
    friend std::ostream& operator<<(std::ostream& os, const Moto& a);
};

#endif /* defined(__Examen__Moto__) */
