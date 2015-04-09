//
//  main.cpp
//  Examen
//
//  Created by Sebastian Galgueraon 4/9/15.
//  Copyright (c) 2015 Sebastian Galguera. All rights reserved.
//

#include <iostream>
#include <string>
#include "Stack.h"
#include "LinkedList.h"
#include "Node.h"
#include <math.h>

using namespace vcn;
using namespace std;


LinkedList<int>& duplicate(Stack<int> * L, Stack<int> * R, LinkedList<int> * listaR)
{
    while (!L->empty())
    {
        int aux = L->pop()->getInfo();
        R->push(aux);
        
        Stack<int> pilaAux;
        while (!L->empty()){
            int aux2 = L->pop()->getInfo();
            if (aux != aux2)
            {
                pilaAux.push(aux2);
            }else{
                listaR->insertFront(aux2);
            }
        }
        L->clear();
        while (!pilaAux.empty()){
            L->push(pilaAux.pop()->getInfo());
        }
        
    }
    return *listaR;
}


int main(int argc, const char * argv[])
{
    Stack<int> * L;
    Stack<int> * R;
    LinkedList<int> * listaR;
    L->push(5);
    L->push(2);
    L->push(7);
    L->push(2);
    L->push(5);
    L->push(5);
    L->push(1);
    duplicate(L, R, listaR);
    
    if(!listaR->empty())
    {
        cout << "Lista R:" << listaR;
    }
    else
    {
        cout << "Lista R esta vacía";
    }
    
    return 0;
}
