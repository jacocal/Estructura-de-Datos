#ifndef Persona_h
#define Persona_h

#include <string>
class Persona {
    std::string nombre;
    std::string apellido;
    int edad;
public:
    Persona() { };
    Persona(std::string nombre, std::string apellido, int edad)
        : nombre(nombre), apellido(apellido), edad(edad) { }
    
    bool operator<(Persona p);
    bool operator>(Persona p);
    friend std::ostream& operator<<(std::ostream&, Persona&);
};

#endif
