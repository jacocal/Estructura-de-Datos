//
//  Coche.h
//  Examen
//
//  Created by Abraham Cherem on 2/19/15.
//  Copyright (c) 2015 Abraham Cherem. All rights reserved.
//

#ifndef __Examen__Coche__
#define __Examen__Coche__

#include <stdio.h>
#include <iostream>
#include "servicio.h"
#include <strings>

class Coche {
    int placa;
    int marca;
    int modelo;
    int kilometraje;
    std::string comprador;
    Servicio* servicios;
public:
    Coche();
    Coche(int placa; int marca; int modelo; int kilometraje, string comprador);
    ~Coche();
    void setServicio(int tipo, float costo);
    friend std::ostream& operator<<(std::ostream& os, const Coche& a);
};
#endif /* defined(__Examen__Coche__) */
