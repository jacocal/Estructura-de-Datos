#include <string>
#include "Persona.h"


bool Persona::operator<(Persona p) {
    return (apellido < p.apellido);
}

bool Persona::operator>(Persona p) {
    return (apellido > p.apellido);
}

std::ostream& operator<<(std::ostream& os, Persona& p) {
    os << p.apellido << " " << p.nombre << ", " << p.edad << " años."  << std::endl;
    return os;
}
