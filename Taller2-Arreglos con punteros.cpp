#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;

int PuntoArevisar=0;
char Findelprograma='n';

void MostrarTitulo(){
	printf("TALLER II EDII - EJERCICIOS DE ARREGLOS CON PUNTEROS \n");
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
	
	float vector[4] = {32.583,11.239,45.781,22.237};
	float* Pvector=vector;
	
	int vector2[50][50];
	int* Pvector2 = &vector2[0][0];
	int columnas=0,filas=0;
	int* Pcolumna = &columnas;
	int* Pfilas = &filas;
	int Contador=0;
	int ceroouno=1;
	
	int num1 = 0;
	int num2 = 0;
	int num3 = 0;
	int num4 = 0;
	int* Pnum1 = &num1;
	int* Pnum2 = &num2;
	int* Pnum3 = &num3;
	int* Pnum4 = &num4;
	
	int arregloC[4][4];
	int* ParregloC = &arregloC[0][0];
	
	switch(PuntoArevisar)
	{
	case 1:
		
		printf("\n punto 1 \n");
		printf("elementos  \n");
		
		for(int i = 0;i<4;i++){
			printf("%.3f \n",*(Pvector+i));
		}
		
		printf(" \n ********* \n");
		
		break;
	case 2:
		
		printf("\n punto 2 \n");
		
		printf("ingrese el NUM 1 : ");
		scanf("%d",Pfilas);
		printf("\n ingrese el NUM 2 : ");
		scanf("%d",Pcolumna);

		
		for(int c = 0; c < (*Pfilas);c++){
			for(int f = 0; f < (*Pcolumna);f++){
				*(Pvector2 + Contador) = ceroouno;
				if(ceroouno==1)ceroouno=0;else ceroouno=1;
				Contador++;
			}
		}
		
		printf("\n");
		Contador=0;
		
		for(int c = 0; c < (*Pfilas);c++){
			for(int f = 0; f < (*Pcolumna);f++){
			    printf("%d ",*(Pvector2 + Contador));
				Contador++;
			}
			printf("\n");
		}
		
		printf(" \n ********* \n");
		
		break;
	case 3:
		
		printf("\n punto 3 \n");
		
		printf("INGRESE EL VALOR 1 : ");
		scanf("%d",Pnum1);
		printf(" \n INGRESE EL VALOR 2 : ");
		scanf("%d",Pnum2);
		printf(" \n INGRESE EL VALOR 3 : ");
		scanf("%d",Pnum3);
		printf(" \n INGRESE EL VALOR 4 : ");
		scanf("%d",Pnum4);
		printf(" \n");
		
		
		for(int f=0;f <= 3;f++){
			if(f==0){
				*ParregloC = *Pnum1;
				*(ParregloC + 1) = *Pnum2;
				*(ParregloC + 2) = *Pnum3;
				*(ParregloC + 3) = *Pnum4;
			} else {
				*(ParregloC + (f * 4)) = floor(pow(*Pnum1,(f + 1)));
				*(ParregloC + 1 + (f * 4)) = floor(pow(*Pnum2,(f + 1)));
				*(ParregloC + 2 + (f * 4)) = floor(pow(*Pnum3,(f + 1)));
				*(ParregloC + 3 + (f * 4)) = floor(pow(*Pnum4,(f + 1)));
			}
		}
		
		for(int f=0;f <= 3;f++){
			for(int c=0;c <= 3;c++){
				printf("%d \t",*(ParregloC + f + (4 * c)));
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

