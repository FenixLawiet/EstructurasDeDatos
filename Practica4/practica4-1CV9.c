/*
INSTITUTO POLIT�CNICO NACIONAL
ESCUELA SUPERIOR DE C�MPUTO
ESTRUCTURAS DE DATOS
GRUPO: 1CV9
ALUMNOS:
Escamilla S�nchez Alejandro
P�rez Bravo Isaac Ulises 
 
PROFESOR: BENJAM͍N LUNA BENOSO
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
Pr�ctica 4

FECHA: 08/10/2018

*/

#include "Nodo.h"
#include "../Practica1/Pila.h"

void menu(PILA P, int n);
NODO *IngresarPolinomio(int n);
void MostrarPolinomio(PILA P, int pos);
void Derivar(PILA P, int pos);
void Integrar(PILA P, int pos);
void Sumar(PILA P, int pos1, int pos2);
void Multiplicar(PILA P, int pos1, int pos2);
void EliminarNodos(PILA *P);

int main(void)
{
	char car2 = 'Y';
	int n, t;
	PILA P, auxP;
	CrearPila(&P);
	CrearPila(&auxP);
	system("CLS");
	puts("-------------------------------------------------------------------------");
	printf("Instrucciones:\n");
	printf("Este programa almacena términos de uno o varios polinomios y realiza operaciones con estos.\n");
	printf("Para ingresar un polinomio, se ingresa término a término");
	puts("-------------------------------------------------------------------------");
	printf("-Ingrese el número de polinomios que desea ingresar: ");
	scanf("%d", n);
	fflush(stdin);
	for(int i=0; i<n; i++)
	{
		printf("\n*POLINOMIO %d. Ingrese el número de términos: ",(i+1));
		scanf("%d", t);
		NODO *aux = IngresarPolinomio(t);
		InsertaPila(&auxP, *aux);
		P = invertirPila(&auxP);
	}
	printf("\n\n-----------------REGISTRO DE POLINOMIOS COMPLETADO-----------------\n\n");
	printf("Los polinomios registrados son: ")
	//MOSTRANDO POLINOMIOS
	for(int i=0; i<n; i++)
	{
		printf("%d) ", (i+1);
		MostrarPolinomio(P, i);
		printf("\n");
	}
	while (car2=='Y' || car2=='y')
	{
		menu(P, n);
		printf("*Desea realizar otra operación? Y/N: ")
		scanf("%c", car2);			
	}
	EliminarNodos(&P);
	return 0;
}

//Función que despliega el menu de acciones al usuario
void menu(PILA P, int n) 
{
	char car1 = '0';
	int poli1, poli2;
	//Puesto que para hacer suma y multiplicación debe de haber al menos 2
	if(n==1)
	{
		do{
			puts("Menu:");
			puts("1. Derivar el polinomio");
			puts("2. Integrar el polinomio");
			printf("*Ingrese opcion: ");
			scanf("%c", &car1);
			fflush(stdin);
		} while(car1!='1' && car1!='2');
		switch(car1)
		{
			case '1':
				printf("\n*Seleccione el número de polinomio que quiere derivar: ");
				scanf("%d", poli1);
				fflush(stdin);
				printf("* El polinomio a derivar es: ");
				MostrarPolinomio(P, i);
				printf("* Su derivada es: ");
				Derivar(P, poli1);
			break;
			case '2':
				printf("\n*Seleccione el número de polinomio que quiere integrar: ");
				scanf("%d", poli1);
				fflush(stdin);
				printf("* El polinomio a integrar es: ");
				MostrarPolinomio(P, i);
				printf("* Su integral es es: ");
				Integrar(P, poli1);
			break;
			default
			break;
		}
	}
	else
	{
		do{
			puts("Menu:");
			puts("1. Derivar el polinomio");
			puts("2. Integrar el polinomio");
			puts("3. Sumar polinomios");
			puts("4. Multiplicar polinomios");
			printf("*Ingrese opcion: ");
			scanf("%c", &car1);
			fflush(stdin);
		} while(car1!='1' && car1!='2' && car1!='3' && car1!='4');
		switch(car1)
		{
			case '1':
				printf("\n*Seleccione el número de polinomio que quiere derivar: ");
				scanf("%d", poli1);
				fflush(stdin);
				printf("* El polinomio a derivar es: ");
				MostrarPolinomio(P, poli1);
				printf("* Su derivada es: ");
				Derivar(P, poli1);
			break;
			case '2':
				printf("\n*Seleccione el número de polinomio que quiere integrar: ");
				scanf("%d", poli1);
				fflush(stdin);
				printf("* El polinomio a integrar es es: ");
				MostrarPolinomio(P, poli1);
				printf("* Su integral es: ");
				Integrar(P, poli1);
			break;
			case '3':
			break;
			case '4':
			break;
			default
			break;
		}	
	}
}

//Función para ingresar polinomios
NODO *IngresarPolinomio(int n)
{
	NODO *pol=NULL; //=(NODO *)malloc(sizeof(NODO));
	int coe, ex;
	for(int i=0; i<n; i++)
	{
		TERMINO T;
		printf("\n*Termino %d. Ingrese su coeficiente: ");
		scanf("%d", coe);
		fflush(stdin);
		printf("Ingrese su exponente: ");
		scanf("%d", ex);
		fflush(stdin);
		IngresarTermino(T, ex, coe);
		InsertarCabLSE(&pol, T);
	}
	return pol;
}

//Función para mostrar los polinomios
void MostrarPolinomio(PILA P, int pos)
{
	int counter=1;
	NODO *aux = NULL;
	if(pos<counter)
	{
		printf("ERROR. No existe un polinomio en dicha posición");
	}
	else
	{
		while(!PilaVacia(P))
		{
			aux = QuitaCima(&P);
			if(counter==pos)
			{
				TERMINO T = aux->dato;
				printf("%f(x^%d)", T->coef, T->exp);
				aux=aux->siguiente;
				for(aux; aux->siguiente!=NULL; aux=aux->siguiente)
				{
					MostrarTermino(T=(aux->dato));
				}	
			}
			counter++;
		}
	}
	if(pos>counter)
	{
		printf("ERROR. No existe un polinomio en dicha posición");
	}
}

//Funcion que permite derivar un polinomio
void Derivar(PILA P, int pos)
{
	int counter=1;
	NODO *aux = NULL;
	if(pos<counter)
	{
		printf("ERROR. No existe un polinomio en dicha posición");
	}
	else
	{
		while(!PilaVacia(P))
		{
			aux = QuitaCima(&P);
			if(counter==pos)
			{
				for(aux; aux->siguiente!=NULL; aux=aux->siguiente)
				{
					TERMINO T = aux->dato;
					if(((T->exp)>=1 || (T->exp)<0) && ((T->coef)>=1 || (T->coef)<0))
					{
						printf("%f(x^(%d))", (T->coef)*(T->exp),(T->exp)-1);
					}
				}
			}
			counter++;
		}	
	}
	if(pos>counter)
	{
		printf("ERROR. No existe un polinomio en dicha posición");
	}
}

//Funcion que permite integrar un polinomio
void Integrar(PILA P, int pos)
{
	int counter=1;
	NODO *aux = NULL;
	if(pos<counter)
	{
		printf("ERROR. No existe un polinomio en dicha posición");
	}
	else
	{
		while(!PilaVacia(P))
		{
			aux = QuitaCima(&P);
			if(counter==pos)
			{
				for(aux; aux->siguiente!=NULL; aux=aux->siguiente)
				{
					TERMINO T = aux->dato;
					if(((T->exp)>=1 || (T->exp)<0) && ((T->coef)>=1 || (T->coef)<0))
					{
						printf("%f(x^(%d))", (T->coef)*(1/(T->exp)+1),(T->exp)+1);
					}
				}
			}
			counter++;
		}
	}
	if(pos>counter)
	{
		printf("ERROR. No existe un polinomio en dicha posición");
	}
}

//Funcion que permite sumar dos polinomios
void Sumar(PILA P, int pos1, int pos2)
{
	int counter1, counter2=1;
	NODO *aux1, *aux2 = NULL;
	if(pos1<counter1 || pos2<counter2)
	{
		printf("ERROR. Uno de los polinomios no existe en dicha posición");
	}
	else
	{
		while(!PilaVacia(P))
		{
			aux1=QuitaCima(&P);
			if(counter1==pos1 || counter2==pos2)
			{

			}
		}
	}
	if(pos1>counter1 || pos2>counter2)
	{
		printf("ERROR. Uno de los polinomios no existe en dicha posición");
	}
}

//Funcion que permite multiplicar dos polinomios
void Multiplicar(PILA P, int pos1, int pos2)
{
	int counter1, counter2=1;
	NODO *aux1, *aux2 = NULL;
	if(pos1<counter1 || pos2<counter2)
	{
		printf("ERROR. Uno de los polinomios no existe en dicha posición");
	}
	else
	{
		while(!PilaVacia(P))
		{
			aux1=QuitaCima(&P);
			if(counter1==pos1 || counter2==pos2)
			{

			}
		}
	}
	if(pos1>counter1 || pos2>counter2)
	{
		printf("ERROR. Uno de los polinomios no existe en dicha posición");
	}
}

//Funcion para borrar los nodos ingresados en la pila
void EliminarNodos(PILA *P)
{
	if(!PilaVacia(P))
	{
		NODO aux=QuitaCima(P);
		if(aux->siguiente!=NULL)
		{
			EliminarNodos(P);
			free(aux);
		}	
	}
}