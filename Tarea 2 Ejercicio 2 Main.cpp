// Sebastián Galguera A01016708 para V Cubells.
// Función de comparación para 1000 caracteres de la Tarea 2
// Para cambiar el tamaño de la matriz, modifique el número 7 al valor que desee.
#include <iostream>
#include <stdio.h>
#include <time.h>  
#include <stdlib.h>
#include "Template.h"
#include "Template2.cpp"

using namespace std;

void llenar(char arreglo[])
{
    for (int i=0; i<1000; i++)
    {
    arreglo[i] = 0;
    }
    for (int i=0; i<1000; i++)
    {
    arreglo[i] = 'A' + random() % 26;
    }
    arreglo[999] = (char)0;
    cout << "arreglo original: " << printf("%s\n", arreglo);
}

bool prompt()
{
    cout << "Por favor seleccione una opción: " << endl;
    cout << "1. Ordenar Ascendente" << endl;
    cout << "2. Ordenar Descendente" << endl;
}

int main ()
{
    int j = 999, conmutador, seleccion;
    char arreglo[1000];
    
     do{
        cout << "Bienvenido al acomodador T500-9XP " << endl;
        cout << "------------------------------------------------- " << endl;
        cout << "Por favor seleccione una opción: " << endl;
        cout << "1. Ordenar con Burbuja" << endl;
        cout << "2. Ordenar con Inserción" << endl;
        cout << "3. Ordenar con Selección" << endl;
        cout << "4. Salir" << endl;
        cout << "Su selección: ";
        cin >> conmutador;
        switch (conmutador) {
            case 1:
            prompt();
            cin >> seleccion;
            if(seleccion == 1)
            {
            llenar(arreglo);
            Ordenamiento::burbujaAsc(arreglo, 999);
            cout << "Ordenado: " << printf("%s\n", arreglo) << endl;
            }
            else
            {
            llenar(arreglo);
            Ordenamiento::burbujaDec(arreglo, 999);
            cout << "Ordenado: " << printf("%s\n", arreglo) << endl;
            }
                break;
            case 2:
            
            prompt();
            cin >> seleccion;
            if(seleccion == 1)
            {
            llenar(arreglo);
            Ordenamiento::insercionAsc(arreglo, 999);
            cout << "Ordenado: " << printf("%s\n", arreglo) << endl;
            }
            else
            {
            
            }
            printf("%s\n", arreglo);
                break;
            case 3:
            
            prompt();
            cin >> seleccion;
            if(seleccion == 1)
            {
            llenar(arreglo);
            Ordenamiento::seleccionAsc(arreglo, 999);
            cout << "Ordenado: " << printf("%s\n", arreglo) << endl;
            }
            else
            {
            
            }
                break;
            case 4:
                cout << "¡Gracias por usar el sistema!";
                exit(1);
                break;
                
            default:
                cout << "Lo sentimos, opción no disponible." << endl;
                break;
        }
    }while(conmutador != 4);
}
    
