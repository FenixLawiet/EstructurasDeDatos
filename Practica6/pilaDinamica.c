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
FUNCIONES DE LA PILA DINÁMICA
FECHA: 29/10/2018

*/

#include "pilaDinamica.h"

int pilaVacia(PILA *P){
	if(P==NULL)
		return 1;
	return 0;
}

TipoDato cimaPila (PILA *P){
		if(!pilaVacia(P)){
			return P->dato;
		}
		else{
			printf("Error");
			exit(-1);
		}
}

void insertarPila(PILA **P, TipoDato x){
	PILA *aux=(PILA *)malloc(sizeof(PILA));
	aux->dato=x;
	aux->siguiente=*P;
	*P=aux;
}

TipoDato quitarPila(PILA **P){
	if(pilaVacia(*P)){
		printf("Error Pila Vacia");
		exit(-1);
	}
	TipoDato aux=(*P)->dato;
	*P=(*P)->siguiente;
	return aux;
}

void eliminarPila(PILA *P){
	if(P!=NULL){
		eliminarPila(P->siguiente);
		free(P);
	}
}
