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
PROGRAMA PRINCIPAL
FECHA: 29/10/2018

*/

#include "arbolBinario.c"
#include "pilaDinamica.c"

void creacion();
void caminos(ARBOLBINARIO r, PILA *P);
void imprimeCamino(PILA *P);

int main(){
	creacion();
	return 0;
}

//Función que rellena el árbol binario
void creacion(){
	ARBOLBINARIO r;
	PILA *P=NULL;
	r=crearNodo('A');
	//Camino por la Izquierda
	r->izq=crearNodo('B');
	r->izq->izq=crearNodo('D');
	r->izq->der=crearNodo('E');
	r->izq->der->izq=crearNodo('H');
	r->izq->der->der=crearNodo('I');
	//Camino por la Derecha
	r->der=crearNodo('C');
	r->der->izq=crearNodo('F');
	r->der->der=crearNodo('G');
	r->der->der->der=crearNodo('J');
	caminos(r,P);
	eliminarArbol(r);
	printf("\nSe libero tu memoria satisfactoriamente");
}

//Función que recorre el árbol
void caminos(ARBOLBINARIO r, PILA *P){
    //PILA *aux;
    //char c,ci;
	if(r){
	    insertarPila(&P,r->dato);
        if((r->izq)==NULL && (r->der)==NULL)
            imprimeCamino(P);
		caminos(r->izq,P);
		caminos(r->der,P);
	}
}

//Función que imprime el camino recorrido en el arbol
void imprimeCamino(PILA *P){
        char c;
	    PILA *aux;
	    aux=P;
	    while(!pilaVacia(aux)){
            c=quitarPila(&aux);
            printf("%c",c);
	    }
	    printf("\n");
}
