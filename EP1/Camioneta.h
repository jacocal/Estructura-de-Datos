//
//  Camioneta.h
//  Examen
//
//  Created by Abraham Cherem on 2/19/15.
//  Copyright (c) 2015 Abraham Cherem. All rights reserved.
//

#ifndef __Examen__Camioneta__
#define __Examen__Camioneta__

#include <stdio.h>
#include <string>

class Camioneta {
    int placa;
    int marca;
    int modelo;
    std::string traccion;
    Servicio* servicios;
public:
    Camioneta();
    Camioneta(int placa, int marca, int modelo, int kilometraje, std::string traccion, std::string comprador);
    void setServicio(int tipo, float costo);
    friend std::ostream& operator<<(std::ostream& os, const Camioneta& a);
};

#endif /* defined(__Examen__Camioneta__) */
