#include <iostream>
#include "BinaryTree.h"
#include "Person.h"

using namespace std;


void setDeath(BNode<Person*> *person);
void showDead(int day, int month, int year, BNode<Person*> *node);
void showAlive(BNode<Person*> *node);

BNode<Person*> * search(BinaryTree<Person*> *arbol, string texto);


int main()
{
        BinaryTree<Person *> * family = new BinaryTree<Person *>;
        int conmutador;
    
        do
        {
            
            cout << "Bienvenido al Administrador de Familias T9-23920480" << endl;
            
            cout << "1. Agregar miembro\n2. Ver descendencia\n3. Ver primos y hermanos\n4. Ver ancestros\n5. Establecer muerte\n6. Ver miembros muertos\n7. Ver miembros vivos\n0. Salir" << endl;
            
            cout << "Por favor, seleccione una conmutador: ";
            cin >> conmutador;
            
            if (conmutador == 1)
            {
                
                if (!family->getRoot())
                {
                    string nombre;
                    cout << "Nombre: ";
                    cin >> nombre;
                   
                    family->insert(*new Person(nombre), nullptr);
                }
                
                else
                {
                    BNode<Person*> *padre = search(family, "Padre: ");
                    
                    if (padre)
                    {
                        string nombre;
                        cout << "Nombre: ";
                        cin >> nombre;
               
                        family->insert(*new Person(nombre), padre);
                    }
                    
                    else
                    {
                        cout << "Lo sentimos, no existe el nodo Padre." << endl;
                    }
                    
                }
                
            }
            
            else if (conmutador > 1 && conmutador <= 5)
            {
                
                BNode<Person *> * person = search(family, "Ingrese la persona a buscar: ");
                
                if (person)
                {
                    switch (conmutador)
                    {
                        case 2:
                            cout << "Descendencia: ";
                            family->preOrden(person, person->getInfo());
                            cout << endl;
                            break;
                        case 3:
                            cout << "Hermanos: ";
                            family->siblings(person);
                            cout << endl;
                            cout << "Primos: ";
                            family->cousins(person, family->getRoot());
                            cout << endl;
                            break;
                        case 4:
                            cout << "Ancestros: ";
                            family->ancestors(person);
                            cout << endl;
                            break;
                        case 5:
                            setDeath(person);
                            cout << person->getInfo()->deathDate;
                            break;
                    }
                }
                
                else
                {
                    cout << "Lo sentimos, miembro no encontrado." << endl;
                }
                
            }
            
            else if (conmutador == 6)
            {
                
                int year, day, month;
                
                cout << "Por favor, ingrese la fecha de nacimiento.";
                
                cout << "Day (DD): ";
                cin >> day;
                
                cout << "Month (MM): ";
                cin >> month;
                
                cout << "Year (YY): ";
                cin >> year;
                
                showDead(day, month, year, family->getRoot());
                
            }
            
            else if (conmutador == 7)
            {
                showAlive(family->getRoot());
            }
            
            else if (conmutador > 7)
            {
                cout << "Lo sentimos, conmutador no valida" << endl;
            }
            
        } while (conmutador != 0);
    
}


void setDeath(BNode<Person*> *person)
{
    int fecha;
    cout << "Por favor, ingrese la fecha de nacimiento asi DDMMYY: ";
    cin >> fecha;
    person->getInfo()->setLife(false);
    person->getInfo()->setDate(fecha);
    
}

void showDead(int day, int month, int year, BNode<Person*> *node)
{
    if (node)
    {
        if (!node->getInfo()->getLife())
        {
            int yearAux, monthAux, dayAux, dateAux;
            
            /*convertir formato de fechar*/
            dateAux = node->getInfo()->getDate();
            yearAux = dateAux % 10000;
            dateAux /= 10000;
            monthAux = dateAux % 100;
            dateAux /= 100;
            dayAux = dateAux;
            
            if (yearAux < year || (yearAux == year && monthAux < month) || (yearAux == year && monthAux == month && dayAux < day))
            {
                cout << *node->getInfo() << endl;
            }
        }
        
        showDead(day, month, year, node->getLeft());
        showDead(day, month, year, node->getRight());
        
    }
}

void showAlive(BNode<Person*> *node)
{
    if (node)
    {
        if (node->getInfo()->getLife())
        {
            cout << *node->getInfo() << endl;
        }
        showAlive(node->getLeft());
        showAlive(node->getRight());
    }
}


BNode<Person*> * search(BinaryTree<Person*> *arbol, string texto)
{
        string nombre;
        cout << texto;
        getline(cin, nombre);
        Person p(nombre);
        return arbol->search(&p);
}
    




