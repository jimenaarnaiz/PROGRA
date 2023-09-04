/*Nombre: P5.6.c
 *Autor: JImena Arnaiz González
 *Descripción:
 **/

#include<stdio.h>
#include <math.h>


int main(){
	int opcion;

	printf("0 - Calcula el area de un cuadrado\n");
	printf("1 - Calcula el area de un ractángulo\n");
	printf("2 - Calcula el area de un rombo\n");
	printf("3 - Calcula el area de un círculo\n");
	printf("4 - Calcula el area de una corona circular\n");
	printf("5 - Calcula el area de un cuadrado\n");
	printf("6 - Calcula el perimetro de un ractángulo\n");
	printf("7 - Calcula el perimetro de un rombo\n");
	printf("8 - Calcula el perimetro de un círculo\n");
	printf("9 - Calcula el perimetro de una corona circular\n\n");
	printf("Elige una opcion: ");
	scanf("%d",&opcion);

	switch (opcion) {

		case 0:
		       	if (opcion == 0) {

			printf("0 - Calcula el area de un cuadrado\n");

			double lado;
			printf("Introduce la medida del lado: ");
			scanf("%lf",&lado);

			printf("El area del cuadrado es: %lf\n", lado*lado);
		
			}
		case 1:
		       	if (opcion == 1) {

			printf("1 - Calcula el area de un rectangulo\n");

			double base, altura;
			printf("Introduce la medida del base: ");
			scanf("%lf",&base);
			printf("Introduce la medida de la altura: ");
			scanf("%lf", &altura);

			printf("El area del cuadrado es: %lf\n", base*altura);
		
			}

		case 2: 
			if (opcion==2){
			printf("2 - Calcula el area de un rombo\n");
			
			double d1, d2;

			printf("Introduce la medida de la mediana mayor: ");
			scanf("%lf",&d1);

			printf("Introduce la medida de la mediana menor: ");
			scanf("%lf", &d2);
			
			printf("El area del rombo es: %lf\n",(d1*d2)/2);
		
			}


		case 3: 
			if (opcion==3){
			printf("3 - Calcula el area de un circulo\n");
			
			double r;

			printf("Introduce la medida del radio: ");
			scanf("%lf",&r);

			printf("El area del circulo es: %lf\n",M_PI*pow(r,2));
		
			}


		case 4: 
			if (opcion==4){
			printf("4 - Calcula el area de una corona circular\n");
			
			double r, R;

			printf("Introduce la medida del radio menor: ");
			scanf("%lf",&r);

			printf("Introduce la medida del radio mayor: ");
			scanf("%lf",&R);


			printf("El area de l acorona circular es: %lf\n",M_PI*pow((R-r),2));
		
			}

	}


		return 0;

}
