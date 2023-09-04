/*Nombre del programa: P3.1.c
 * Descripcion: Pide el valor del lado de un cuadrado y muestra el perímetro y el área
 *Autor: Jimena Arnaiz González
 *Fecha: 25/02/2022
 *Vers: 1.0
 */


/*directivas*/
#include <stdio.h>


/*declaracion de prototipos*/
void pide_lado(int* l);
int area(int x);
int perimetro(int y);


/*funcion principal*/
int main () {
	
	int l; //la dir esta vacia

	pide_lado(&l); //pasamos la direcc de l para q ahora contega un valor (%d)
	area(l);
	perimetro(l);

return 0;
}


/*declaracion de funciones*/
void pide_lado (int* l) {
	printf("Introduce la medida del lado del cuadrado: ");
	scanf("%d", l);
}	

int area (int x) {
	int a=x*x;
	return printf("El area es: %d\n",a);
}

/*funcion que calcula el perimetro. cuando el compilador llega aqui,
 * sustituye la y por el valor de l*/

int perimetro (int y) {
	int p=4*y;
	return printf("El perimetro es: %d\n",p);

}
