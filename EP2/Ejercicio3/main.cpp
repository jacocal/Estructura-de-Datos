//
//  main.cpp
//  Examen
//
//  Created by Sebastian Galgueraon 4/9/15.
//  Copyright (c) 2015 Sebastian Galguera. All rights reserved.
//

#include <iostream>
#include "Stack.h"
#include "Queue.h"
#include "LinkedList.h"
using namespace vcn;
using namespace std;


bool simbolo(char c);
int orden(char c);
float verificar(Queue<char> &expresion);
void transformar(string s, Queue<char> &expresion);

int main()
{
    Queue<char> expresion;
    string operacion;
    
    cout << "Bienvenido al funcionario T-2390409: " << endl;
    cin >> operacion;
    transformar(operacion, expresion);
    
    float resultado = verificar(expresion);
    cout << resultado << endl;
    
}

bool simbolo(char c)
{
    return (c == '+' || c == '*');
}

void transformar(string aux, Queue<char> &expresion)
{
    Stack<char> operadores;
    LinkedList<int> aList;
    LinkedList<int> bList;
    int i = 0;
    char caracter = aux[i];
    
    while (caracter)
    {
        if (caracter >= '0' && caracter <= '9')
        {
            expresion.enqueue(caracter);
        }
        else if (simbolo(caracter))
        {
            while (!operadores.empty())
                expresion.enqueue(operadores.pop()->getInfo());
            operadores.push(caracter);
        }
        else if (caracter == '(')
        {
            operadores.push(caracter);
        }
        else if (caracter == ')')
        {
            while (!operadores.empty() && operadores.top()->getInfo() != '(')
            {
                expresion.enqueue(operadores.pop()->getInfo());
            }
            if (operadores.empty())
            {
                cout << "Entrada incorrecta";
            }
            operadores.pop();
        }
        else if (caracter == '*')
        {
            Node<int> * aux1 = operadores->top();;

            Node<int> * aux2 = expresion->first();;

            while(!operadores.empty())
            {
                aList.insertBack(operadores.pop());
            }
            while(!expresion.empty())
            {
                bList.insertBack(expresion.dequeue();
                                 }
            for (Node<int> *aux1 = a.first(); aux1; aux1 = aux1->getNext())
            {
                
                for (Node<int> *aux2 = b.first(); aux2; aux2 = aux2->getNext())
                {
                    
                    operadores.push(aux1->getInfo() * aux2->getInfo());
                    
                }
                aList.clear();
                blist.clear();
                
            }
            
            operadores.pop();
        }
        else if (caracter == '+')
        {
            while(!operadores.empty())
            {
            aList.insertBack(operadores.pop());
            }
            while(!expresion.empty())
            {
                bList.insertBack(expresion.dequeue();
            }
                                 
            operadores.pop();
            }
            Node<int> * auxN = operadores->top();;
            while (auxN!=NULL)
                {
                operadores->insertBack(auxN->getInfo());
                auxN = auxN->getNext();
                }
                        
            Node<int> * auxM = expresion->first();
                while(auxM!=NULL)
            {
                if (!operadores->search(auxM->getInfo()))
                {
                operadores->insertBack(auxM->getInfo());
                }
            }
                                 aList.clear();
                                 blist.clear();
        
        }

        caracter = aux[++i];
    }
    while (!operadores.empty())
    {
        expresion.enqueue(operadores.pop()->getInfo());
    }
}
float verificar(Queue<char> &expresion)
{
    Stack<float> operandos;
    while (!expresion.empty())
    {
        if (expresion.first()->getInfo() >= '0' && expresion.first()->getInfo() <= '9')
        {
            operandos.push(expresion.dequeue()->getInfo() - 48.0);
        }
        if (!expresion.empty() && simbolo(expresion.first()->getInfo()))
        {
            if (operandos.size() < 2)
            {
                cout << "Lo sentimos, no es valida la operacion";
            }
            float o1 = operandos.pop()->getInfo();
            float o2 = operandos.pop()->getInfo();
            
            switch (expresion.dequeue()->getInfo()) {
                case '+':
                    operandos.push(o2 + o1);
                    break;
                case '*':
                    operandos.push(o2 * o1);
                    break;
                default:
                    cout << "Lo sentimos, no es valida la operacion";
                    break;
            }
        }
    }
    if (operandos.size() == 1)
    {
        return operandos.pop()->getInfo();
    }
    else
    {
        cout << "Lo sentimos, no es valida la operacion";
    }
    return 0;
}



