#include <iostream>
#include "token.cpp"
#include "computadora.h"
#include "listaEnlazadaCircular.h"

using namespace std;

void access(ListaEnlazadaCircular<Computadora> &redToken)
{
    int direccion;
    cout << "Por favor, seleccione el vinculo emisor: ";
    cin >> direccion;
    cout << "Se está enviando la señal, por favor espere.\n";
    if (redToken.at(direccion)) 
    {
        Computadora compu = redToken.at(direccion)->getInfo();
        compu.setEnviar(true);
        redToken.deleteAt(direccion);
        redToken.insertAt(compu, direccion);
    }
    
    else
    {
        cout << "Lo sentimos, este vinculo es inexistente. ";
    }
}


void generar(ListaEnlazadaCircular<Computadora> &redToken, Token &token) 
{
    int receptor;
    string signal;
    cout << "Por favor, seleccione el vinculo receptor: ";
    cin >> receptor;
    
    if (receptor >= redToken.size())
    {
         cout << "Lo sentimos, este vinculo es inexistente. ";
    }
    
    cout << "Por favor escriba el mensaje a continuacion: ";
    cin >> signal;
    cout << "Se está enviando la señal, por favor espere.\n";
    
    token.enviar(receptor, signal);
    
}


void confirm(ListaEnlazadaCircular<Computadora> &redToken, Token &token)
{
    cout << "Se ha notificado al vinculo numero: " << token.getlocal();
    
    Computadora compu = redToken.at(token.getlocal())->getInfo();
    
    compu.setEnviar(false);
    
    redToken.deleteAt(token.getlocal());
    
    redToken.insertAt(compu, token.getlocal());
    
    token.setRecibido(false);
    
}

int main()
{
    
    ListaEnlazadaCircular<Computadora> redToken;
    int vinculos, conmutador;
    Token token;
    
    cout << "Hola, bienvenido a la Red Token T9-0129302\n";
    cout << "\nPor favor, ingrese el numero de vinculos en la red: ";
    cin >> vinculos;
    
    for (int i = 0; i < vinculos; ++i)
    {
        redToken.insertBack(Computadora(i));
    }
    
    do {
        
        access(redToken);
        Nodo<Computadora> * aux = redToken.at(token.getlocal());
         
        while (!aux->getInfo().getEnviar())
                {
                aux = aux->getSiguiente();
                token.setlocal(aux->getInfo().getDireccion());
                cout << "El token esta en: " << token.getlocal() << endl;
                }
            
        generar(redToken, token);
            
        while (token.getReceptor() != aux->getInfo().getDireccion()) 
                {
                aux = aux->getSiguiente();
                token.setlocal(aux->getInfo().getDireccion());
                cout << "El token esta en: " << token.getlocal() << endl;
                }
            
        token.confirmar();
            
        while (token.getEmisor() != aux->getInfo().getDireccion())
                {
                aux = aux->getSiguiente();
                token.setlocal(aux->getInfo().getDireccion());
                cout << "El token esta en: " << token.getlocal() << endl;
                }
            
        confirm(redToken, token);
            
            cout << "\n1.- Enviar otro mensaje. 2.- Salir de la aplicacion.";
            cout << "\nSeleccione una opcion del conmutador: ";
            cin >> conmutador;
        
       
    } while (conmutador != 0);
    cout << "\n\nMuchas gracias por utilizar el sistema!";
}


