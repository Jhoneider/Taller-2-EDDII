#include <stdio.h>
#include<stdlib.h>
#include<stdio.h>

struct promedio
{
	float nota1;  
	float nota2; 
	float nota3;
};
struct estudiante
{
	char nombre[30];
	char sexo[12];
	int  edad;
	
	struct promedio persona;
}alumno, *p_alumno = &alumno;

int main() {
	
	float divicion = 0;
	
	printf("ingrese el nombre de alumno: ");
	fgets(p_alumno -> nombre,20,stdin);
	printf("ingrese su edad: ");
	scanf("%d", &p_alumno -> edad);
	fflush (stdin);
	printf("ingrese su sexo: ");
	fgets(p_alumno -> sexo,10,stdin);
	fflush (stdin);
	printf("ingrese la nota 1: ");
	scanf("%f",&p_alumno -> persona.nota1);
	fflush (stdin);
	printf("Ingrese la nota 2: ");
	scanf("%f",&p_alumno -> persona.nota2);
	fflush (stdin);
	printf("Ingrese la nota 3: ");
	scanf("%f",&p_alumno -> persona.nota3);
	fflush (stdin);
	
	divicion = (p_alumno -> persona.nota1 + p_alumno -> persona.nota2 + p_alumno-> persona.nota3)/3;
	
	printf("El alumno %s con sexo %s tiene una edad de %d, con un promedio de %.2f ",p_alumno -> nombre, p_alumno -> sexo, p_alumno -> edad, divicion);
	

	return 0;
}

