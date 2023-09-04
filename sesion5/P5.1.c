#include <stdio.h>

int pideNum();
void calculaMinMax(int, int, int, int*, int*);
void imprimirMax(int, int, int, int, int );

int main () {
	int a,b,c,min,max;

	a =pideNum();
	b=pideNum();
	c=pideNum();
	
	calculaMinMax(a, b, c, &min, &max);
	imprimirMax(a, b, c, min, max);

	return 0;
}

/**Descripcion: Pide un numero entero al usuario
 * @return: Entero introducido por el usuario
*/

//como queremos recoger 2 valores, no se puede hacer por referencia.
//en void se ponen las 3 con * para poder cambiar su valor

int pideNum(){
	int numero;

	printf("Introduce un num entero: ");
	scanf("%d", &numero);
	
	return numero;
}

/**
 * Descripcion: 
 * 
 */	
	
	
void calculaMinMax(int n1, int n2, int n3, int* min, int* max){
	//calculo el max
	if (n1>n2){
		if(n1>n3){
		  *max=n1;
		}
		else  {
		  *max=n3;
		}
	}
	else {
	     	if (n2>n3){
		   *max=n2;
		}
		else {
		   *max=n3;
		}
	}

//calculo min
	if (n1<n2){
		if(n1<n3){
		  *min=n1;
		}
		else  {
		  *min=n3;
		}
	}
	else {
	     	if (n2<n3){
		   *max=n2;
		}
		else {
		   *min=n3;
		}
	}
}

void imprimirMax(int n1, int n2, int n3, int min, int max){
	printf("El minimo de %d, %d, %d es %d\n", n1, n2, n3, min);
	printf("El máximo de %d, %d, %d es %d\n", n1, n2, n3, max);
}
