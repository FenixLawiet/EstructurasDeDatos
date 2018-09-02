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
PRÁCTICA NUMERO: 2
TITULO: FUNCIONES COLA

FECHA: 03/09/2018

*/

#include "Cola.h" //MODIFICAR LA RUTA EN CASO DE NO RECONOCERLO

//Funci�n para inicializar una variable de tipo COLA
void CrearCola(COLA *Q)
{
	Q->frente = Q->final = 0;
}

//Funci�n para determinar si la cola esta llena
int ColaLlena(COLA Q)
{
	if(Q.frente==(((Q.final)+1)%TAMMAX))
	{
		return 1;
	}
	return 0;
}

//Funci�n para determinar si la cola esta vacia
int ColaVacia(COLA Q)
{
	if(Q.frente==Q.final)
	{
		return 1;
	}
	return 0;
}

//Funci�n para poder ingresar nuevos elementos a la cola
void InsertarCola(COLA *Q, item x)
{
	if(ColaLlena(*Q))
	{
		perror("FATAL ERROR. Cola llena");
		exit(-1);
	}
	Q->final=(((Q->final)+1)%TAMMAX);
	Q->ListaCola[Q->final]=x;
}

//Funci�n para retirar el valor del frente de la cola
item QuitarFrente(COLA *Q)
{
	if(ColaVacia(*Q))
	{
		perror("FATAL ERROR. Cola vacia");
		exit(-1);
	}
	Q->frente=(((Q->frente)+1)%TAMMAX);
	return (Q->ListaCola[Q->frente]);
}

//Funci�n para mostrar el frente de la cola
item FrenteCola(COLA Q)
{
	if(ColaVacia(Q))
	{
		perror("FATAL ERROR. Cola vacia");
		exit(-1);
	}
	return (Q.ListaCola[((Q.frente)+1)%TAMMAX]);
}

//Funci�n que compara si dos colas son iguales
int CompararCola(COLA Q, COLA S)
{
	while((!ColaVacia(Q)) && (!ColaVacia(S)))
	{
		if(QuitarFrente(&Q)!=QuitarFrente(&S))
		{
			return 0;
		}
	}
	if((!ColaVacia(Q)) || (!ColaVacia(S)))
	{
		return 0;
	}
	return 1;
}