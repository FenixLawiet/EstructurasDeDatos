/*
INSTITUTO POLIT�CNICO NACIONAL
ESCUELA SUPERIOR DE C�MPUTO
ESTRUCTURAS DE DATOS
GRUPO: 1CV9
ALUMNOS:
P�rez Bravo Isaac Ulises 
Escamilla Sanchez Alejandro
 
PROFESOR: BENJAM�N LUNA BENOSO
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
PR�CTICA NUMERO: 1
TITULO: FUNCIONES PILA

FECHA: 27/08/2018

*/

#include "Pila.h" //MODIFICAR LA RUTA EN CASO DE NO RECONOCERLO

//FUNCI�N QUE INICIA LA PILA
void CrearPila(PILA *P)
{
	P->cima=-1;
}

//FUNCI�N QUE DETERMINA SI LA PILA SE LLENO
int PilaLlena(PILA P)
{
	return ((P.cima==TAMMAX-1)?1:0); //operador ternario, funciona como if-else
}

//DETERMINA SI HAY ELEMENTOS EN LA PILA
int PilaVacia(PILA P)
{
	return ((P.cima==-1)?1:0); //operador ternario, funciona como if-else
}

//FUNCI�N QUE VACIA LA PILA
void LimpiaPila(PILA *P)
{
	CrearPila(P); //Equivalente a decir P->cima==-1, es decir, reiniciar el contador para sobreescribir
}

//FUNCI�N QUE INGRESA UN ELEMENTO A LA PILA
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

//FUNCI�N QUE RETIRA EL ELEMENTO EN LA CIMA DE LA PILA 
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

//FUNCI�N QUE MUESTRA EL VALOR EN LA CIMA DE LA PILA
TipoDato CimaPila(PILA P)
{
	if(PilaVacia(P))
	{
		perror("Error. Pila vacia\n");
		exit(-1);
	}
	return P.ListaPila[P.cima];
}

//FUNCI�N QUE DETERMINA SI DOS PILAS POSE�N EL MISMO CONTENIDO
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

//FUNCI�N QUE COPIA EL CONTENIDO DE UNA PILA A OTRA
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

//Función que permite invertir el orden de la pila
PILA invertirPila(PILA *F)
{
	PILA J;
	CrearPila(&J);
	while(!PilaVacia(*F))
	{
		InsertaPila(&J, QuitaCima(F));
	}
	return J;
}