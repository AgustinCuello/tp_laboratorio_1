/*
 ============================================================================
 Name        : TP2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio_ext.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>

#include "Funciones.h"

#define X 100

int main(void) {

	Employee List[X];

	initEmployees(List, X);

	int opcion;
	int espacioLibre;
	int agregado=0;
	int error;

	while(opcion!=0)
	{
		opcion=Menu();
		switch(opcion)
		{
			case 1:
				espacioLibre=searchFreeSpace(List,X);
				if(espacioLibre==-1)
				{
					agregado=addEmployee(List,X,espacioLibre);
				}
				else
				{
					puts("No hay lugares disponibles");
				}
			break;
			case 2:
				if(agregado!=1)
				{
					puts("No hay empleados agregados");
				}
				else
				{
					printEmployees(List,X);
					removeEmployee(List, X);
				}
			break;
			case 3:
				if(agregado!=1)
				{
					puts("No hay empleados agregados");
				}
				else
				{
					printEmployees(List,X);
					modifyEmployee(List,X);
				}
			break;
			case 4:
				if(agregado!=1)
				{
					puts("No hay empleados agregados");
				}
				else
				{
					sortEmployees(List , X);
					printEmployees(List,X);
				}
			break;
			case 5:
				if(agregado!=1)
				{
					puts("No hay empleados agregados");
				}
				else
				{
					promediosalarios(List,X);
				}
			break;
			default:
			break;
		}
	}
	return EXIT_SUCCESS;
}
