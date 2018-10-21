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
PR�CTICA NUMERO: 3
TITULO: Round Robin
FECHA: 10/09/2018
*/
#include "Cola.h"

void NumProc();
void MTablaProc(int);

int main()
{
    system("cls");
    NumProc();
    return 0;
}

void NumProc(){
    int pro=0;
    printf("Implementar un programa que emule la planificacion por turnos rotatorio\nRound Robin ");
    printf("para esto usuario, favor de elegir el numero de procesos a realizar\n");
    fflush(stdin);
    scanf("%i",&pro);
    MTablaProc(pro);
}

void MTablaProc(int pro){
    //Generacion de mas numeros aleatorios por ejecuccion
    srand(time(NULL));
    //Creacion de todas nuestras variables a ocupar
    COLA C;
    PROCESO *P,*Q;
    CrearCola(&C);
    char x='A',e='A';
    int i,t=0,r,Qu,Ntab=0,ex=0;
    int subopc=0, opc=0;
    printf("Proceso\tTiempo de Llegada\tRequerimiento CPU(ms)\n");
    for(i=0;i<pro;i++){
        //Creacion de cada uno de nuestros procesos a realizar
        P=(PROCESO *)malloc(sizeof(PROCESO));
        r=(rand()%20)+1;
        IngresarProceso(P,x,t,r);
        x++;
        t+=1;
        MostrarProceso(*P);
        InsertarCola(&C,P);
    }
    //Generacion de nuestro Quantium
    Qu=(rand()%3)+3;
    do{
        printf("Para seguir con el procedimiento, contamos con dos breves opciones\n1.-Emular Paso a Paso\n2.-Emular Completo\n");
        fflush(stdin);
        scanf("%i",&opc);
        switch(opc){
            case 1:
                //La opcion de emulacion de paso a paso tras un enter
                printf("El valor de Quantum es de: %i\n",Qu);
                printf("Perfecto, usted eligio la emulacion paso a paso, para eso, debera dar enter para continuar con el proceso\n");
                //Entramos en un bucle, donde esta se quedara vacia hasta que todos los requeste se vallan al primer if, aqui seran quitados de la cola
                while(!ColaVacia(C)){
                    Q=QuitarCola(&C);
                    Q->Request=(Q->Request)-Qu;
                    if(Q->Request<=0){
                        //Al entrar a esta opcion, significa que nuestro sacado sacado de cola, su requeste queda menor que 0
                        ex+=1;
                        Ntab+=1;
                        printf("Termina proceso %c exitosamente\n",Q->NomProc);
                        //Por lo tanto, indicaremos el nombre de este proceso
                        if(!ColaVacia(C)){
                            //Y procederemos a hacer un bucle con el resto de los elementos de la pila, para esto el for va desde nuestro numero de procesos, hasta una variable que incrementa cada vez entrando aqui
                            printf("%i.-\n",Ntab);
                            printf("Proceso\tTiempo de Llegada\tRequerimiento CPU(ms)\n");
                            for(i=0;i<(pro-ex);i++){
                                //Para quitar el valor que acaba de quedar su request 0, sacaremos el siguiente valor de la cola y procederemos a nuestro bucle
                                Q=QuitarCola(&C);
                                MostrarProceso(*Q);
                                InsertarCola(&C,Q);
                            }
                        }
                    }else{
                        Ntab+=1;
                        printf("%i.-\n",Ntab);
                        printf("Proceso\tTiempo de Llegada\tRequerimiento CPU(ms)\n");
                        //Sino, lo que hara es volver a integrar ese mismo valor en la cola
                        InsertarCola(&C,Q);
                        for(i=0;i<(pro-ex);i++){
                            //Y cuando haga el bucle, al querer imprimir los valores, por logica los hara con ese valor hasta el final
                            Q=QuitarCola(&C);
                            MostrarProceso(*Q);
                            InsertarCola(&C,Q);
                        }
                    }
                    do{
                        printf("Favor de presionar la tecla ENTER para continuar\n");
                        fflush(stdin);
                        scanf("%c",&x);
                    }while(x!='\n');
                }
            break;
            case 2:
                //La emulacion completa, que se realizara de a golpe
                printf("El valor de Quantum es de: %i\n",Qu);
                printf("Perfecto, usted eligio la emulacion completa, aparecera toda la informacion\n");
                //Entramos en un bucle, donde esta se quedara vacia hasta que todos los requeste se vallan al primer if, aqui seran quitados de la cola
                while(!ColaVacia(C)){
                    Q=QuitarCola(&C);
                    Q->Request=(Q->Request)-Qu;
                    if(Q->Request<=0){
                        //Al entrar a esta opcion, significa que nuestro sacado sacado de cola, su requeste queda menor que 0
                        ex+=1;
                        Ntab+=1;
                        printf("Termina proceso %c exitosamente\n",Q->NomProc);
                        //Por lo tanto, indicaremos el nombre de este proceso
                        if(!ColaVacia(C)){
                            //Y procederemos a hacer un bucle con el resto de los elementos de la pila, para esto el for va desde nuestro numero de procesos, hasta una variable que incrementa cada vez entrando aqui
                            printf("%i.-\n",Ntab);
                            printf("Proceso\tTiempo de Llegada\tRequerimiento CPU(ms)\n");
                            for(i=0;i<(pro-ex);i++){
                                //Para quitar el valor que acaba de quedar su request 0, sacaremos el siguiente valor de la cola y procederemos a nuestro bucle
                                Q=QuitarCola(&C);
                                MostrarProceso(*Q);
                                InsertarCola(&C,Q);
                            }
                        }
                    }else{
                        Ntab+=1;
                        printf("%i.-\n",Ntab);
                        printf("Proceso\tTiempo de Llegada\tRequerimiento CPU(ms)\n");
                        //Sino, lo que hara es volver a integrar ese mismo valor en la cola
                        InsertarCola(&C,Q);
                        for(i=0;i<(pro-ex);i++){
                            //Y cuando haga el bucle, al querer imprimir los valores, por logica los hara con ese valor hasta el final
                            Q=QuitarCola(&C);
                            MostrarProceso(*Q);
                            InsertarCola(&C,Q);
                        }
                    }
                }
            break;
        }
    }while(opc<1||opc>2);
    //Liberaremos la memoria ocupada con nuestras variables
    free(P);
    free(Q);
    do{
        printf("Le gustaria repetir nuestro programa\n1.-Si\t2.-No\n");
        fflush(stdin);
        scanf("%i",&subopc);
        if(subopc==1){
            main();
        }
    }while(subopc<1 || subopc>2);
}
