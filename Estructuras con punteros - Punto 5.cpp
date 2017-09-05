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
}alumno[50], *p_alumno = &alumno[0];

int main() {
	
	int contador=0;
	char otroalumno='n';
	
	do{
		printf("ingrese el nombre de alumno %d : ",contador + 1);
		fgets((p_alumno + contador) -> nombre,20,stdin);
		printf("ingrese su edad: ");
		scanf("%d", &(p_alumno + contador) -> edad);
		fflush (stdin);
		printf("ingrese su sexo: ");
		fgets((p_alumno + contador) -> sexo,10,stdin);
		fflush (stdin);
		printf("ingrese la nota 1: ");
		scanf("%f",&(p_alumno + contador) -> persona.nota1);
		fflush (stdin);
		printf("Ingrese la nota 2: ");
		scanf("%f",&(p_alumno + contador) -> persona.nota2);
		fflush (stdin);
		printf("Ingrese la nota 3: ");
		scanf("%f",&(p_alumno + contador) -> persona.nota3);
		fflush (stdin);
		contador++;
		printf("/n Desea ingresar otro alumno ? (s. si) (n. no) ");
		scanf("%c",&otroalumno);
		fflush (stdin);
	}
	while(otroalumno=='s');
	
	float menorpromedio = 0;
	int poscialumn=0;
	for(int i =0; i < contador;i++){
		if(i==0){
			menorpromedio = ((p_alumno + i) -> persona.nota1 + (p_alumno + i) -> persona.nota2 + (p_alumno + i)-> persona.nota3)/3;
			poscialumn=i;
		}else if(menorpromedio > (((p_alumno + i) -> persona.nota1 + (p_alumno + i) -> persona.nota2 + (p_alumno + i)-> persona.nota3)/3)){
			menorpromedio = ((p_alumno + i) -> persona.nota1 + (p_alumno + i) -> persona.nota2 + (p_alumno + i)-> persona.nota3)/3;
			poscialumn=i;
		}
	}

	printf("\n ** MENOR PROMEDIO ** \n");
	printf("El alumno %s con sexo %s tiene una edad de %d, con un promedio de %.2f ",(p_alumno + poscialumn) -> nombre, (p_alumno + poscialumn) -> sexo, (p_alumno + poscialumn) -> edad, menorpromedio);
	
	float mayorpromedio = 0;
	poscialumn=0;
	for(int i =0; i < contador;i++){
		if(i==0){
			mayorpromedio = ((p_alumno + i) -> persona.nota1 + (p_alumno + i) -> persona.nota2 + (p_alumno + i)-> persona.nota3)/3;
			poscialumn=i;
		}else if(mayorpromedio < (((p_alumno + i) -> persona.nota1 + (p_alumno + i) -> persona.nota2 + (p_alumno + i)-> persona.nota3)/3)){
			mayorpromedio = ((p_alumno + i) -> persona.nota1 + (p_alumno + i) -> persona.nota2 + (p_alumno + i)-> persona.nota3)/3;
			poscialumn=i;
		}
	}
	
	printf("\n\n ** MAYOR PROMEDIO ** \n");
	printf("El alumno %s con sexo %s tiene una edad de %d, con un promedio de %.2f ",(p_alumno + poscialumn) -> nombre, (p_alumno + poscialumn) -> sexo, (p_alumno + poscialumn) -> edad, mayorpromedio);
	
	return 0;
}
