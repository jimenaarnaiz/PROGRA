/*Nombre: P4.5.c
 * Descripción: pide valores de los radios de una corona circular y nos muestra su area y perimetro
 *Autor: Jimena Arnaiz González
 *Fecha: 20/03/2022
 * */


//directivas

#include <stdio.h>
#include <math.h>

/*declaración de prototipos*/

float pide_radiom();
float pide_radioM();
float calculoarea(float, float);
float perimetro(float, float);
void resultados(float, float);


/*funcion principal*/

int main () {
	float radio, Radio, area, per; //declaracion de variables
	
	radio= pide_radiom();
	Radio= pide_radioM();
	per = perimetro(Radio, radio);
	area = calculoarea(Radio, radio);
	resultados(per, area);
	
	return 0;
}

/*
 *
 *
 *
 */

float pide_radiom(){
	float radio;
	printf("Introduce el radio menor: ");
	scanf("%f",&radio);
	return radio;
}

float pide_radioM(){
	float Radio;
	printf("Introduce el radio mayor: ");
	scanf("%f",&Radio);
	return Radio;
}

float calculoarea(float R, float r){
	float A = M_PI*pow((R-r),2);
	return A;
}


float perimetro(float R, float r){
	float P = 2*M_PI*R+2*M_PI*r;
	return P;

}

void resultados(float per, float area){
	printf("El perimetro es: %f\n", per);
	printf("El area es: %f\n", area);

}
