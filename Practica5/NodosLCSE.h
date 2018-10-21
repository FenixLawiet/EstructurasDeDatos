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
HEADER NODOS LCSE
FECHA: 15/10/2018

*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef int TipoDato2;

typedef struct nodo
{
  TipoDato2 dato;
  struct nodo *siguiente;
} NODO;

//PROTOTIPOS DE LAS FUNCIONES
NODO *CrearNodo(TipoDato2 x, NODO *nuevo);
void ImprimeLCSE(NODO *cab);
void InsertarCabLCSE(NODO **cab, TipoDato2 x);
void InsertarLCSE(NODO *anterior, TipoDato2 x);
NODO *anterior(NODO *cab, TipoDato2 x);
NODO *BuscaElemento(NODO *cab, TipoDato2 x);
void eliminarLCSE(NODO **cab, TipoDato2 x);
