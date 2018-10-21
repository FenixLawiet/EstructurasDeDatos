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
Práctica 5
Implementación de las funciones del nodo para LCSE
FECHA: 15/10/2018

*/

#include "NodosLCSE.h"

//Función para crear nodos
NODO *CrearNodo(TipoDato2 x, NODO *nuevo)
{
  NODO *aux=(NODO *)malloc(sizeof(NODO));
  aux->dato=x;
  aux->siguiente=nuevo;
  return aux;
}

//Función para imprimir elementos de LCSE
void ImprimeLCSE(NODO *cab)
{
  NODO *ptr=cab;
  while(ptr->siguiente!=cab)
  {
    printf("%d, ", ptr->siguiente->dato);
    ptr=ptr->siguiente;
  }
  printf("%d", ptr->siguiente->dato);
}

//Función para introducir elementos del LCSE por la cabecera
void InsertarCabLCSE(NODO **cab, TipoDato2 x)
{
  NODO *aux=(NODO *)malloc(sizeof(NODO));
  aux->dato=x;
  aux->siguiente=aux;
  if((*cab)!=NULL)
  {
    aux->siguiente=(*cab)->siguiente;
    (*cab)->siguiente=aux;
  }
  *cab=aux;
}

//Funcion para insertar un nodo en una LCSE que no es por cabecera
void InsertarLCSE(NODO *anterior, TipoDato2 x)
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

//Función que busca un elemento x en una LCSE
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

//Funcion para eliminar un nodo en una LCSE
void eliminarLCSE(NODO **cab, TipoDato2 x)
{
  NODO *actual= *cab;
  int bandera=0;
  while(((actual->siguiente)!=(*cab)) && !bandera) //Busqueda
  {
    bandera=(actual->siguiente->dato==x);
    if(!bandera)
    {
      actual=actual->siguiente;
    }
  }
  bandera=(actual->siguiente->dato==x);
  //Borrado
  if(bandera)
  {
    NODO *aux=actual->siguiente;
    if(*cab==(*cab)->siguiente)
    {
      *cab=NULL;
    }  
    else
    {
      if(aux==(*cab))
      {
        *cab=actual;
      }
      actual->siguiente=aux->siguiente;
    }
    free(aux);
  }
  else
  {
    printf("ERROR. No existe el elemento.");
  }
}
