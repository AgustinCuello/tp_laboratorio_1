/*
 ============================================================================
Agustín Cuello 1°C
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "Operaciones.h"

int main(void) {
	int respuesta = 0;

	while(respuesta!=5){
		printf("Bienvenido a la calculadora programada\n");
		printf("1. Ingresar el primer numero (A)\n");
		printf("2. Ingresar el segundo numero (B)\n");
		printf("3. Calcular\n");
		printf("4. Mostrar los calculos resolvidos\n");
		printf("5. Salir\n");
		Mostrar();
		scanf("Opción %d",&respuesta);

		switch(respuesta){
			case 1:
				RegistrarX();
			break;
			case 2:
				RegistrarY();
			break;
			case 3:
				OperacionSuma();
				OperacionResta();
				OperacionMulti();
				OperacionDivi();
				OperacionFacX();
				OperacionFacY();
			break;
			case 4:
				MostrarOperaciones();
			break;
			case 5:
				return EXIT_SUCCESS;
			break;
		}
	}
}
