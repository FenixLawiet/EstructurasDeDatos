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
FUNCIONES DEL ARBOL BINARIO
FECHA: 29/10/2018

*/

typedef char item;
#include "arbolBinario.h"

ARBOLBINARIO crearNodo (item x){
	ARBOLBINARIO r=(ARBOLBINARIO) malloc(sizeof(ELEMENTODEARBOLBINARIO));
	r->dato=x;
	r->izq=r->der=NULL;
	return r;
}

void nuevoArbol(ARBOLBINARIO *r, item x, ARBOLBINARIO rama_izq, ARBOLBINARIO rama_der){
	*r=crearNodo(x);
	(*r)->izq=rama_izq;
	(*r)->der=rama_der;
	//return r;
}

void eliminarArbol(ARBOLBINARIO raiz){
	if(raiz){
		eliminarArbol(raiz->izq);
		eliminarArbol(raiz->der);
		free(raiz);
	}
}
