/*Nombre del programa: P3.3.c
 *Descripcion: Pide el valor del radio de una circunferencia y muestra el area
 *Autor: Jimena Arnaiz González
 *Fecha: 28/02/2022
 *Vers: 1.0
 */


/*directivas al compilador*/

#include <stdio.h>
#define pi 3.14

/*prototipos de funciones*/
void pide_radio(int* r);
int area(int x);
int perimetro(int y);


/*funcion principal*/

int main () {
	int r;
	pide_radio(&r);
	area(r);
	perimetro(r);
	
	return 0;
}


/*definicion de funciones*/

void pide_radio(int* r) {
	printf("Introduce la medida del radio: ");
	scanf("%d",r);
}

int area(int x) {
	int a=pi*x*x;
	return printf("El area del circulo es: %d\n",a);
}

int perimetro(int y) {
	int p=2*pi*y;
	return printf("El perimetro del circulo es: %d\n",p);
}
