/*
INSTITUTO POLITÉCNICO NACIONAL
ESCUELA SUPERIOR DE CÓMPUTO
ESTRUCTURAS DE DATOS
GRUPO: 1CV9
ALUMNOS:
Escamilla Sánchez Alejandro
Pérez Bravo Isaac Ulises 
 
PROFESOR: BENJAMÍN LUNA BENOSO
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
Práctica 4
HEADER LSE
FECHA: 08/10/2018

*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//typedef int TipoDato2;

typedef struct nodo
{
  TipoDato2 dato;
  struct nodo *siguiente;
} NODO;

/*Para la práctica 4, necesitamos definir lo que
es un término de un polinomio*/
typedef termino struct
{
  int exp;
  float coef;
} TERMINO;

typedef TERMINO *TipoDato2;

//PROTOTIPOS DE LAS FUNCIONES
NODO *CrearNodo(TipoDato2 x, NODO *nuevo);
void ImprimeLSE(NODO *cab);
void InsertarCabLSE(NODO **cab, TipoDato2 x);
void InsertarLSE(NODO *anterior, TipoDato2 x);
NODO *anterior(NODO *cab, TipoDato2 x);
NODO *BuscaElemento(NODO *cab, TipoDato2 x);
void eliminarLSE(NODO **cab, TipoDato2 x)

//PARA LOS TERMINOS
void IngresarTermino(TERMINO T, int exp, int coef);
void MostrarTermino(TERMINO T);