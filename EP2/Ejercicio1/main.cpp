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
#include "Queue.h"
#include "CircularLinkedList.h"
#include "LinkedList.h"
#include "OrderedLinkedList.h"
#include "Persona.h"
#include "CircularDoubleLinkedList.h"
#include "Node.h"
#include <math.h>

using namespace vcn;
using namespace std;



Stack<int>& binario(Stack<int> * pilaUno, int num)
{
    int total;
    while(num > 0)
    {
        total = num % 2;
        num /= 2;
        pilaUno->push(total);
    }
    return * pilaUno;
}

int main()

{
    Stack<int> * pilaUno;
    Stack<int> * pilaInvertir;
    binario(pilaUno, 4);
    while(!pilaUno->empty())
    {
        pilaInvertir->push(pilaUno->pop());
        cout << pilaInvertir->pop();
    }
    
}
