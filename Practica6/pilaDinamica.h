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
Práctica 6
HEADER PILA DINÁMICA
FECHA: 29/10/2018

*/

#include<stdio.h>
#include<stdlib.h>

typedef char TipoDato;

typedef struct pila{
	TipoDato dato;
	struct pila *siguiente;
} PILA;

int pilaVacia(PILA *P);
TipoDato cimaPila(PILA *P);
void insertarPila(PILA **P, TipoDato x);
TipoDato quitarPila(PILA **P);
void eliminarPila(PILA *P);
