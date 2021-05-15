#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "Funciones.h"

int Menu(void)
{
    int opcion;

    printf("\n BIENVENIDO AL REGISTRO DE EMPLEADOS \n");
    printf(" 1. ALTA\n");
	printf("2. BAJA\n");
	printf("3. MODIFICAR\n");
	printf("4. LISTADO DE EMPLEADOS POR NOMBRE \n");
	printf("5. LISTADO DE TOTAL Y PROMEDIO DE SALARIOS \n");
	printf("6. LISTADO DE EMPLEADOS CON SALARIO MAYOR AL PROMEDIO \n");
	printf("0. Salir\n");
    opcion = PedirEntero("Opción: ");

    return opcion;
}

int MenuModificacion(void)
{
    int opcion;

    printf(" 1. NOMBRE\n");
	printf("2. APELLIDO\n");
	printf("3. SALARIO\n");
	printf("4. SECTOR \n");
	printf("0. Salir\n");
    opcion = PedirEntero("Opción: ");

    return opcion;
}

int PedirEntero (char mensaje [])
{
    int numeroIngresado;

    printf("%s", mensaje);
    scanf("%d", &numeroIngresado);

    return numeroIngresado;
}

float PedirFlotante (char mensaje [])
{
    float numeroIngresado;

    printf("%s", mensaje);
    scanf("%f", &numeroIngresado);

    return numeroIngresado;
}

void PedirString(char mensaje [], char *string)
{
    printf("%s", mensaje);
    fflush(stdin);
    scanf("%s", string);
}

char PedirChar(char mensaje [])
{
    char charIngresado;
    printf("%s", mensaje);
    fflush(stdin);
    scanf("%c", charIngresado);
    return charIngresado;
}

int initEmployees(Employee list, int len)
{
	int i;
	for (i = 0; i < len; i++)
	{
		list[i].isEmpty = 1;
	}
	return 0;
}

int searchFreeSpace(Employee list, int len)
{
	int i;
	int index;
	for(i=0;i<len;i++)
	{
		if(list[i].isEmpty==1)
		{
			index=i;
		}
		else
		{
			index=-1;
		}
	}
	return index;
}

int addEmployee(Employee list, int len, int i)
{
	list[i].id=i;
	PedirString("Ingrese Nombre de empleado: ",list[i].name);
	PedirString("Ingrese Appelido de empleado: ",list[i].lastName);
	list[i].salary=PedirFlotante("Ingrese salario: ");
	list[i].sector=PedirEntero("Ingrese el numero del sector: ");
	list[i].isEmpty=0;
	return 1;
}

int findEmployeeById(Employee list, int len,int id)
{
	int i;
	for(i=0;i<len;i++)
	{
		if(id==list[i].id)
		{
			break;
		}
	}
	return i;
}

int removeEmployee(Employee list, int len)
{
	int i;
	int IDborrar;
	IDborrar=PedirEntero("Ingrese el id del empleado a dar de baja");
	i=findEmployeeById(list, len, IDborrar);
	list[i].isEmpty=1;
	list[i].id=-1;

	return -1;
}

int modifyEmployee(Employee list , int len)
{
	int i;
	int IDmodificar;
	int opcion;
	int entero;
	float flotante;
	IDmodificar=PedirEntero("Ingrese el id del empleado a dar de baja");
	i=findEmployeeById(list, len, IDmodificar);
	opcion=PedirEntero("Opcion:");
	switch(opcion)
	{
		case 1:
			PedirString("Ingrese el nuevo nombre: ",list[i].name);
		break;
		case 2:
			PedirString("Ingrese el nuevo apellido: ",list[i].lastName);
		break;
		case 3:
			flotante=PedirFlotante("Ingrese el nuevo salario: ");
			list[i].salary=flotante;
		break;
		case 4:
			entero=PedirEntero("Ingrese el nuevo sector del empleado: ");
		break;
		default:
		break;
	}
	return -1;
}

int sortEmployees(Employee list, int len)
{
	Employee aux;
	int i;
	int j;
	for(i=0;i<len-1;i++)
	{
		for(j=i+1;j<len;j++)
		{
			if(strcmp(list[i].lastName,list[j].lastName)<0 && list[i].sector<list[j].sector)
			{
				aux=list[i];
				list[i]=list[j];
				list[j]=aux;
			}
		}
	}
	return 0;
}

int printEmployees(Employee list, int length)
{
	int i;
	for(i=0;i<length;i++)
	{
		printf("ID: %d \nNombre: %s \nApellido: %s \nSalario: %f \nSector: %d",list[i].id,list[i].lastName,list[i].name,list[i].salary,list[i].sector);
	}
	return 0;
}

int promediosalarios(Employee list, int len)
{
	int i;
	float sumaSalarios;
	float promedioSalarial;
	int contador;
	int contadorMasSalario;
	for(i=0;i<len;i++)
	{
		if(list[i].isEmpty!=1)
		{
			sumaSalarios=sumaSalarios+list[i].salary;
			contador++;
		}
	}
	printf("Total de salarios: %3f", sumaSalarios);
	promedioSalarial=sumaSalarios/contador;
	printf("El promedio de salarios es de: %3f",promedioSalarial);
	for(i=0;i<len;i++)
	{
		if(list[i].isEmpty!=1 && list[i].salary>promedioSalarial)
		{
			contadorMasSalario++;
		}
	}
	printf("La cantidad de empleados que superan el salario promedio es de %d empleados", contadorMasSalario);
	return -1;
}

