/*
INSTITUTO POLITÉCNICO NACIONAL
ESCUELA SUPERIOR DE CÓMPUTO
ESTRUCTURAS DE DATOS
GRUPO: 1CV9
ALUMNO:
Pérez Bravo Isaac Ulises 
 
PROFESOR: BENJAMÍN LUNA BENOSO
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
EXAMEN PRÁCTICO
FECHA: 17/09/2018

Se tienen dos Pilas: I y P de valores enteros y una Estructura Cola C de valores
enteros (inicialmente vacía). I tiene valores impares y P tiene valores pares, ambos
ordenados de mayor a menor (mayor en el fondo, menor en la cima). Implementar
una función que permita colocar en C los valores enteros ordenados de menor a
mayor (menor al frente, mayor al final) de las pilas I y P.

*/


#include "Pila.h"
#include "Cola.h"

void LlenarPilaImpar(PILA *D);
void LlenarPilaPar(PILA *D);
PILA invertirPila(PILA *F);
PILA ColocarPilaUnica(PILA A, PILA B);
COLA ColocarEnCola(PILA *C);
void imprimir(PILA A, PILA B, COLA Q);

int main(void)
{
	PILA A1;
	PILA B1;
	PILA A2;
	PILA B2;
	PILA C1;
	PILA C2;
	COLA Q;
	CrearPila(&A1);
	CrearPila(&B1);
	CrearPila(&A2);
	CrearPila(&B2);
	CrearPila(&C1);
	CrearPila(&C2);
	CrearCola(&Q);
	LlenarPilaPar(&A1); //Pila A será la pila de pares (10 elementos)
	LlenarPilaImpar(&B1); //Pila B será la pila de impares (10 elementos)
	A2 = invertirPila(&A1);
	B2 = invertirPila(&B1);
	C1 = ColocarPilaUnica(A2, B2);
	C2 = invertirPila(&C1);
	Q = ColocarEnCola(&C2);
	imprimir(A2, B2, Q); 
	return 0;
}

void LlenarPilaImpar(PILA *D)
{
	int i;
	for(i=0; i<10; i++)
	{
		if((i%2)!=0)
		{
			InsertaPila(D, i);
		}
	}
}

void LlenarPilaPar(PILA *D)
{
	int i;
	for(i=0; i<10; i++)
	{
		if((i%2)==0)
		{
			InsertaPila(D, i);
		}
	}
}

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

PILA ColocarPilaUnica(PILA A, PILA B)
{
	PILA P;
	CrearPila(&P);
	while(!PilaVacia(A) && !PilaVacia(B))
	{
		int aux1 = CimaPila(A);
		int aux2 = CimaPila(B);
		if(aux1>=aux2)
		{
			InsertaPila(&P, QuitaCima(&B));
		}
		else
		{
			InsertaPila(&P, QuitaCima(&A));
		}
	}
	while(!PilaVacia(A))
	{
		InsertaPila(&P, QuitaCima(&A));
	}
	while(!PilaVacia(B))
	{
		InsertaPila(&P, QuitaCima(&B));
	}
	return P;
}

COLA ColocarEnCola(PILA *C)
{
	int aux;
	COLA W;
	CrearCola(&W);
	while(!PilaVacia(*C))
	{
		aux = QuitaCima(C);
		InsertarCola(&W, aux);
	}
	return W;
}

void imprimir(PILA A, PILA B, COLA Q)
{
	printf("\n*La pila de pares se conforma de: \n");
	while(!PilaVacia(A))
	{
		printf("%d ", QuitaCima(&A));
	}
	printf("\n*La pila de impares se conforma de: \n");
	while(!PilaVacia(B))
	{
		printf("%d ", QuitaCima(&B));
	}
	printf("\n*La cola resultante contiene a: \n");
	while(!ColaVacia(Q))
	{
		printf("%d ", QuitarFrente(&Q));
	}
}
