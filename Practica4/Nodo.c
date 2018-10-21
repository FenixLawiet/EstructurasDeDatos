/*
INSTITUTO POLITÉCNICO NACIONAL
ESCUELA SUPERIOR DE CÓMPUTO
ESTRUCTURAS DE DATOS
GRUPO: 1CV9
ALUMNOS:
Escamilla Sánchez Alejandro
Pérez Bravo Isaac Ulises 
 
PROFESOR: BENJAM͍ÍN LUNA BENOSO
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
Práctica 4
Implementación de las funciones del nodo
FECHA: 08/10/2018

*/

#include "Nodo.h"

//Función para crear nodos
NODO *CrearNodo(TipoDato2 x, NODO *nuevo)
{
  NODO *aux=(NODO *)malloc(sizeof(NODO));
  aux->dato=x;
  aux->siguiente=nuevo;
  return aux;
}

//Función para imprimir elementos de LSE
void ImprimeLSE(NODO *cab)
{
  NODO *ptr;
  for(ptr=cab; ptr=!NULL; ptr=ptr->siguiente)
  {
    print("%d", ptr->dato);
  }
}

//Función para introducir elementos del LSE por la cabecera
void InsertarCabLSE(NODO **cab, TipoDato2 x)
{
  NODO *aux=(NODO *)malloc(sizeof(NODO));
  aux->dato=x;
  aux->siguiente=cab;
  *cab=aux;
}

//Funcion para insertar un nodo en una LSE que no es por cabecera
void InsertarLSE(NODO *anterior, TipoDato2 x)
{
  NODO *aux = (NODO *)malloc(sizeof(NODO));
  aux->dato=x;
  aux->siguiente=anterior->siguiente;
  anterior->siguiente=aux;
}

NODO *anterior(NODO *cab, TipoDato2 x)
{
    NODO *ptr;
    for(ptr=cab; ptr->siguiente; ptr=ptr->siguiente)
    {
      if((ptr->siguiente->dato)>x)
      {
        return ptr;
      }
      return ptr;
    }
}//Para obtener el nodo anterior

//Función que busca un elemento x en una LSE
NODO *BuscaElemento(NODO *cab, TipoDato2 x)
{
  NODO *ptr;
  for(ptr=cab; ptr; ptr=ptr->siguiente)
  {
    if(ptr->siguiente->dato==x)
    {
      return ptr;
    }
    return NULL;
  }
}

//Funcion para eliminar un nodo en una LSE
void eliminarLSE(NODO **cab, TipoDato2 x)
{
  NODO *actual, *anterior=NULL;
  int bandera=0;
  actual=*cab;
  while((actual=!NULL)&&(!bandera)) //Busqueda
  {
    bandera=(actual->dato==x);
    if(!bandera)
    {
      anterior=actual;
      actual=actual->siguiente;
    }
  }
  //Borrado
  if(actual!=NULL)
  {
    if(actual==*cab)
    {
      *cab=(*cab)->siguiente;
    }
    else
    {
      anterior->siguiente=actual->siguiente;
    }
    free(actual);
  }
  else
  {
    printf("No existe el elemento");
  }
}

//PARA LOS TERMINOS
void IngresarTermino(TERMINO T, int exp, int coef)
{
	T->exp = exp;
	T->coef = coef;
}

void MostrarTermino(TERMINO T)
{
  if((T.coef)>0)
	{
		printf("+%f(x^%d)", T.coef, T.exp);
	}
	else
	{
		printf("%f(x^%d)", T.coef, T.exp);
	}
}