#include "token.h"

void Token::enviar(int rec, std::string texto)
{
    
    emisor = local;
    receptor = rec;
    signal = texto;
    
}

void Token::confirmar() 
{
    std::cout << "La información ha sido enviada al nodo: " << local << "\nEl mensaje enviado ha sido: " << signal << std::endl;
    recibido = true;
}

