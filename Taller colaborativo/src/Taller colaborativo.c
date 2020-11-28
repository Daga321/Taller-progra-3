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
#include <string.h>

/*
link donde se ha hallado el codigo para el getString():
https://es.stackoverflow.com/questions/31601/guardar-cadena-de-caracteres-en-c
el codigo se encuentra al final de la pagian
 */

char* getString(int chararacter){
	//la variable que entra ha de ser un numero cualesquiera o 0, esto haria como true or false para determinar
	//si esta solicitando una cadena o un caracter unico, uds diran que por que no use el scanf("%c", variacleChar);
	// esto se debe que para concatenar se usa la funcion strcat(cadena que recive, cadena que da info), es una funcion
	//que trabaja unicamente con char* y no admite char
	fflush(stdin);
	char* string;
	string = 0;
	int stringSize = 0;
	do{
		if (chararacter) {
			printf("Por favor ingrese el caracter que desea utilizar:\n");
			string = (char*)realloc(string,stringSize + 1);
			int c = getchar();
			string[stringSize] = (char)c;
			string[stringSize+1] = 0;
		}else {
			printf("Por favor ingrese la cadena de caracteres que desea utilizar:\n");
			fflush(stdout);
			while( 1 ) {
				string = (char*)realloc(string,stringSize + 1);
				int c = getchar();
				if( c == 10 ){
					string[stringSize] = 0;
					break;
				}
				string[stringSize] = (char)c;
				stringSize++;
			}
		}

		if ((int)(string[0])==0) {
			printf("Lo lamento pero no podemos procesar un espacio en blanco como una cadena\n");
			printf("Presiona enter para ingresar una cadena\n");
			fflush(stdin);
			getchar();
			system("cls");
		}
	}while((int)(string[0])==0);

	return string;
}

void functionConcatenate(char* string, char* character, int numberOfRepetitions, char direction){
	/*
	character es el caracter
	string es la cadena
	 */
	int size;
	if (direction=='I') {
		size = strlen(string)+numberOfRepetitions;
	}else{
		size = strlen(character)+numberOfRepetitions;
	}
	char* stringC[size];
	if (direction=='I') {
		strcpy(stringC, "");
	}else{
		strcpy(stringC, string);
	}
	for (int i = 0; i < numberOfRepetitions; i++) {
		strcat(stringC, character);
	}
	if (direction=='I') {
		strcat(stringC, string);
	}
	printf("El resultado de nuestra funcion ha sido el siguiente %s\n",stringC);
}

void Concatenate(){
	printf("Vamos a ingresar la cadena a utilizar\n");
	char* string = getString(0);
	printf("Vamos a ingresar el caracter a repetir\n");
	char* character = getString(1);
	char option;
	while(1){
		printf("Si desea repetir el caracter por el lado izquierdo de la cadena ingrese 'I', si desea repetir el caracter por el lado derecho de la cadena ingrese 'D'\n");
		fflush(stdin);
		scanf("%c", &option);
		if (option=='I' || option=='D') {
			break;
		}else {
			printf("Lo lamento pero no podemos procesar la opcion %c\n", option);
			printf("Presiona enter para ingresar una opcion valida\n");
			fflush(stdin);
			getchar();
			system("cls");
		}
	}
	int numberOfRepetitions;
	do {
		printf("Por favor ingresa la cantidad de veces que deseas repetir el caracter\n");
		scanf("%i", &numberOfRepetitions);
		if (numberOfRepetitions<=0) {
			printf("Lo lamento pero no es posible repetir un caracter %i veces\n",numberOfRepetitions);
			printf("Presiona enter para ingresar un numero mayor a 0\n");
			fflush(stdin);
			getchar();
			system("cls");
		}
	} while (numberOfRepetitions<=0);
	functionConcatenate(string, character, numberOfRepetitions, option);
}

void functionEncrypt(char* string){
//	la idea que tome como referencia para encriptar fue cuando en los celulares de antes (las flechitas) tocaba oprimir varias
//	veces una tecla para asi ingresar una letra, en esta ocacion lo que el programa muestra es el equivalente al numero que se
//	oprimio n veces. De ser una letra mayuscula el numero sera negativo.
//	todó esto usando el codigo ascii para identificar las letras, ya sean mayusculas o minusculas. si se ingresa culaquier caracter
//	se mostrara su codigo ascii sin ninguna modificacion, en caso de ser un espacio se imprime un 0
//
//	por favor hagan pruebas de encriptado, si llegan a encontrar algun tipo de falla me lo informan por el foro. Gracias.

	int ascii;
	int numberOfRepetitions;
	int value;
	for (int i = 0; i < strlen(string); i++) {
		ascii = (int)string[i];
		if (ascii==32) {
			printf("0");
		}else if ((ascii>=65 && ascii<=90) || (ascii>=97 && ascii<=122)) {
			if((ascii>=65 && ascii<=90)){
						printf("-");
						ascii+=32;
					}

					if ((ascii>=97 && ascii<=99) ) {//#2
						numberOfRepetitions=(ascii-96);
						value = 2;
					} else if ((ascii>=100 && ascii<=102) ) {//#3
						numberOfRepetitions=(ascii-99);
						value = 3;
					} else if ((ascii>=103 && ascii<=105) ) {//#4
						numberOfRepetitions=(ascii-102);
						value = 4;
					} else if ((ascii>=106 && ascii<=108) ) {//#5
						numberOfRepetitions=(ascii-105);
						value = 5;
					} else if ((ascii>=109 && ascii<=111) ) {//#6
						numberOfRepetitions=(ascii-108);
						value = 6;
					} else if ((ascii>=112 && ascii<=115) ) {//#7
						numberOfRepetitions=(ascii-111);
						value = 7;
					} else if ((ascii>=116 && ascii<=118) ) {//#8
						numberOfRepetitions=(ascii-115);
						value = 8;
					} else if ((ascii>=119 && ascii<=122) ) {//#9
						numberOfRepetitions=(ascii-118);
						value = 9;
					}
					for (int j = 0; j <numberOfRepetitions; j++) {
						printf("%i",value);
					}
		}else{
			printf("%i",ascii);
		}
		printf("*");
	}
	printf("\n");

}

void encrypt(){
	char* string = getString(0);
	functionEncrypt(string);
}

void functionDecrypt(char* string){
	int value;
	int multiplier;
	int identifier;
	char* number = strtok(string, "*");
	if(number != NULL){
		while(number != NULL){
			value = 0;
			multiplier = 1;
			identifier = (((int)number[strlen(number)-1])-48);
			if (identifier==0) {
				identifier=-1;
			}
			for (int i = strlen(number)-1; i >= 0 ; i--) {
				if (number[i]=='-') {
					value*=-1;
				}else{
					value += (((int)number[i])-48)*multiplier;
					multiplier*=10;
				}
			}

			if (((value/identifier)==1 || (value/identifier)==11 || (value/identifier)==111 || (value/identifier)==1111 || //mayusculas
				(value/identifier)==-1 || (value/identifier)==-11 || (value/identifier)==-111 || (value/identifier)==-1111)//minusculas
				&& (identifier!=1)){
				if (value<0) {
					value*=-1;
					value = (58+(identifier*3)+strlen(number)-1);
					number[strlen(number)-1]=0;
				}else{
					value = (90+(identifier*3)+strlen(number));
				}
				if (identifier==8 || identifier==9) {
					value++;
				}
				if (((identifier!=7 && identifier!=9) && strlen(number)<4) || ((identifier==7 || identifier==9) && strlen(number)<5)) {
					printf("%c",(char)value);
				}else{
					printf("\nERROR no se ha pododido desencriptar el mensaje debido a que se enceuntra corrompido");
					break;
				}
			}else if(value==-1){
				printf(" ");
			}else{
				if ((value>255 || value<0) || (value>=65 && value<=90) || (value>=97 && value<=122)) {
					printf("\nERROR no se ha pododido desencriptar el mensaje debido a que se enceuntra corrompido\n");
					break;
				}else{
					printf("%c",(char)value);
				}
			}
			number = strtok(NULL, "*");
		}
		printf("\n");
	}else{
		printf("ERROR la cadena ingresada no esta hecha para desencriptar○2n");
	}

}

void decrypt(){
	char* string = getString(0);
	functionDecrypt(string);
}

void functionName(char* string){

/*
	Compañeros esta es la funcion que convierte en nombre propio las cadenas de caracteres
	ingresadas, la implemente teniendo en cuenta el codigo ascii, mediante la suma y resta
	de los valores a los cuales corresponde cada letra, les recomiendo que por favor hagan
	pruebas y en caso de algun error por favor avisar en el foro.
*/

	int numCharacters = strlen(string);

	if(string[0] != ' ' && string[1] != ' ' && strlen(string) > 1){
		if(string[0] >= 'a' && string[0]<='z'){
			string[0] = (char)(('A'-'a') + string[0] );
		}
	}

	else if (string[0] >= 'A' && string[0] <= 'Z'){
		string[0] = (char)(string[0] + ('a' - 'A'));
	}

	for(int i=1; i<numCharacters; i++){

		if((string[i-1] != ' ') || (string[i-1] == ' ' && string[i+1] == ' ' ) || (string[i+1] == '\0')){
			if (string[i] >= 'A' && string[i] <= 'Z'){
				string[i] = (char)(string[i] + ('a' - 'A'));
			}
		}
		else if (string[i] >= 'a' && string[i] <= 'z'){
			string[i] = (char)(('A'-'a') + string[i] );
		}
	}

	printf("La cadena de caracteres ingresa convertida en nombre propio es: %s\n", string);
}

void name(){
	char* string = getString(0);
	functionName(string);
}


void menu(){
	char option;
	do{
		system("cls");
		printf("MENU:\n"
				"1) Convertir en nombre Propio el contenido de la cadena\n"
				"2) Contar el numero de veces que existe una palabra en una cadena\n"
				"3) Encriptar cadena\n"
				"4) Desencriptar\n"
				"5) Llenar caracteres por Izquierda o por Derecha\n"
				"6) Borrar caracteres de una cadena\n"
				"7) Interseccion\n"
				"8) Diferencia entre dos cadenas\n"
				"9) Borrar caracteres Izquierda o Derecha\n"
				"0) Salir\n"
				"Por favor selecciona una opcion\n");

		scanf("%c", &option);
		system("cls");
		switch(option){

		case '1':
			name();
			break;

		case '2':

			break;

		case '3':
			encrypt();
			break;

		case '4':
			decrypt();
			break;

		case '5':
			Concatenate();
			break;

		case '6':

			break;

		case '7':

			break;

		case '8':

			break;

		case '9':

			break;

		case '0':
			printf("Adios\n");
			break;

		default:
			printf("La opcion \"%c\" NO existe, por favor ingresa una opcion valida\n", option);
			break;
		}
		if (option!='0') {
			printf("Presiona enter para volver al menu\n");
			fflush(stdin);
			getchar();
		}
	}while(option!='0');
}

int main(void) {
	menu();
	return EXIT_SUCCESS;
}
