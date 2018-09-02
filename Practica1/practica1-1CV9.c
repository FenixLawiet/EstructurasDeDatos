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
TITULO: Inciso B. Cadena postfija a archivo

FECHA: 27/08/2018

*/

#include "Pila.h"
void IngresaOperacion(FILE *pf, PILA *P);
void menu(FILE *pf, PILA *P);

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

//FUNCIÓN QUE DESPLIEGA MENU PARA EL USUARIO
void menu(FILE *pf, PILA *P)
{
	char car1 = '0';
	char car2 = 'Y';
	do{
		system("CLS");
		puts("-------------------------------------------------------------------------");
		printf("Instrucciones:\n");
		printf("Este programa realiza el calculo de una operacion en notacion postfija y la guarda en un archivo.\n");
		printf("Para calcularla, se ingresan los datos uno a la vez");
		puts("-------------------------------------------------------------------------");
		puts("Menu:");
		puts("1. Calcular operacion");
		puts("2. Salir");
		printf("Ingrese opcion: ");
		scanf("%c", &car1);
		fflush(stdin);
	}while(car1!='1' && car1!='2');
	switch(car1)
	{
		case '1':
			
			while (car2=='Y' || car2=='y')
			{
				IngresaOperacion(pf, P);
				printf("\n\nDesea calcular otro? Y/N: ");
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


//FUNCIÓN QUE REALIZA EL CÁLCULO DE LAS OPREACIONES
void IngresaOperacion(FILE *pf, PILA *P)
{
	char simb;
	int simb2, aux, operando1, operando2;
	simb='0';
	
	while(simb!='\n')
	{
		printf("\nIngrese un caracter: ");
		simb = getchar();
		//simb = scanf("%c", &simb);
		fflush(stdin);
		//REVISANDO EL CONTENIDO DEL CARACTER
		if(simb>=48 && simb<=57)
		{
			fputc(simb, pf);
			simb2=simb-'0';
			InsertaPila(P, simb2);
		}
		
		/*FORMA ALTERNATIVA
		if(simb=='0' || simb=='1' || simb=='2' || simb=='3' || simb=='4' || simb=='5' || simb=='6' || simb=='7' || simb=='8' || simb=='9')
		{
			fputc(simb, pf);
			simb2=simb-'0';
			InsertaPila(P, simb2);
		}*/
		
		else
		{
			if((simb=='+' || simb=='-' || simb=='*' || simb=='/' || simb=='^') && ((P->cima)>=1))
			{
				fputc(simb, pf);
				operando1 = QuitaCima(P);
				operando2 = QuitaCima(P);
				
				//REALIZANDO LAS OPREACIONES DE ACUERDO AL SÍMBOLO
				switch(simb)
				{
					case '+': aux = operando1 + operando2;
					break;
					case '-': aux = operando1 - operando2;
					break;
					case '*': aux = operando1 * operando2;
					break;
					case '/': aux = operando1 / operando2;
					break;
					case '^': aux = pow(operando1, operando2); 
					break;
					default: break;
				}
				//printf("Aux: %d", aux);
				InsertaPila(P, aux);
			}
			else
			{
				if(PilaVacia(*P))
				{
					printf("\n****ERROR: PILA VACIA. Favor de revisar la notacion de la operacion.");
				}
				else
				{
					if(simb!='\n')
						printf("\n****ERROR. CARACTER NO VALIDO****");
				}
			}
		}
	}
	aux = QuitaCima(P);
	fputc('=', pf);
	printf("El resultado es %d. Su archivo se ha creado", aux);
	//IMPRIMIENTO EN EL ARCHIVO
	fprintf(pf, "%d\n", aux);
}

