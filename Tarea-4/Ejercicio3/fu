
#ifndef Sgal_funcionesDoc_h
#define Sgal_funcionesDoc_h
#include <fstream>
using namespace std;


ListaEnlazadaDoblementeCircular<string> * stringToList(string s);
string listToString(ListaEnlazadaDoblementeCircular<string> *lista);
void leerArchivo(fstream &archive, ListaEnlazadaDoblementeCircular<ListaEnlazadaDoblementeCircular<string> *> &doc);

void imprimir(ListaEnlazadaDoblementeCircular<string> linea, int posPalabra);
void imprimirTodo(ListaEnlazadaDoblementeCircular<ListaEnlazadaDoblementeCircular<string> *> &doc);
void guardar(fstream &archive, ListaEnlazadaDoblementeCircular<ListaEnlazadaDoblementeCircular<string> *> &doc);

ListaEnlazadaDoblementeCircular<string> * stringToList(string s)
{
    int i = 0;
    char cAux = s[i];
    ListaEnlazadaDoblementeCircular<string> * linea = new ListaEnlazadaDoblementeCircular<string>;
    string word;
    while (cAux)
    {
        if (cAux == ' ')
        {
            linea->insertBack(word);
            word = "";
        }
        else
        {
            word += cAux;
        }
        cAux = s[++i];
    }
    linea->insertBack(word);
    return linea;
}

string listToString(ListaEnlazadaDoblementeCircular<string> *lista)
{
    string linea = "";
    Nodo<string> * aux = lista->start();
    
    while (aux != lista->getUltimo())
    {
        linea += aux->getInfo();
        linea += " ";
        aux = aux->getSiguiente();
    }
    
    linea += aux->getInfo();
    linea += "\n";
    return linea;
}

void leerArchivo(fstream &archive, ListaEnlazadaDoblementeCircular<ListaEnlazadaDoblementeCircular<string> *> &doc)
{
    string s;
    while (getline(archive, s))
    {
        ListaEnlazadaDoblementeCircular<string> * linea = new ListaEnlazadaDoblementeCircular<string>;
        linea = stringToList(s);
        doc.insertBack(linea);
        cout << *linea << endl;
    }
}


void imprimir(ListaEnlazadaDoblementeCircular<string> linea, int posPalabra)
{
    int i = 0;
    for (auto p : linea)
    {
        if (i == posPalabra)
        {
            cout << "|";
        }
        cout << p << " ";
        ++i;
    }
    if (i == posPalabra)
    {
        cout << "|";
    }
}

void imprimirTodo(ListaEnlazadaDoblementeCircular<ListaEnlazadaDoblementeCircular<string> *> &doc)
{
    for (auto l : doc)
    {
        cout << *l.getInfo() << endl;
    }
}

void guardar(fstream &archive, ListaEnlazadaDoblementeCircular<ListaEnlazadaDoblementeCircular<string> *> &doc)
{
    
    Nodo<ListaEnlazadaDoblementeCircular<string> *> * aux = doc.start();
    
    while (aux != doc.getUltimo())
    {
        
        archive << listToString(aux->getInfo());
        aux = aux->getSiguiente();
        
    }
    
    archive << listToString(aux->getInfo());
}



#endif
