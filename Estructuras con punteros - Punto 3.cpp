#include <stdio.h>
#include<stdlib.h>
	
struct trabajadores{
	
	char nombre_completo[60];
	char cedula[15];
	int edad;
	long salario;
	
}empleados[600],*p_empleados = empleados;

int main() 
{
	int a;
	int num_mayor;
	int num_menor;
	
	printf("ingrese el numero de trabajadores: ");
	scanf("%d", &a);
	
	long mayor = 000000, menor = 100000000;
	
	
	for(int i = 0 ; i <= a - 1; i++)
	{
		fflush (stdin);
		printf("Ingrese el nombre del trabajador: ");
		fgets((p_empleados+i)->nombre_completo,60,stdin);
		fflush (stdin);
		printf("Ingrese la cedula del trabajador: ");
		fgets((p_empleados+i)->cedula,15,stdin);
		fflush (stdin);
		printf("Ingrese la edad del trabajador: ");
		scanf("%d",&(p_empleados+i)->edad);
		fflush (stdin);
		printf("Ingrese el salario del trabajador: ");
		scanf("%d", &(p_empleados+i)->salario);
		fflush (stdin);
		printf("\n");
		
		
	}
	
	for(int j = 0 ; j <= a - 1; j++)
	{
		
		if(menor > (p_empleados+j)->salario)
		{
			
			menor = (p_empleados + j)->salario;
			num_menor = j;
		}
		if(mayor < (p_empleados+j)->salario)
		{
			mayor = (p_empleados+j)->salario;
			num_mayor = j;
		}
		
	}
	printf("El trabajador %s con la cedula %s tiene una edad de %d tiene el menor salario con un valor de %d\n ",(p_empleados + num_menor)->nombre_completo,(p_empleados+num_menor)->cedula,(p_empleados+num_menor)->edad,menor);
	printf("El trabajador %s con la cedula %s tiene una edad de %d tiene el mayor salario con un valor de %d\n ",(p_empleados+num_mayor)->nombre_completo,(p_empleados+num_mayor)->cedula,(p_empleados+num_mayor)->edad,mayor);
	return 0;
}
