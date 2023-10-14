/**
 *Nombre: entrega1.c
 *Autor: Jimena Arnaiz González
 *Fecha: 1/04/2022
 *Descripción: Programa en el que aparece un menu y depende de lo que elija el usuario calcula una cosa u otra.
 **/

/*directivas*/

#include<stdio.h>

/*prototipos de los módulos*/
void pideNum(int*);
void limpiarBuffer();
int factorial();
void divisores();
void perfecto();

/*funcion principal*/

int main () {
	
	int opcion; //declaramos la variable con la que el usuario eligirá hacer una opción o una
	int num; //declaramos la var con la que calcularemos el factorial 

/*mostramos por pantalla lo que es el menú*/
	printf("1 - Calcular el factorial de un numero\n");
	printf("2 - Calcular los divisores de un numero\n");
	printf("3 - Comprobar si un número es perfecto\n\n");
	printf("Elige una opcion: ");
	pideNum(&opcion);
		
	switch (opcion) {
			
			case 1: 
				
				printf("Introduce un numero para calcular su factorial: ");
				scanf("%d",&num);
				printf("El factorial de %d es: %d \n",num, factorial(num));			
				break;

			case 2:	divisores();

				break;

			case 3: perfecto();

				break;
		}

	return 0;
}

/**
 *Nombre: factorial
 *Descripción: calcula el factorial de un número
 *Parámetros de entrada: int
 *Return: int
 * */
int factorial(int n){
	int f=1,i;
	for (i=1; i<=n; i++){
		f=f*i;
	}
	return f;
}


/**
 *Nombre: divisores()
 *Descripción: Calculas los divisores de un número
 *Parámetros de entrada: ninguno
 *Retorno: nada (void)
 * */

void divisores(){
	int i,n;
	
	printf("Introduca el numero para calcular sus divisores : ");
	scanf("%d",&n);
	
	if(n>=0){ //comprobamos que sea positivo
	
		for (i=1; i <= n/2; i++){ /*Creamos un bucle que vaya desde el 1 hasta el numero introducido por el usuario entre dos*/

			if (n%i == 0 ){ //si el resto de la división es 0 se imprimen los divisores
				printf("los divisores de %i son: %d\n", n,i);
			}
		}		
	}
}

/**
 *Nombre: perfecto()
 *Descripción: funcion que dice si un número es perfecto o no 
 *Parámetro de entrada: ninguno
 *Retorno: ninguno (void)
 */

void perfecto(){
	int num,i,suma = 0;

	printf("Introduca el numero para comprobar que es perfecto: ");
	scanf("%d",&num);
	
	if(num>=0){ //comprobamos que el número no sea negativo

		 for (i=1;i<num;i++){ //con el bucle inicalizamos i a 1 y repetimos el bucle mientras i sea menor que el número introducido 
		 	 
	 		if(num%i==0)
		 		suma+=i;
		 }
	 		if(suma==num)
	 			printf("El número %d es perfecto \n",num);
			else
	 			printf("El número %d no es perfecto \n",num);
	}
}

/**
 *Nombre: pideNum
 *DEscripción: Función que pide números y que dice cuándo está mal intrducido.
 *Parámetro de entrada: int* 
 *Return: ninguno (void)
 * */

void pideNum(int* num){
	int leidos;

	do {
		printf("Elige una opción: ");
		leidos=scanf("%d", num); //scanf devuelve 1 o 0 si recoge bien las var introducidas.
		if(leidos!=1){ 
			printf("La entrada era incorrecta\n");
			limpiarBuffer();
		}
	
	} while ( *num > 3 || leidos !=1);

}

/**
 *Nombre: limpiarBuffer
 *Descripción: función que limpia el buffer de entrada
 *Parámetro de entrada: ninguno
 *Return: nada (void)
 * */

void limpiarBuffer(){
	char c;
	do {
		c=getchar();
	} while (c!='\n');
}


