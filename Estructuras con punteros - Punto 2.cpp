#include <stdio.h>

struct promedio
{
	float n1, n2, n3;
};

struct alumno
{
	char nombre[30];
	int edad, grado;
	
	struct promedio prom;
	
}estudiantes[3], *p_estudiantes= &estudiantes[0];

void datos();

alumno estudiante;

int main()
{
	datos();
}


void datos()
{
	for(int i = 0; i < 3; i++){
		printf("Ingrese nombre %d : ",i + 1);
		fgets((p_estudiantes+i)-> nombre,30,stdin);
		printf("Ingrese grado: ");
		scanf("%d",&(p_estudiantes+i)-> grado);
		fflush(stdin);
		printf("Ingrese edad: ");
		scanf("%d",&(p_estudiantes+i)->edad);
		fflush(stdin);
		printf("Ingrese nota 1: ");
		scanf("%f", &(p_estudiantes+i)-> prom.n1);
		fflush(stdin);
		printf("Ingrese nota 2: ");
		scanf("%f", &(p_estudiantes+i)-> prom.n2);
		fflush(stdin);
		printf("Ingrese nota 3: ");
		scanf("%f", &(p_estudiantes+i)-> prom.n3);
		fflush(stdin);
	}
	
	float mejorProm=0;
	int poscAlumno=0;
	
	for(int i = 0; i < 3; i++){
		float div;
		div=((p_estudiantes+i)-> prom.n1 + (p_estudiantes+i)-> prom.n2 +  (p_estudiantes+i)-> prom.n3)/3;
		
		if(div > mejorProm){
			mejorProm = div;
			poscAlumno=i;
		}
	}
	printf("\n *** MEJOR PROMEDIO *** \n");
	printf("nombre: %s\n",(p_estudiantes+poscAlumno)->nombre);
	printf("grado: %d\n",(p_estudiantes+poscAlumno)->grado);
	printf("edad: %d\n",(p_estudiantes+poscAlumno)->edad);
	printf("nota 1: %1.1f\n",(p_estudiantes+poscAlumno)->prom.n1);
	printf("nota 2: %1.1f\n",(p_estudiantes+poscAlumno)->prom.n2);
	printf("nota 3: %1.1f\n",(p_estudiantes+poscAlumno)->prom.n3);
	printf("PROMEDIO : %1.1f\n",(mejorProm));
}

