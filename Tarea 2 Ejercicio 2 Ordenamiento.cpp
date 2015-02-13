#include <iostream>
#include <stdio.h>
#include <time.h>  
#include <stdlib.h>
#include "Template.h"
using namespace std;

void Ordenamiento::burbujaAsc(char arreglo[], int n)
{
   char temp;
   for (int a = 0 ; a < (n-1); a++)
  {
    for (int b = 0 ; b < (n-1); b++)
    {
      if (arreglo[b] > arreglo[b+1]) 
      {
        temp      = arreglo[b];
        arreglo[b]   = arreglo[b+1];
        arreglo[b+1] = temp;
      }
    }
  }
}

void Ordenamiento::burbujaDec(char arreglo[], int n)
{
   char temp;
   for (int a = 0 ; a < (n-1); a++)
  {
    for (int b = 0 ; b < (n-1); b++)
    {
      if (arreglo[b] < arreglo[b+1]) 
      {
        temp      = arreglo[b];
        arreglo[b]   = arreglo[b+1];
        arreglo[b+1] = temp;
      }
    }
  }
}

void Ordenamiento::insercionAsc(char arreglo[], int n)
{
    int a,b;
    int temp;
    for (a = 1; a < n; a++)
    {
    b = a;
    while (b > 0 && arreglo[b - 1] > arreglo[b]) 
    {
    temp = arreglo[b];
    arreglo[b] = arreglo[b - 1];
    arreglo[b - 1] = temp;
    b--;
    }
    }
}

void Ordenamiento::insercionDec(char arreglo[], int n)
{
    int a,b;
  int temp;
    for (a = 1; a < n; a++)
    {
    b = a;
    while (b < 0 && arreglo[b - 1] < arreglo[b]) 
    {
    temp = arreglo[b];
    arreglo[b] = arreglo[b - 1];
    arreglo[b - 1] = temp;
    b--;
    }
    }
}


void Ordenamiento::seleccionDec(char arreglo[], int n)
{
   
	int min,temp;

	for (int i=0; i < n-1; i++)
	{
	    min = i;
		
		for (int j=i+1; j < n; j++)
		{

		if (arreglo[j] > arreglo[min])
                   min=j;
		}
        if (min != i)
        {
        temp = arreglo[i];
        arreglo[i] = arreglo[min];
        arreglo[min] = temp;
        }
	}
}

void Ordenamiento::seleccionAsc(char arreglo[], int n)
{
   
	int min,temp;

	for (int i=0; i < n-1; i++)
	{
	    min = i;
		
		for (int j=i+1; j < n; j++)
		{

		if (arreglo[j] < arreglo[min])
                   min=j;
		}
        if (min != i)
        {
        temp = arreglo[i];
        arreglo[i] = arreglo[min];
        arreglo[min] = temp;
        }
	}
}
