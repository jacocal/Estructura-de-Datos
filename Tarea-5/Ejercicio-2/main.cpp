#include <iostream>
#include "BinaryTree.h"

using namespace std;


int main()
{
    
    BinaryTree<int> * arbol = new BinaryTree<int>;
    
    cout << "Bienvenido al Reflector de Arboles T3-4929038" << *arbol << endl;
    
    arbol->insert(1, nullptr);
    arbol->insert(2, 1);
    arbol->insert(3, 1);
    arbol->insert(4, 2);
    arbol->insert(5, 2);
    arbol->insert(6, 3);
    arbol->insert(7, 3);
    
    cout << "Enteros: " << *arbol << endl;
    arbol->reflect();
    cout << "Árbol reflejado: " << *arbol << endl;
 
}
