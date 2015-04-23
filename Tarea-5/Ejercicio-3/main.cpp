#include <iostream>
#include "BinaryTree.h"

using namespace std;


int main()
{
    
    BinaryTree<int> * arbolTwo = new BinaryTree<int>;
    
    cout << "Bienvenido al Validador de Simetria de Arbol T9-3490" << endl;
    
    arbolTwo->insert(1, nullptr);
    arbolTwo->insert(2, 1);
    arbolTwo->insert(4, 2);
    arbolTwo->insert(5, 2);
    arbolTwo->insert(3, 1);
    arbolTwo->insert(6, 3);
    arbolTwo->insert(7, 3);

    
    cout << "El arbol { " << *arbolTwo;
    if (arbolTwo->validateSymmetry())
    {
        cout << "} es simetrico" << endl;
    }
    else
    {
        cout << "} no es simetrico" << endl;
    }
    
    
}
