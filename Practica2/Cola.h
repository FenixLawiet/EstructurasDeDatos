/*
INSTITUTO POLIT…CNICO NACIONAL
ESCUELA SUPERIOR DE C”MPUTO
ESTRUCTURAS DE DATOS
GRUPO: 1CV9
ALUMNOS:
PÈrez Bravo Isaac Ulises 
Escamilla Sanchez Alejandro
 
PROFESOR: BENJAMÕN LUNA BENOSO
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
PR√ÅCTICA NUMERO: 2
TITULO: HEADER COLA

FECHA: 03/09/2018

*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define TAMMAX 100

typedef int item; //Equivalente a tipo de dato. Cambiar de acuerdo al problema
typedef struct cola
{
	int frente;
	int final;
	item ListaCola[TAMMAX];
} COLA;

//PROTOTIPOS DE LAS FUNCIONES PRINCIPALES
void InsertarCola(COLA *Q, item x); 
void CrearCola(COLA *Q);
item FrenteCola(COLA Q);
int ColaLlena(COLA Q);
int ColaVacia(COLA Q);
item QuitarFrente(COLA *Q);