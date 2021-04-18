#include <stdio.h>
#include <stdlib.h>
#include "Operaciones.h"

int X = 0;
int Y = 0;

int operacionHecha = 0;

void RegistrarX()
{
	printf("Ingrese el primer numero (A): ");
	scanf("%d", &X);
	operacionHecha=0;
}

void RegistrarY()
{
	printf("Ingrese el segundo numero (B): ");
	scanf("%d", &Y);
	operacionHecha=0;
}
void Mostrar()
{
	printf("A es %d \n", X);
	printf("B es %d \n", Y);
}

int OperacionSuma()
{
	int respuesta;
	int suma=0;
	suma= X+Y;
	respuesta=suma;
	return respuesta;
	operacionHecha=1;
}
int OperacionResta()
{
	int respuesta;
	int resta=0;
	resta= X-Y;
	respuesta=resta;
	return respuesta;
}
int OperacionMulti()
{
	int respuesta;
	int multiplicar=0;
	multiplicar= X*Y;
	respuesta=multiplicar;
	return respuesta;
}
int OperacionDivi()
{
	int respuesta;
	float dividir=0;
	if(Y!=0)
	{
		dividir= X/Y;
	}
	respuesta=dividir;
	return respuesta;
}
int OperacionFacX()
{
	int respuesta;
	int factorialX=X;
	int contadorX=X;
	for(contadorX=X;contadorX>0;contadorX--)
	{
		factorialX = factorialX*contadorX;
	}
	respuesta=factorialX;
	return respuesta;
}
int OperacionFacY()
{
	int respuesta;
	int contadorY=Y;
	int factorialY=Y;
	for(contadorY=Y;contadorY>0;contadorY--)
	{
		factorialY = factorialY*contadorY;
	}
	respuesta=factorialY;
	return respuesta;
}
void MostrarOperaciones()
{
	int suma;
	suma=OperacionSuma();
	int resta;
	resta=OperacionResta();
	int multi;
	multi=OperacionMulti();
	float divi;
	divi=OperacionDivi();
	int facX;
	facX=OperacionFacX();
	int facY;
	facY=OperacionFacY();
	if(operacionHecha==0)
	{
		printf("Error, no se han calculado los numeros ingresados");
	}
	else
	{
		printf("La suma da %d\n", suma);
		printf("La resta da %d\n", resta);
		printf("El producto da %d\n", multi);
		if(divi==0)
		{
			printf("No se puede dividir por 0");
		}
		else
		{
			printf("La divición da %2f\n", divi);
		}
		printf("El factoreo de A es %d\n", facX);
		printf("El factoreo de B es %d\n", facY);
	}
}
