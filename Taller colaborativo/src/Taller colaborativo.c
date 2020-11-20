/*
 ============================================================================
 Name        : Taller.c
 Author      : Daga
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void menu(){
	char opcion;
	do{
		system("cls");
		printf("MENU:\n"
			   "1) Convertir en nombre Propio el contenido de la cadena\n"
			   "2) Contar el numero de veces que existe una palabra en una cadena\n"
			   "3) Encriptar cadena\n"
			   "4) Desencriptar\n"
			   "5) Llenar caracteres por Izquierda o por Derecha\n"
			   "6) Borrar caracteres de una cadena\n"
			   "7) Intersección\n"
			   "8) Diferencia entre dos cadenas\n"
			   "9) Borrar caracteres Izquierda o Derecha\n"
			   "0) Salir\n"
			   "Por favor selecciona una opcion\n");
		scanf("%c", &opcion);
		system("cls");
		switch(opcion){

		case '1':

		break;

		case '2':

		break;

		case '3':

		break;

		case '4':

		break;

		case '5':

		break;

		case '6':

		break;

		case '7':

		break;

		case '8':

		break;

		case '9':

		break;

		default:
			printf("La opcion \"%c\" NO existe, por favor ingresa una opcion valida\n", opcion);
		break;
		}
		printf("Presiona enter para volver al menu\n");
		fflush(stdin);
		getchar();
	}while(opcion!='0');
}

int main(void) {
	menu();
	printf("Adios\n");
	return EXIT_SUCCESS;
}
