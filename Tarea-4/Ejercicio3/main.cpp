#include <iostream>
#include "listaEnlazadaDoblementeCircular.cpp"
#include "funcionesDoc.h"


int main()
{
    
    std::fstream archive;

    ListaEnlazadaDoblementeCircular<ListaEnlazadaDoblementeCircular<std::string> *> doc;
    std::string nombre;
    int conmutador;
    std::cout << "Bienvenido al editor de texto Casimueroconesto T923-4019\n";
    
    std::cout << "Por favor seleccione una opcion\n";
    std::cout << "1: Hacer un archivo" << std::endl;
    std::cout << "2: Abrir un archivo default" << std::endl;
    std::cout << "Opcion: ";
    std::cin >> conmutador;
    if (conmutador == 1)
    {
        std::cout << "Por favor introduzca el nombre para su archivo: ";
        std::cin >> nombre;
        archive.open(nombre);
    }
    else
    {
        
        std::cout << "Se abrirá el archivo default ";
        std::cin >> nombre;
        archive.open("default.txt");
        
    }
    
    std::cout << "1: Insertar nueva linea" << std::endl;
    std::cout << "2: Borrar linea" << std::endl;
    std::cout << "3: Insertar nueva word" << std::endl;
    std::cout << "4: Borrar word" << std::endl;
    std::cout << "5: Ir al inicio de la fila" << std::endl;
    std::cout << "6: Ir al final de la fila" << std::endl;
    std::cout << "7: Retroceder" << std::endl;
    std::cout << "8: Avanzar" << std::endl;
    std::cout << "9: Mostrar Texto" << std::endl;
    std::cout << "0: Salir" << std::endl;
    std::cout << "Opcion: ";
    
    if (archive.is_open())
    {
        leerArchivo(archive, doc);
        Nodo<ListaEnlazadaDoblementeCircular<std::string> *> * lineaActual = doc.start();
        Nodo<string> * palabraActual;
        int posLinea = 0;
        int posPalabra = 0;
        
        std::cout << std::endl;
        imprimir(*lineaActual->getInfo(), posPalabra);
        
        conmutador = 0;
        
        while (conmutador != 0)
        {
            std::cin >> conmutador;
            std::string str;
                
            switch (conmutador)
            {
                case 1:
                    
                    std::cout << "> ";
                    std::cin >> str;
                    
                    lineaActual->getInfo()->insertAt(str, posPalabra);
                    ++posPalabra;
                    
                    break;

                case 2:
                    
                    lineaActual->getInfo()->deleteAt(--posPalabra);
                    
                    break;
                    
                case 3:
                    
                    posPalabra = 0;
                    
                    break;
                    
                case 4:
                    
                    posPalabra = lineaActual->getInfo()->size();
                    
                    break;
      
                case 5:
                    
                    if (doc.size() > 1)
                    {
                        lineaActual = lineaActual->getSiguiente();
                        doc.deleteAt(posLinea);
                        posPalabra = 0;
                        
                        if (posLinea == doc.size())
                        {
                            posLinea = 0;
                        }
                        
                    }
                    
                    else
                    {
                        if (doc.size() == 1)
                        {
                            doc.deleteFront();
                        }
                        
                        std::cout << "Se ha llegado al End of File" << std::endl;
                    }
                    
                    break;
                    
                case 6:
                    
                    std::cin >> str;
                    
                    if (doc.size() == 0)
                    {
                        doc.insertFront(stringToList(str));
                        lineaActual = doc.start();
                    }
                    else if (posPalabra == 0)
                    {
                        doc.insertAt(stringToList(str), posLinea);
                        lineaActual = lineaActual->getAnterior();
                    }
                    else if (posPalabra == lineaActual->getInfo()->size())
                    {
                        doc.insertAt(stringToList(str), ++posLinea);
                        lineaActual = lineaActual->getSiguiente();
                    }
                    posPalabra = 0;
                    break;
                    
                    
                case 7:
                    
                    lineaActual = lineaActual->getAnterior();
                    palabraActual = lineaActual->getInfo()->start();
                    
                    if (posLinea == 0)
                    {
                        posLinea = doc.size() - 1;
                    }
                    
                    else
                    {
                        posLinea = (--posLinea) % doc.size();
                    }
                    
                    posPalabra = 0;
                    break;
                    
                    
                case 8:
                    
                    if (posPalabra == 0)
                    {
                        posPalabra = lineaActual->getInfo()->size();
                    }
                    
                    else
                    {
                        posPalabra = (--posPalabra) % (lineaActual->getInfo()->size() + 1);
                    }
                    
                    break;

                    
                case 9:
                    
                    std::cout << std::endl;
                    imprimirTodo(doc);
                    
                    break;
                    
                default:
                    
                    std::cout << "\nLo sentimos, opcion no valida" << std::endl;
                    break;
                    
            }
            
            if (doc.size() != 0 && conmutador != 0)
            {
                imprimir(*lineaActual->getInfo(), posPalabra);
            }
        }
        
        archive.close();
        archive.open("example.txt", ios::in | ios::out | ios::trunc);
        guardar(archive, doc);
        archive.close();
    }
    
    else
    {
        cout << "Error at opening file!" << endl;
    }
    
}

