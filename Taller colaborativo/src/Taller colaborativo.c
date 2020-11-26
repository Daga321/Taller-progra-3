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

void functionConcatenate(char* stringI, char* stringD, int numberOfRepetitions, char direction){
	/*
	StringD es la cadena que quedara a la DERECHA
	StringI es la cadena que quedara a la IZQUIERDA
	 */
	int size;
	if (direction=='I') {
		size = strlen(stringI)+numberOfRepetitions;
	}else{
		size = strlen(stringD)+numberOfRepetitions;
	}
	char* stringC[size];
	if (direction=='I') {
		strcpy(stringC, "");
	}else{
		strcpy(stringC, stringI);
	}
	for (int i = 0; i < numberOfRepetitions; i++) {
		strcat(stringC, stringD);
	}
	if (direction=='I') {
		strcat(stringC, stringI);
	}
	printf("El resultado de nuestra funcion ha sido el siguiente %s\n",stringC);
}

void Concatenate(){
	printf("Vamos a ingresar la cadena a utilizar\n");
	char* stringA = getString(0);
	printf("Vamos a ingresar el caracter a repetir\n");
	char* stringB = getString(1);
	char option;
	while(1){
		printf("Si desea repetir el caracter por el lado izquierdo de la cadena ingrese 'I', si desea repetir el caracter por el lado derecho de la cadena ingrese 'D'\n");
		scanf("%c", &option);
		if (option=='I') {
			break;
		} else if(option=='D'){
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
	printf("Por favor ingresa la cantidad de veces que deseas repetir el caracter");
	scanf("%i", &numberOfRepetitions);
	functionConcatenate(stringA, stringB, numberOfRepetitions, option);
}

char* functionEncrypt(char* string, char* encrypted){
	int ascii;
	//	for (int i= 0; i < strlne(string); i++) {
	//		ascii = string[i];
	//	}
	//	string = (char*)realloc(string,stringSize + 1);
	char stringC[strlen(encrypted)+strlen(string)];
	//	strcpy(stringC, stringD);
	//	strcat(stringC, stringI);
	strcat(encrypted, string);
	printf("Concatenado perfectamente");

	return string;
}

void encrypt(){
	char* string = getString(0);
	printf("El mensaje se a codificado correctamente\nEl neuvo mensaje es: %s\n",functionEncrypt(string, "#"));
}

//char* functionDecrypt(){
//
//
//}

void decrypt(){
	char* string = getString(0);


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
				"7) Intersección\n"
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
		printf("Presiona enter para volver al menu\n");
		fflush(stdin);
		getchar();
	}while(option!='0');
}

int main(void) {

	menu();

	return EXIT_SUCCESS;
}
