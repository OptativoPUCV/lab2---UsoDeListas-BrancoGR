#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "arraylist.h"
#include "stack.h"

// #include "exercises.h"

//Funciones auxiliares que puedes utilizar para debuggear tus ejercicios
//NO MODIFICAR
void imprime_lista(List *L) {
   int *dato;
   dato = (int*)first(L);
   printf("[");
   while(dato != NULL) {
      printf("%d ", *dato);
      dato = (int*)next(L);
   }
   printf("]\n");

}

//Ojo que la pila se vacía al imprimir y se imprime en orden inverso
//NO MODIFICAR
void imprime_y_vacia_pila(Stack *P) {
   void *dato;
   printf("[");
   while((dato = pop(P)) != NULL) {
      printf("%d ", *(int*)dato);
   }
   printf("]\n");
}

/* 
Ejercicio 1.
Crea una Lista y agrega punteros a elementos del 1 al 10.
Recuerda que la lista almacena punteros, por lo que
debes reservar memoria para cada elemento que agregues.
Al finalizar retorna la lista creada.
*/

List* crea_lista() {
   List* L = create_list();

   for (int i = 1; i < 11; i++)
     {
       int* elemento = (int*)malloc(sizeof(int));
       *elemento = i;
       pushBack(L, elemento);
     }
   return L;
}

/*
Ejercicio 2.
Crea una función que reciba una lista de enteros (int*) y 
retorne la suma de sus elementos.
*/
int sumaLista(List *L)
{
  int suma = 0;
  int *primero = first(L);
  while (primero != NULL)
    {
      suma += *primero;
      primero = next(L);      
    }
  return suma;
}

/*
Ejercicio 3.
Crea una función que reciba una lista de punteros a int (int*) y
un entero elem. La función debe eliminar todos los elementos 
de la lista que sean iguales a elem.
Asume que popCurrent luego de eliminar un elemento se
posiciona en el elemento anterior.
*/

void eliminaElementos(List*L, int elem)
{
  int *primero = first(L);
  while (primero != NULL)
    {
      if (*primero == elem)
        popCurrent(L);
      primero = next(L);
    }
}

/*
Ejercicio 4.
La función copia los punteros de la pila P1 en la pila P2.
El orden de ambas pilas se debe mantener.
Puedes usar una pila auxiliar.
*/

void copia_pila(Stack* P1, Stack* P2)
{
  Stack* pAux = create_stack();

  while (top(P1) != NULL)
    {
      pushBack(pAux, top(P1));
      pushBack(P2, top(P1));
      pop(P1);
    }

  while (top(pAux) != NULL)
    {
      pushBack(P1, top(pAux));
      pop(pAux);
    }
}

/*
Ejercicio 5.
La función verifica si la cadena de entrada tiene sus 
paréntesis balanceados. Retorna 1 si están balanceados,
0 en caso contrario.
*/

int parentesisBalanceados(char *cadena)
{
  Stack* pAux = create_stack();

  while(cadena[0] != '\0')
    {
      if (cadena[0] == '(' || cadena[0] == '[' || cadena[0] == '{')
      {
        push(pAux, cadena[0]);
      }
      else //significa que es un cierre entonces xd
      {
        if (cadena[0] == ')' || cadena[0] == ']' || cadena[0] == '}')
        {
          if (cadena[0] == top(pAux)
            return 1;
          return 0;
        }
      }      
    }
  return 0;
  
}


  
