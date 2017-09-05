#include <iostream>
#include <stdio.h>
#define L 3

using namespace std;

int PuntoArevisar=0;
char Findelprograma='n';

int EsNumeroPrimo(int numero){
	int divisiones = 0;
	
	if(numero==1){
		return false;
	}
	
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
	printf("TALLER II EDII - EJERCICIOS DE MATRICES CON PUNTEROS \n");
}

void PreguntarPunto(){
	printf("digite el numero del punto que desea revisar (1 - 2 - 3) : ");
	scanf("%d",&PuntoArevisar);
}

void Preguntarsideseacontinuar(){
	printf("Desea revisar otro punto ? (s. Si) - (n. No) : ");
	scanf("%c",&Findelprograma);
}

void ImprimirResultadoSegunPunto(){
	
	int matriz[L][L];
	int* Pmatriz=&matriz[0][0];
	int proximonumeroprimo = 0;
	int* PPprimo = &proximonumeroprimo;
	int sumatoria = 0;
	
	switch(PuntoArevisar)
	{
	case 1:
		
		printf("\n punto 1 \n");
		
		for(int c = 0; c < L; c++){
			for(int f = 0; f < L; f++){
				printf(" \n INGRESE EL NUMERO DE LA POSICION (%d , %d) : ",c,f);
				scanf("%d",(Pmatriz + f + (3 * c)));
			}
			printf(" \n");
		}
		
		printf(" \n");
		
		sumatoria = 0;
		
		for(int c = 0; c <= 2; c++){
			for(int f = 0; f <= 2; f++){
				printf("%d \t",*(Pmatriz + f + (3 * c)));
				sumatoria += (*(Pmatriz + f + (3 * c)));
			}
			printf(" \n");
		}
		
		printf("La suma de todos los elementos es : %d ",sumatoria);
		
		printf(" \n ********* \n");
		
		break;
		case 2:
			
			printf("\n punto 2 \n");
			
			sumatoria = 1;
			
			for(int c = 0; c < L; c++){
				for(int f = 0; f < L; f++){
					*(Pmatriz + f + (3 * c)) = sumatoria; 
					sumatoria++;
				}
				printf(" \n");
			}
			
			printf(" \n");
			
			for(int c = 0; c <= 2; c++){
				for(int f = 0; f <= 2; f++){
					printf("%d \t",*(Pmatriz + f + (3 * c)));
				}
				printf(" \n");
			}
			
			printf(" \n ********* \n");
			
			break;
		case 3:
			
			printf("\n punto 3 \n");
			
			for(int c = 0; c < L; c++){
				for(int f = 0; f < L; f++){
					while(EsNumeroPrimo(proximonumeroprimo)==false){
						proximonumeroprimo++;
					}
					*(Pmatriz + f + (3 * c)) = proximonumeroprimo; 
					proximonumeroprimo++;
				}
				printf(" \n");
			}
			
			printf(" \n");
			
			for(int c = 0; c <= 2; c++){
				for(int f = 0; f <= 2; f++){
					printf("%d \t",*(Pmatriz + f + (3 * c)));
				}
				printf(" \n");
			}
			
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

