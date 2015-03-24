#include <iostream>
#include <cmath>
#include "pila.cpp"
#include "cola.cpp"

using namespace std;

int reglas(char c);
float segmentar(Cola<char> &expresion);
void segmentar(string s, Cola<char> &expresion);
bool funcionIdentificar(char c);


int reglas(char c) 
{
    if (c == '-' || c == '+')
    {
        return 0;
    }
    else if (c == '/' || c== '*' || c == '%')
    {
        return 1;
    }
    else if (c == '^')
    {
        return 2;
    }
    else
    {
        return -1;
    }
}

float segmentar(Cola<char> &expresion) 
{
    Pila<float> simbolo;
    while (!expresion.empty()) 
    {
        if (expresion.inicio()->getInfo() >= '0' && expresion.inicio()->getInfo() <= '9')
        {
            simbolo.push(expresion.dequeue()->getInfo() - 48.0);
        }
        if (!expresion.empty() && funcionIdentificar(expresion.inicio()->getInfo()))
        {
            if (simbolo.size() < 2)
            {
                throw "Lo sentimos, esta operacion no esta permitida.";
            }
            float o1 = simbolo.pop()->getInfo();
            float o2 = simbolo.pop()->getInfo();
            
            switch (expresion.dequeue()->getInfo())
            {
                case '+':
                
                    simbolo.push(o2 + o1);
                    break;
                    
                case '-':
                
                    simbolo.push(o2 - o1);
                    break;
                    
                case '*':
                
                    simbolo.push(o2 * o1);
                    break;
                    
                case '/':
                
                    simbolo.push(o2 / o1);
                    break;
                    
                case '%':
                
                    simbolo.push((int)o2 % (int)o1);
                    break;
                    
                case '^':
                
                    simbolo.push(pow(o2, o1));
                    break;
                    
                default:
                
                    throw "Lo sentimos, esta operacion no esta permitida.";
                    break;
                    
            }
        }
    }
    if (simbolo.size() == 1)
    {
        return simbolo.pop()->getInfo();
    }
    else
    {
        throw "Lo sentimos, esta operacion no esta permitida.";
    }
    return 0;
}

void segmentar(string s, Cola<char> &expresion)
{
    Pila<char> operadores;
    
    int i = 0;
    char caracter = s[i];
    while (caracter) 
    {
        if (caracter >= '0' && caracter <= '9')
            expresion.enqueue(caracter);
        else if (funcionIdentificar(caracter))
        {
            while (!operadores.empty() && reglas(caracter) < 2 && reglas(caracter) <= reglas(operadores.top()->getInfo()))
            
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
                throw "Su operacion no esta balanceada!";
            operadores.pop();
        }
        caracter = s[++i];
    }
    while (!operadores.empty())
    {
        expresion.enqueue(operadores.pop()->getInfo());
    }
}

bool funcionIdentificar(char c)
{
    return (c == '+' || c == '-' || c == '*' || c== '/' || c == '%' || c == '^');
}


int main()
{
    Cola<char> expresion;
    string operacion;
    
    cout << "Hola, bienvenido al balanceador de operaciones T-943058690\n" << endl;
    cout << "Por favor, escriba la ecuacion a evaluar: " << endl;
    
    cin >> operacion;
    
    try 
    {
        segmentar(operacion, expresion);
        float resultado = segmentar(expresion);
        cout << resultado << endl;
    }
    catch (const char* e) {
        cout << "Error: " << e << endl;
    }
}

