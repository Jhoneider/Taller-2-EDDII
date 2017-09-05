#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>


struct competidor
{
	char nombre[30];
	char sexo[10];
	char club[30];
	int edad;
	
}acleta, *p_acleta = &acleta;

int main(){
	
	char categoria[10];
	
	printf("Ingrese nombre: ");
	fgets(p_acleta -> nombre, 20, stdin);
	printf("Ingrese la edad: ");
	scanf("%d",&p_acleta -> edad);
	fflush(stdin);
	printf("Ingrese el sexo: ");
	fgets(p_acleta -> sexo, 10 , stdin );
	fflush(stdin);
	printf("Ingrese el club: ");
	fgets(p_acleta -> club, 30, stdin);
	fflush(stdin);
	
	if(p_acleta -> edad <= 15){
		strcpy(categoria,"infantil");
	}
	if(p_acleta -> edad <= 30 && p_acleta -> edad > 15){
		strcpy(categoria,"juvenil");
	}
	if(p_acleta -> edad > 30){
		strcpy(categoria,"mayor");
	}
	
	
	fflush(stdin);
	printf("el competidor %s con la edad de %d, del sexo %s, de el clud %s, pertenece ala categoria %s ", p_acleta-> nombre, p_acleta->edad, p_acleta->sexo, p_acleta->club,categoria);
	
	return 0;
	}
