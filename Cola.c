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
//Cola.c

#include "Cola.h"

void CrearCola(COLA *Q){
	Q->frente=Q->fin=0;
}

int ColaVacia(COLA Q){
	if(Q.frente==Q.fin){
		return 1;
	}
	return 0;
}

int ColaLlena (COLA Q){
	if(Q.frente==(Q.fin+1)%TAMMAX){
		return 1;
	}
	return 0;
}

void InsertarCola(COLA *Q, item x){
	if(ColaLlena(*Q)){
		printf("Cola Llena\n");
		exit(-1);
	}
	Q->fin=((Q->fin)+1)%TAMMAX;
	Q->ListaCola[Q->fin]=x;
}

item QuitarCola (COLA *Q){
	if(ColaVacia(*Q)){
		printf("Error, cola vacia\n");
		exit(-1);
	}
	Q->frente=((Q->frente)+1)%TAMMAX;
	return(Q->ListaCola[Q->frente]);
}

item FrenteCola (COLA Q){
	if(ColaVacia(Q)){
		printf("Error, cola vacia\n");
		exit(-1);
	}
	return(Q.ListaCola[((Q.frente)+1)%TAMMAX]);
}

//Funciones para una Bicola

void InsertarColaFrente(COLA *Q, item x){
	if(ColaLlena(*Q)){
		printf("Cola Llena\n");
		exit(-1);
	}
	Q->ListaCola[Q->frente]=x;
	Q->frente=((Q->frente)-1)%TAMMAX;
}

item QuitarColafin(COLA *Q){
	if(ColaVacia(*Q)){
		printf("Error, cola vacia\n");
		exit(-1);
	}
	item aux=Q->ListaCola[Q->fin];
	Q->fin=((Q->fin)-1)%TAMMAX;
	return aux;
}

item finCola (COLA Q){
	if(ColaVacia(Q)){
		printf("Error, cola vacia\n");
		exit(-1);
	}
	return(Q.ListaCola[Q.fin]);
}

//Funciones para TipoDato como estructura

void IngresarProceso(PROCESO *P, char x, int t, int r){
	P->NomProc=x;
	P->Time=t;
	P->Request=r;
}

void MostrarProceso(PROCESO P){
	printf("%c\t|", P.NomProc);
	printf("%i\t\t|", P.Time);
	printf("\t%i\t\t|\n", P.Request);
}
