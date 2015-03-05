#include <string>
#include "Persona.h"


bool Persona::operator<(Persona p) {
    return (apellido < p.apellido);
}

bool Persona::operator>(Persona p) {
    return (apellido > p.apellido);
}

std::ostream& operator<<(std::ostream& os, Persona& p) {
    os << p.nombre << " " << p.apellido << ", " << p.edad << std::endl;
    return os;
}
