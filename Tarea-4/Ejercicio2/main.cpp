#include <iostream>
#include <string>
#include "cola.cpp"
#include "pila.cpp"

int validar(std::string, int);
void verificar(Pila<char> *, int, int, std::string);

int main()
{
    Pila<char> * matema = new Pila<char>();
    int banderaUno = 1, bandera = 1, aux = 0;
    
    std::cout << "Hola, bienvenido al balanceador de operaciones T-943058690\n" << std::endl;
    std::cout << "Por favor, escriba la ecuacion a evaluar: " << std::endl;
    std::string expresion;
    std::cin >> expresion;
    validar(expresion, aux);
    if (aux!=0)
    {
        std::cout << "Por favor ingrese una expresion valida" << std::endl;
    }
    else
    {
    verificar(matema, banderaUno, bandera, expresion);
    }
}

void verificar(Pila<char> * matema, int banderaUno, int bandera, std::string expresion)
{
    
    for(int size = 0; size < expresion.length(); ++size)
    {
        
        if(expresion[size] == ')')
        {
            if(matema->empty())
            {
                bandera--;
            }
            else
            {
                matema->pop();
            }
        }
        
        else if (expresion[size] == '(')
        {
            matema->push(expresion[size]);
        }
        
    }
    
    if (bandera != 0 && matema->empty())
    {
        banderaUno = 0;
    }
    
    if(banderaUno == 1)
    {
        std::cout << "La expresion no se encuentra balanceada." << endl;
    }
    
    else
    {
        std::cout << "La expresion se encuentra balanceada" << endl;
    }
}

int validar(std::string expresion, int aux)
{
    for (int size = 0; size < expresion.length(); ++size)
    {
        if (expresion[size] != 1  || expresion[size] != 2 || expresion[size] != 3 || expresion[size] != 4 || expresion[size] != 5 || expresion[size] != 6 || expresion[size] != 7 || expresion[size] != 8 || expresion[size] != 9 || expresion[size] != '('  ||expresion[size] != ')')
        {
            ++aux;
        }
        
    }
    return aux;
}

