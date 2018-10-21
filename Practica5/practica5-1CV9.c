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
Práctica 5
PROBLEMA DE JOSEPHUS
FECHA: 15/10/2018

*/

#include "NodosLCSE.h"

void JOSEPHUS();
void ImprimeZapatitoBlanco(NODO *cab, int n);
void BorrarLista(NODO *cab);

int main(void)
{
	JOSEPHUS();
	return 0;
}

//Función que realiza el procedimiento de Josephus
void JOSEPHUS()
{
	srand(time(NULL));
	int sold, n, i;
	NODO *Grump=NULL;
	printf("*Ingrese el numero de soldados: ");
	scanf("%d", &sold);
	fflush(stdin);
	n = rand()%(sold+1);
	if(n==0)
	{
		n=1;
	}
	for(i=0; i<sold; i++)
	{
		InsertarCabLCSE(&Grump, i+1);
	}
	ImprimeZapatitoBlanco(Grump, n);
	free(Grump);
}

//Función para imprimir los movimientos de la lista
void ImprimeZapatitoBlanco(NODO *cab, int n)
{
	NODO *aux, *aux2=NULL;
	int j;
	printf("\n\n*SOLDADOS ORIGINALES*\n");
	ImprimeLCSE(cab);
	printf("\nTeniendo como n=%d\n", n);
	while(cab->siguiente!=cab)
	{
		for(j=0; j<n; j++)
		{
			printf("\n\n*********PASADA %d*********\n\n", j+1);
			//IMPRIME
			ImprimeLCSE(cab);
			cab=cab->siguiente;
		}
		printf("\n*****SALE EL SOLDADO %d*****", cab->dato);
		aux=cab->siguiente;
		do
		{
			//printf("LLEGASTE?");
			if(aux->siguiente==cab)
			{
				//printf("Entras?");
				aux2=aux; //aux2 es el nodo anterior a la cabecera
			}
			aux=aux->siguiente;
		} while(aux->siguiente!=cab);
		aux2=aux;
		aux2->siguiente=cab->siguiente;
		//printf("LLEGASTE?x2");
		free(cab);
		cab=aux;
	} 
	printf("\n\nEl soldado que sobrevive es: %d", cab->dato);
}

//Función para borrar toda la lista
void BorrarLista(NODO *cab)
{
	NODO *actual= cab;
	NODO *aux=actual->siguiente;
    if(cab==(cab->siguiente))
    {
      cab=NULL;
    }  
    else
    {
      if(aux==cab)
      {
        cab=actual;
      }
      actual->siguiente=aux->siguiente;
    }
    free(aux);
}
