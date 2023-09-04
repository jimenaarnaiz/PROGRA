/**
 *Descripción: Realizar un programa que lea una letra minúscula (a-z)
e imprima la letra leída en mayúscula.
 */

#include <stdio.h>


/*prototipos*/
char leerletra();
void convertiramayus(char*);
void escribirletra(char);

int main () {
	char min;
	min = leerletra();
	convertiramayus(&min);
	escribirletra(min);

	return 0;
}
char leerletra(){
	char letra;
	printf("Introduzca una letra en minusculas: ");
	scanf("%c", &letra);

	return letra;
}

void convertiramayus(char* minus){ 
	printf("%d",*minus-32);
	printf("%c", *minus);
	
}

void escribirletra(char letra){
	printf("\nLa letra en mayusculas es %c\n", letra);
}

