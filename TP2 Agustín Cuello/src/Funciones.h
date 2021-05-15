#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#ifndef FUNCIONES_H_
#define FUNCIONES_H_

typedef struct
{
	 int id;
	 char name[51];
	 char lastName[51];
	 float salary;
	 int sector;
	 int isEmpty;
}Employee;

int Menu(void);

int MenuModificacion(void);

float PedirFlotante (char );

int PedirEntero (char );

void PedirString(char , char );

char PedirChar(char );

int searchFreeSpace(Employee , int );

int initEmployees(Employee , int );

int addEmployee(Employee , int, int );

int removeEmployee(Employee , int );

int modifyEmployee(Employee,int);

int sortEmployees(Employee , int);

int printEmployees(Employee , int );

int promediosalarios(Employee , int );

#endif /* FUNCIONES_H_ */
