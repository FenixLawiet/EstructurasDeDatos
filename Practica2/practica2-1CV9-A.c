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
PRÁCTICA NUMERO: 2
TITULO: Inciso A. Conversion de una operacion en 
notación interfija a postfija.

FECHA: 03/09/2018

*/

#include "../Practica1/Pila.h"

//PROTOTIPOS DE FUNCIONES
void menu(FILE *pf, PILA *P);
void convertirOperacion(FILE *pf, PILA *P);
int preced(char op1, char op2);

int main(void)
{
	FILE *pf;
	PILA P;
	
	//INICIANDO EL ARCHIVO Y LA PILA
	CrearPila(&P);
	pf = fopen("postfija.txt", "a+");
	if(pf==NULL)
	{
		perror("No existe el archivo");
		exit(-1);
	}
	else
	{
		menu(pf, &P);
	}
	
	//CERRANDO EL ARCHIV0
	fclose(pf);
	return 0;
}

//FUNCION QUE DESPLIEGA MENU PARA EL USUARIO
void menu(FILE *pf, PILA *P)
{
	char car1 = '0';
	char car2 = 'Y';
	do{
		system("CLS");
		puts("-------------------------------------------------------------------------");
		printf("Instrucciones:\n");
		printf("Este programa realiza la conversion de una operacion en notacion interfija a postfija y la guarda en un archivo.\n");
		printf("Para convertir, se ingresan los datos uno a la vez");
		puts("-------------------------------------------------------------------------");
		puts("Menu:");
		puts("1. Convertir operacion");
		puts("2. Salir");
		printf("*Ingrese opcion: ");
		scanf("%c", &car1);
		fflush(stdin);
	}while(car1!='1' && car1!='2');
	switch(car1)
	{
		case '1':
			
			while (car2=='Y' || car2=='y')
			{
				convertirOperacion(pf, P);
				printf("\n\nDesea convertir otro? Y/N: ");
				scanf("%c", &car2);
				fflush(stdin);
			}
			printf("Gracias por usar este programa.\n");	
		break;
		case '2':
			printf("Gracias por usar este programa.\n");
			fclose(pf);
			exit(0);
	}	
}


//FUNCION QUE CONVIERTE LA OPERACION A NOTACION POSTFIJA
void convertirOperacion(FILE *pf, PILA *P)
{
	//PILA P ES "CADENA POSTFIJA"
	PILA N; //PILA PARA GUARDAR LOS OPERADORES
	PILA N2; //PILA QUE RECIBE A P EN ORDEN INVERSO PARA IMPRIMIR
	char simb, aux;
	int simb2; 
	CrearPila(&N);
	CrearPila(&N2);
	while(simb!='\n')
	{
		printf("\n-Ingresa un caracter: ");
		simb = getchar();
		fflush(stdin);
		if(simb>=48 && simb<=57) //REVISANDO SI ES UN OPERANDO
		{
			fputc(simb, pf);
			//simb2 = simb - '0';
			InsertaPila(P, simb);
			//printf("%c", simb);
		}
		else
		{
			//REVISANDO SI ES UN OPERADOR
			if((simb=='*') || (simb=='/') || (simb=='+') || (simb=='-') || (simb=='^'))
			{
				if(PilaVacia(*P))
				{
					printf("*****ERROR. No se puede iniciar con operador.*****");
				}
				else
				{
					if(PilaVacia(N))
					{
						InsertaPila(&N, simb);
						fprintf(pf, "%c", simb);
					}
					else
					{
						//printf("%c, %c", CimaPila(N), simb);
						while(!PilaVacia(N) && preced(CimaPila(N), simb))
						{
							simb2 = QuitaCima(&N);
							//printf("%c", simb);
							InsertaPila(P, simb2);
						}
						fprintf(pf, "%c", simb);
						InsertaPila(&N, simb);
					}
				}
			}
			else
			{
				if(simb!='\n')
					printf("*****ERROR. Simbolo no valido*****");
			}
		}
	}
	while(!PilaVacia(N))
	{
		//printf("aqui");
		simb2 = QuitaCima(&N);
		//printf("%c ", simb2);
		InsertaPila(P, simb2);
	}
	while(!PilaVacia(*P))
	{
		//printf("aca");
		simb2 = QuitaCima(P);
		//printf("%c ", simb2);
		InsertaPila(&N2, simb2);
	}
	//IMPRIMIENDO A ARCHIVO Y EN PANTALLA
	printf("\nLa cadena convertida es: ");
	fprintf(pf, "=");
	while(!PilaVacia(N2))
	{
		aux = QuitaCima(&N2);
		printf("%c", aux);
		fprintf(pf, "%c", aux);
	}
	fprintf(pf, "\n");
}

//FUNCION QUE REVISA LA PRECEDENCIA DE OPERADORES (op1 es cima y op2 es el que se ingresa) 
int preced(char op1, char op2)
{
	switch(op1)
	{
		case '^':
			return 1; //PRECEDENCIA MÁXIMA
		break;
		case '*':
			if(op2=='^')
			{
				return 0;
			}
			else
			{
				return 1;
			}
		break;
		case '/':
			if(op2=='^')
			{
				return 0;
			}
			else
			{
				return 1;
			}
		break;
		case '+':
			if((op2=='^') || (op2=='*') || (op2=='/'))
			{
				return 0;
			}
			else
			{
				return 1;
			}	
		break;
		case '-':
			if((op2=='^') || (op2=='*') || (op2=='/'))
			{
				return 0;
			}
			else
			{
				return 1;
			}
		break;
		default:
			return 0;	
		break;
	}
}
