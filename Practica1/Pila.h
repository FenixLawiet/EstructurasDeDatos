/*
INSTITUTO POLITÉCNICO NACIONAL
ESCUELA SUPERIOR DE CÓMPUTO
ESTRUCTURAS DE DATOS
GRUPO: 1CV9
ALUMNOS:
Pérez Bravo Isaac Ulises 
Escamilla Sanchez Alejandro
 
PROFESOR: BENJAMÍN LUNA BENOSO
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
PRÁCTICA NUMERO: 1
TITULO: PILA HEADER

FECHA: 27/08/2018

*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define TAMMAX 100

typedef int TipoDato; //LA LINEA A CAMBIAR DEPENDIENDO DE LA PILA

typedef struct pila
{
	TipoDato ListaPila[TAMMAX]; //Tipo de estructura abstracta 
	int cima;
} PILA;

//FUNCIONES ELEMENTALES DE LA PILA
void CrearPila(PILA *P);
int PilaLlena(PILA P); //Por referencia, dado que no se modifica. Booleano, 0=false, 1=true
int PilaVacia(PILA P); //Lo mismo
TipoDato QuitaCima(PILA *P); //Es de TipoDato porque se modifica el arreglo, quita el valor en la cima
TipoDato CimaPila(PILA P); //Devuelve el valor en  la cima de la pila
void InsertaPila(PILA *P, TipoDato x);
void LimpiaPila(PILA *P); //reinicia el contador cima para sobreescribir
