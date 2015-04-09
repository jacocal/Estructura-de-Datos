#include "Stack.h"
#include <iostream>
using namespace vcn;

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
    binario(pilaUno, 4);
    while(!pilaUno->empty())
    {
    cout << pilaUno->pop();
    }
    
}
