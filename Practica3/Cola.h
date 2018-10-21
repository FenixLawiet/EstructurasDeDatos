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
PRÁCTICA NUMERO: 3
TITULO: Round Robin
FECHA: 10/09/2018
*/
//Cola.h
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
//#include <math.h>
#define TAMMAX 100

typedef struct proceso
{
	char NomProc;
	int Time;
	int Request;
}PROCESO;

typedef PROCESO* item;

typedef struct cola{
	int frente;
	int fin;
	item ListaCola[TAMMAX];
}COLA;


void InsertarCola(COLA *, item );
void CrearCola (COLA *);
item FrenteCola (COLA);
item QuitarCola (COLA *);
int ColaLlena (COLA);
int ColaVacia (COLA);
//Funcion para Bicola
void InsertarColaFrente(COLA *,item);
item QuitarColaFinal(COLA *);
item FinalCola (COLA);
//Funciones para TipoDato como estructura
void IngresarProceso(PROCESO *,char, int, int);
void MostrarProceso(PROCESO);
