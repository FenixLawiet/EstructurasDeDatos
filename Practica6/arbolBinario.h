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
HEADER ARBOL BINARIO
FECHA: 29/10/2018

*/

#include <stdio.h>
#include <stdlib.h>
typedef char item;

typedef struct nodo{
	item dato;
	struct nodo*izq, *der;
}ELEMENTODEARBOLBINARIO;

typedef ELEMENTODEARBOLBINARIO *ARBOLBINARIO;

ARBOLBINARIO crearNodo(item x);
void nuevoArbol(ARBOLBINARIO *r, item x, ARBOLBINARIO rama_izq, ARBOLBINARIO rama_der);
void eliminarArbol(ARBOLBINARIO raiz);
