#include <iostream>
#include "Persona.cpp"
#include "ListaEnlazada.cpp"
#include "ListaEnlazadaOrdenada.cpp"
using namespace std;

Persona generar()
{
    string nombre, apellido;
    int edad;
    cout << "Nombre: ";
    cin >> nombre;
    cout << "Apellidos: ";
    cin >> apellido;
    cout << "Edad: ";
    cin >> edad;
    return Persona(nombre, apellido, edad);
}

typedef bool (*t_compara)(Persona, Persona);

int main()
{
    ListaEnlazadaOrdenada<Persona> personas;
    t_compara comparacion[2];
    comparacion[0] = ListaEnlazadaOrdenada<Persona>::asc;
    int opcion, ordenamiento;
    Persona generador;
    
    cout << "Bienvenido al administrador de Contactos T9-327XX\n" << endl;
    ordenamiento = 1;
    
    do {
        cout << "1. Agregar Contacto\n";
        cout << "2. Buscar Contacto\n";
        cout << "3. Borrar Contacto\n";
        cout << "4. Enlistar Contactos\n";
        cout << "5. Borrar Todo\n";
        cout << "6. Definir Tamaño" << endl;
        cout << "0. Salir del Programa" << endl;
        cout << "Por favor, seleccione una opcion: ";
        cin >> opcion;
        
        int opcion2 = 0;
        if (opcion == 2 || opcion == 3) {
            cout << "Por favor, seleccion la ubicación del contacto: \n";
            cout << "1. Primer Nodo\n";
            cout << "2. Ultimo Nodo\n";
            cout << "3. Otra Posicion\n";
            cout << "Elige una opcion: ";
            cin >> opcion2;
        }
        
        int pos = 0;
        if (opcion2 == 3) 
        {
            cout << "Introduce la localidad del Nodo: ";
            cin >> pos;
        }
        
        switch (opcion) 
        {
            case 1:
            
                generador= generar();
                personas.insert(generador, comparacion[ordenamiento-1]);
                break;
                
            case 2:
            
                if (personas.size() > 0) 
                {
                    if (opcion2 == 1)
                    {
                        cout << *personas[0];
                    }
                    else if (opcion2 == 2)
                    {
                        cout << *personas[personas.size()-1];
                    }
                    else if (opcion2 == 3) 
                    {
                        if (pos >= 0 && pos <= personas.size()-1)
                        {
                            cout << *personas[pos];
                        }
                    }
                }
                else
                {
                    cout << "Lo lamentamos, opcion invalida.\n" << endl;
                }
                break;
                
                
            case 3:
            
                if (opcion2 == 1)
                {
                    personas.deleteFront();
                }
                else if (opcion2 == 2)
                {
                    personas.deleteBack();
                }
                else if (opcion2 == 3)
                {
                    personas.deleteAt(pos);
                }
                else
                {
                    cout << "Lo lamentamos, opcion invalida.\n" << endl;
                }
                break;
                
            case 4:
            
                cout << " " << personas << endl;
                break;
                
            case 5:
            
                cout << "Esta usted seguro? \n";
                cout << "1. Si\n";
                cout << "2. No\n";
                int lock;
                cin >> lock;
                if (lock == 1)
                {
                    personas.clear();
                    cout << "Se ha eliminado toda la informacion.\n" << endl;
                }
                else 
                {
                    cout << "No se ha eliminado nada de informacion.\n" << endl;
                }
                break;
                
            case 6:
            
                cout << "La cantidad de Individuos es: " << personas.size() << endl;
                break;
                
            case 0:
            
                cout << "Muchas gracias por utilizar el servicio." << endl;
                break;
                
            default:
            
                cout << "Lo lamentamos, opcion invalida.\n" << endl;
                break;
                
        }
    } while (opcion != 0);
    return 0;
}

