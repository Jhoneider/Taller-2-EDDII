#include <iostream>
#include <stdio.h>
#include <stdlib.h>
	
using namespace std;

int PuntoArevisar=0;
char Findelprograma='n';

struct alumno {
	char nombre[30];
	int edad;
	float promedio;
}alumnos[3],*Palumnos=&alumnos[0];

struct tiempo_ciclista{
	int horas;
	int minutos;
	int segundos;
}ciclista[3],*Pciclista=&ciclista[0];

int Anchodecadena(char * ptr){
	int conteo = 0;
	while(*ptr++)conteo++;
	return conteo - 1;
}

bool Buscar_Numero_En_Matriz(int* matriz,int numero,int longitud){
	for(int i = 0; i < longitud;i++){
		if(*(matriz + i) == numero){
			return true;
		}
	}
	return false;
}


bool EsNumeroPrimo(int numero){
	int divisiones = 0;
	
	for(int i = 1; i <= numero;i++){
		if(numero%i==0){
			divisiones++;
		}
		
		if(divisiones > 2){
			return false;
		}
	}
	
	if(divisiones == 2){
		return true;
	} else {
		return false;
	}
}

void MostrarTitulo(){
	printf("TALLER II EDII - EJERCICIOS DE PUNTEROS \n");
}

void PreguntarPunto(){
	printf("digite el numero del punto que desea revisar (1 - HASTA - 12) : ");
	scanf("%d",&PuntoArevisar);
}

void Preguntarsideseacontinuar(){
	printf("Desea revisar otro punto ? (s. Si) - (n. No) : ");
	scanf("%c",&Findelprograma);
}

void ImprimirResultadoSegunPunto(){
	
	int numeroentrante = 0;
	int auxiliar=0;
	int* PnumeroE = &numeroentrante;
	int Arreglo[100];
	int* PArreglo = &Arreglo[0];
	int Nmenor=0;int* PNmenor=&Nmenor;
	char nombre[50];
	char* Pnombre=nombre;
	int matrizA[50][50],matrizB[50][50];
	int* PmatrizA = &matrizA[0][0];
	int* PmatrizB = &matrizB[0][0];
	float mayorprom=0;
	int Thoras=0,Tminutos=0,Tsegundos=0;
	
	switch(PuntoArevisar)
	{
	case 1:
		
		printf("\n punto 1 \n");
		
		printf("Ingrese un numero : ");
		scanf("%d",PnumeroE);
		
		if(*PnumeroE%2==0)printf("\n El numero es par");else printf("\n El numero es impar");
		
		printf("\n La posicion en memoria del numero es %p",PnumeroE);
		
		printf(" \n ********* \n");
		
		break;
	case 2:
		
		printf("\n punto 2 \n");
		
		printf("Ingrese un numero : ");
		scanf("%d",PnumeroE);
		if(EsNumeroPrimo(*PnumeroE))printf("\n El numero es primo");else printf("\n El numero no es primo");
		
		printf("\n La posicion en memoria del numero es %p",PnumeroE);
		
		printf(" \n ********* \n");
		
		break;
	case 3:
		
		printf("\n punto 3 \n");
		
		for(int i = 0; i < 10; i++){
			printf("Ingrese un numero %d : ", i + 1);
			scanf("%d",PArreglo + i);
		}
		
		for(int i = 0; i < 10; i++){
			if(*(PArreglo + i)%2==0)printf("\n %d : El numero es par",*(PArreglo + i));else printf("\n %d : El numero es impar",*(PArreglo + i));
			printf("\t La posicion en memoria del numero es %p",(PArreglo + i));
		}
		
		printf(" \n ********* \n");
		
		break;
		
	case 4:
		
		printf("\n punto 4 \n");
		
		printf("ingrese el numero de elementos del arreglo: ");
		scanf("%d",PnumeroE);
		
		//crear el arreglo dinamico
		PArreglo = new int[*PnumeroE];
		
		for(int i = 0; i < *PnumeroE; i++){
			printf("\n ingrese el numero %d : ",i + 1);
			scanf("%d",(PArreglo + i));
		}
		
		*PNmenor = 0;
			
			for(int i = 0; i < *PnumeroE; i++){
				if(i==0){
					*PNmenor = *(PArreglo + i);
				}
				else if(*(PArreglo + i) < *PNmenor){
					*PNmenor = *(PArreglo + i);
				}
			}
			
			printf(" \n El numero menor es : %d",*PNmenor);
		
		printf(" \n ********* \n");
		
		break;
		
	case 5:
		
		printf("\n punto 5 \n");
		
		printf("ingrese el numero de elementos del arreglo: ");
		scanf("%d",&numeroentrante);
		
		//arreglo dinamico
		PArreglo = new int[numeroentrante];
		
		for(int i = 0; i < numeroentrante; i++){
			printf("\n ingrese el numero %d : ",i + 1);
			scanf("%d",(PArreglo + i));
			fflush(stdin);
		}
		
		//se ordena
		for(int i=0;i< numeroentrante;i++){
			for(int j=0;j< numeroentrante;j++){
				if(*(PArreglo+j) > *(PArreglo+j+1)){ //se compara el antecesor y sucesor
					auxiliar= *(PArreglo+j);
					*(PArreglo+j)= *(PArreglo+j+1);
					*(PArreglo+j+1)= auxiliar;
				}
			}
		}
		printf("\n en orden ascendente :  ");
		//se muestra
		if(numeroentrante%2!=0){
			auxiliar=1;
			numeroentrante++;
		}
		else{auxiliar=0;}
		
		for(int i = auxiliar; i < numeroentrante; i++){
			printf("%d ",*(PArreglo + i));
		}
		
		printf(" \n ********* \n");
		
		break;
		
	case 6:
		
		printf("\n punto 6 \n");
		
		printf("ingrese el numero de elementos del arreglo: ");
		scanf("%d",&numeroentrante);
		
		//arreglo dinamico
		PArreglo = new int[numeroentrante];
		
		for(int i = 0; i < numeroentrante; i++){
			printf("\n ingrese el numero %d : ",i + 1);
			scanf("%d",(PArreglo + i));
			fflush(stdin);
		}
		
		printf("\n ingrese el numero que desea buscar : ");
		scanf("%d",&auxiliar);
		if(Buscar_Numero_En_Matriz(PArreglo,auxiliar,numeroentrante)){
			printf("\n El numero %d se encuentra en el arreglo ",auxiliar);
		}else printf("\n El numero %d no se encuentra en el arreglo ",auxiliar);
		
		printf(" \n ********* \n");
		
		break;
		
	case 7:
		
		printf("\n punto 7 \n");
		fflush(stdin);
		printf("ingrese su nombre (en minuscula) : ");
		fgets(Pnombre,50,stdin);
		auxiliar = Anchodecadena(Pnombre);
		numeroentrante=0;//cuenta las vocales
		
		for(int i = 0; i < auxiliar;i++){
			if(*(Pnombre + i) == 'a' || *(Pnombre + i) == 'e' || *(Pnombre + i) == 'i' || *(Pnombre + i) == 'o' || *(Pnombre + i) == 'u')numeroentrante++;
		}
		
		printf(" \n El numero de vocales en su nombre es : %d",numeroentrante);
		
		printf(" \n ********* \n");
		
		break;
		
	case 8:
		
		printf("\n punto 8 \n");
		
		fflush(stdin);
		printf("ingrese una cadena de caracteres (en minuscula) : ");
		fgets(Pnombre,50,stdin); //reutilizamos la cadena nombre para optimizar espacio
		auxiliar = Anchodecadena(Pnombre);
		numeroentrante=0;//cuenta las vocales
		
		for(int i = 0; i < auxiliar;i++){
			if(*(Pnombre + i) == 'a')numeroentrante++;
		}
		
		printf(" \n Numero de vocales a : %d ",numeroentrante);
		
		numeroentrante=0;//cuenta las vocales
		
		for(int i = 0; i < auxiliar;i++){
			if(*(Pnombre + i) == 'e')numeroentrante++;
		}
		
		printf(" \n Numero de vocales e : %d ",numeroentrante);
		
		numeroentrante=0;//cuenta las vocales
		
		for(int i = 0; i < auxiliar;i++){
			if(*(Pnombre + i) == 'i')numeroentrante++;
		}
		
		printf(" \n Numero de vocales i : %d ",numeroentrante);
		
		numeroentrante=0;//cuenta las vocales
		
		for(int i = 0; i < auxiliar;i++){
			if(*(Pnombre + i) == 'o')numeroentrante++;
		}
		
		printf(" \n Numero de vocales o : %d ",numeroentrante);
		
		numeroentrante=0;//cuenta las vocales
		
		for(int i = 0; i < auxiliar;i++){
			if(*(Pnombre + i) == 'u')numeroentrante++;
		}
		
		printf(" \n Numero de vocales u : %d ",numeroentrante);
		
		printf(" \n ********* \n");
		
		break;
		
	case 9:
		
		printf("\n punto 9 \n");
		
		printf("ingrese la dimension de las matrices : ");
		scanf("%d",&numeroentrante);
		
		//arreglo dinamico
		PmatrizA = (int*) malloc(numeroentrante*numeroentrante*sizeof(int));
		PmatrizB = (int*) malloc(numeroentrante*numeroentrante*sizeof(int));
		
		for(int c = 0; c < numeroentrante; c++){
			for(int f = 0; f < numeroentrante; f++){
				printf(" \n INGRESE EL NUMERO DE LA POSICION DE LA MATRIZ A (%d , %d) : ",c,f);
				scanf("%d",PmatrizA + f +(c * numeroentrante));
			}
			printf(" \n");
		}
		
		printf(" \n");
		
		for(int c = 0; c < numeroentrante; c++){
			for(int f = 0; f < numeroentrante; f++){
				printf(" \n INGRESE EL NUMERO DE LA POSICION DE LA MATRIZ B (%d , %d) : ",c,f);
				scanf("%d",PmatrizB + f +(c * numeroentrante));
			}
			printf(" \n");
		}
		
		//sumatoria de matrices
		printf("\n LA MATRIZ RESULTADO ES : \n");
		
		for(int c = 0; c < numeroentrante; c++){
			for(int f = 0; f < numeroentrante; f++){
				printf("%d ",(*(PmatrizB + f +(c * numeroentrante))) + (*(PmatrizA + f +(c * numeroentrante))));
			}
			printf(" \n");
		}
		
		
		
		printf(" \n ********* \n");
		
		break;
		
	case 10:
		
		printf("\n punto 10 \n");
		
		printf("ingrese la dimension N de la matriz : ");
		scanf("%d",&numeroentrante); //la variable numero entrante nos representara N
		printf("\n ingrese la dimension M de la matriz : "); //la variable auxiliar nos hara las veces de M
		scanf("%d",&auxiliar);
		
		//arreglo dinamico
		PmatrizA = (int*) malloc(numeroentrante*auxiliar*sizeof(int));
		
		for(int c = 0; c < numeroentrante; c++){
			for(int f = 0; f < auxiliar; f++){
				printf(" \n INGRESE EL NUMERO DE LA POSICION DE LA MATRIZ A (%d , %d) : ",c,f);
				scanf("%d",PmatrizA + f +(c * numeroentrante));
			}
			printf(" \n");
		}
		
		//matriz transpuesta
		printf("\n LA MATRIZ ES : \n");
		
		for(int c = 0; c < numeroentrante; c++){
			for(int f = 0; f < auxiliar; f++){
				printf("%d ",(*(PmatrizA + f +(c * numeroentrante))));
			}
			printf(" \n");
		}
		
		printf("\n LA MATRIZ TRANSPUESTA ES : \n");
		
		for(int f = 0; f < auxiliar; f++){
			for(int c = 0; c < numeroentrante; c++){
				printf("%d ",(*(PmatrizA + f +(c * numeroentrante))));
			}
			printf(" \n");
		}
		
		printf(" \n ********* \n");
		
		break;
		
	case 11:
		
		printf("\n punto 11 \n");
		
		for(int i = 0; i < 3;i++){
			fflush(stdin);
			printf("\n ingrese el nombre del alumno %d : ",i+1);
			fgets((Palumnos + i)->nombre,30,stdin);
			fflush(stdin);
			printf("\n ingrese la edad del alumno %d : ",i+1);
			scanf("%d",&(Palumnos + i)->edad);
			fflush(stdin);
			printf("ingrese el promedio del alumno %d : ",i+1);
			scanf("%f",&(Palumnos + i)->promedio);
		}
		
		numeroentrante=0;//posicion del mayor
		mayorprom=0;
		
		for(int i = 0; i < 3;i++){
			if(mayorprom < (Palumnos + i)->promedio){
				mayorprom= (Palumnos + i)->promedio;
				numeroentrante=i;
			}
		}
		
		printf(" \n El mayor promedio es : %f",mayorprom);
		printf(" \n Estudiante : %s",(Palumnos + numeroentrante)->nombre);
		printf(" \n Edad : %d",(Palumnos + numeroentrante)->edad);
		
		
		printf(" \n ********* \n");
		
		break;
		
	case 12:
		
		printf("\n punto 12 \n");
		
		for(int i = 0; i < 3;i++){
			fflush(stdin);
			printf("\n ingrese el numero de horas de la etapa %d : ",i+1);
			scanf("%d",&(Pciclista + i)->horas);
			fflush(stdin);
			printf("\n ingrese el numero de minutos de la etapa %d : ",i+1);
			scanf("%d",&(Pciclista + i)->minutos);
			fflush(stdin);
			printf(" ingrese el numero de segundos de la etapa  %d : ",i+1);
			scanf("%d",&(Pciclista + i)->segundos);
			fflush(stdin);
		}
		
		printf(" \n");
		
		Tminutos =0;Thoras=0;Tsegundos=0;
		
		for(int i = 0; i < 3;i++){
			Thoras+= (Pciclista + i)->horas;
			Tminutos+=(Pciclista + i)->minutos;
			Tsegundos+=(Pciclista + i)->segundos;
			
			//printf(" \n %d - %d - %d",Thoras,Tminutos,Tsegundos);
		}
		
		auxiliar = (Thoras * 3600) + (Tminutos * 60) + (Tsegundos);
		
		Thoras = (auxiliar/3600);
		Tminutos = ((auxiliar - (Thoras*3600)) / 60);
		Tsegundos = auxiliar - ((Thoras*3600) + (Tminutos * 60));
		printf(" \n la sumatoria total es %d Hora(s), %d minuto(s), %d segundo(s)",Thoras,Tminutos,Tsegundos);
		
		printf(" \n ********* \n");
		
		break;
		
	default:
		printf("\n no se reconoce su peticion. \n");
		break;
	}
	
	fflush(stdin);
}

int main(int argc, char *argv[]) {
	MostrarTitulo();
	do{
		PreguntarPunto();
		
		ImprimirResultadoSegunPunto();
		
		Preguntarsideseacontinuar();
	}
	while(Findelprograma=='s');
	
	
	return 0;
}
