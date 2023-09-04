/*Nombre: P4.32.c
 *Autor: Jimena Arnaiz Gonzalez
 *Descripción: Pide el número de lados y el valor del radio de un polígono regular.
El programa calculará y mostrará el perímetro y el área de dicho
polígono.
 *Fecha: 16703/2022
 * */


#include <stdio.h>
#include <math.h> //añadir al gcc -lm

/*prototipos de funciones*/

int pide_lados();
void pide_radio (float*);
float perimetro(int, float); 
float longitud_lado (float, int);
void area (float, float);
float apotema (float);
//void resultados (float, float);

/*funcion principal*/

int main () {
	int n;
	float l, P, ap, r;
	
	n = pide_lados();
	pide_radio (&r);
	l = longitud_lado (r,n);
	ap = apotema (l);
	P= perimetro(n, l);
	area (P, ap);
	//resultados(P,A);

		
	return 0;
}

int pide_lados(){
	int num;
	printf("Introduce el número de lados que quieres que tenga tu poligono regular: \n");
	scanf("%d",&num);
	return 	num;
}


void pide_radio (float* rad){
	printf("Introduce el radio: ");
	scanf("%f", rad);
}


float perimetro(int nlad , float lad){
	float P= nlad*lad;
	return printf("El perimetro es: %f\n", P);

}
float longitud_lado (float rad, int num ){
	float lon= sqrt(2*pow(rad,2)*(1-cos(360/num)));
	return lon;

}
void area (float per, float apot){
	//float A= per*apot;
	printf("El area es: %f\n", per*apot);
} 

float apotema (float llad){
	float ap= sqrt(pow(llad,2)+pow(1/2*llad,2));
	return ap;
}

 /*
  void reultados(float P, float A){
	printf("El perimetro es: %d\n", P);
	printf("El area es: %d\n", A);
 }
 */
