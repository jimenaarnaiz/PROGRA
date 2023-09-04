/*Nombre programa: P4.1.c
 *Descripcion: Pide el valor de las diagonales de un rombo y nos muestra el
perímetro y el área.
 *Fecha: 04/03/2022
 *Versión: 1.0
 */


#include <stdio.h>
#include <math.h>

/*prototipos de funciones*/

void pide_diagonal(float*);
float perimetro (float, float);
float area(float, float);

/*funcion principal*/

int main () {
	float D, d;

	pide_diagonal(&d);
	pide_diagonal(&D);
	perimetro(d,D);
	area(d,D);
	
}

void pide_diagonal(float* numero){
	printf("Introduce el valor de la diagonal \n");
	scanf("%f", numero);
}

float perimetro(float d1, float D2){
	
	float per=2*d1+D2;


	return printf("El perimetro es: %f\n", per);
}

float area(float d1, float D2) {

	//printf("%f, %f\n", d1, D2); para ver q d1 y D2 son d y D

	float a=d1*1/2*D2;

	return printf("El area es: %f\n",a);

}
