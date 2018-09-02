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
TITULO: FUNCIONES PILA

FECHA: 27/08/2018

*/

#include "Pila.h" //MODIFICAR LA RUTA EN CASO DE NO RECONOCERLO

//FUNCIÓN QUE INICIA LA PILA
void CrearPila(PILA *P)
{
	P->cima=-1;
}

//FUNCIÓN QUE DETERMINA SI LA PILA SE LLENO
int PilaLlena(PILA P)
{
	return ((P.cima==TAMMAX-1)?1:0); //operador ternario, funciona como if-else
}

//DETERMINA SI HAY ELEMENTOS EN LA PILA
int PilaVacia(PILA P)
{
	return ((P.cima==-1)?1:0); //operador ternario, funciona como if-else
}

//FUNCIÓN QUE VACIA LA PILA
void LimpiaPila(PILA *P)
{
	CrearPila(P); //Equivalente a decir P->cima==-1, es decir, reiniciar el contador para sobreescribir
}

//FUNCIÓN QUE INGRESA UN ELEMENTO A LA PILA
void InsertaPila(PILA *P, TipoDato x)
{
	if(PilaLlena(*P))
	{
		perror("Error. Pila llena\n");
		exit(-1);
	}
	P->cima=P->cima+1;
	P->ListaPila[P->cima]=x;
}

//FUNCIÓN QUE RETIRA EL ELEMENTO EN LA CIMA DE LA PILA 
TipoDato QuitaCima(PILA *P)
{
	if(PilaVacia(*P))
	{
		perror("Error. Pila vacia\n");
	}
	TipoDato aux = P->ListaPila[P->cima];
	//printf("Dato retirado\n");
	P->cima=P->cima-1;
	return aux;
}

//FUNCIÓN QUE MUESTRA EL VALOR EN LA CIMA DE LA PILA
TipoDato CimaPila(PILA P)
{
	if(PilaVacia(P))
	{
		perror("Error. Pila vacia\n");
		exit(-1);
	}
	return P.ListaPila[P.cima];
}

//FUNCIÓN QUE DETERMINA SI DOS PILAS POSEÉN EL MISMO CONTENIDO
int CompararPilas(PILA *A, PILA *B)
{
	while((PilaVacia(*A)!=0) && (PilaVacia(*B)!=0))
	{
		if(QuitaCima(A)!=QuitaCima(B))
		{
			return 0;
		}
	}
	if(!PilaVacia(*A)||!PilaVacia(*B))
	{
		return 0;
	}
	return 1;
}

//FUNCIÓN QUE COPIA EL CONTENIDO DE UNA PILA A OTRA
void CopiarPila(PILA A, PILA *B)
{
	PILA C;
	CrearPila(&C);
	while(!PilaVacia(A))
	{
		InsertaPila(&C, QuitaCima(&A));
	}
	while(!PilaVacia(C))
	{
		InsertaPila(B, QuitaCima(&C));
	}
}
