/**
 *Nombre: Menu.c
 *Autor:Jimena Arnaiz González
 *Descripción: Programa que muestra un menú en el que puedes elegir diferentes opciones.
 *Fcha: 24/04/2022
 * */

/*directivas al preprocesador*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*prototipos de funciones*/

int solicitarOpcionMenu();
void seleccionarOpcion(int);
int contarCaracteres(FILE*);
int numeroTotalFilas(FILE*);
void limpiarBuffer();
int filaMasLarga(FILE*);


/*funcion principal*/

int main (){
	int opcion;
	
	opcion= solicitarOpcionMenu();
	seleccionarOpcion(opcion);

	return 0;
}


/* funciones empleadas: */

/**
 *Nombre: solicitarOpcionMenu
 *Descripción: Muestra un menú con las opciones que puedes elegir 

 *Parámetros de entrada: -
 *Return: int
 **/

int solicitarOpcionMenu(){
	
	int leidos,num;

	printf("BIENVENIDO AL MENÚ\n");
	printf("******************************************************\n");
	printf("*  1. Número total de caracteres alfanuméricos       *\n"); 	
	printf("*  2. Número total de filas, sin contar la cabecera  *\n");
	printf("*  3. Fila más larga                                 *\n");   
	printf("*  0. Salir                                          *\n");                                         
	printf("******************************************************\n");

	do {
		printf("Elige una opción: ");
		leidos=scanf("%d", &num); //scanf devuelve 1 o 0 si recoge bien las var introducidas.
		if(leidos!=1){ 
			printf("La entrada era incorrecta\n");
			limpiarBuffer();
		}
	
	} while ( num > 3 || num < 0 || leidos !=1 );
	
	return num;
}

/**
 *Nombre: solicitarOpcionMenu
 *Descripción: Permite elegir las opciones elegidas en el menú
 *Parámetros de entrada: int
 *Return: - (por ser void)
 **/

void seleccionarOpcion(int num){

	FILE* pf; //la var pf hace referencia a la dir del buffer de memoria


		switch (num){
			case 0: 
				printf("Has elegido: 0. Salir\n");
				pf=fopen("/home/jimena/Escritorio/PROG/entregafinal/DatosTelefonosMoviles.csv", "r"); //abrimos el archivo dada su ubicación para realizar su lectura

				if (pf==NULL){ //el archivo puede no abrirse corrrectamente, por lo que dará un error
					printf("\nERROR: No se puede abrir el archivo. Es posible que no exista.\n");
				}
				else { //si se abre correctamente, se ejecuta la opción 0 (salir)
					exit(-1);
				}

				if(fclose(pf)==0){ /*fclose devuelve 0 si se hace bien*/ 	
					printf("\nSe ha cerrado el archivo entregaf.c correctamente\n");
				}

				else {
					printf("\nNo se ha cerrado el archivo entregaf.c correctamente\n");
				}

				break;	
		

			case 1:
				printf("Has elegido: 1. Número total de caracteres alfanuméricos\n");
				
				pf=fopen("/home/jimena/Escritorio/PROG/entregafinal/DatosTelefonosMoviles.csv", "r"); 
				
				if (pf==NULL){ 

					printf("\nERROR: No se puede abrir el archivo. Es posible que no exista.\n");
				}

				else { 	

					printf("Hay %d caracteres alfanuméricos\n",contarCaracteres(pf));
				}

				if(fclose(pf)==0) {
				
					printf("\nSe ha cerrado el archivo entregaf.c correctamente\n");
				}

				else {
					printf("\nNo se ha cerrado el archivo entregaf.c correctamente\n");
				}

				break;
		

			case 2 :
				printf("Has elegido: 2. Número total de filas, sin contar la cabecera\n");
				pf=fopen("/home/jimena/Escritorio/PROG/entregafinal/DatosTelefonosMoviles.csv", "r"); 
				
				if (pf==NULL){ 

					printf("\nERROR: No se puede abrir el archivo. Es posible que no exista.\n");
				}

				else { 	

					printf("Hay un total de %d filas\n", numeroTotalFilas(pf));
				}

				
				if(fclose(pf)==0) {
				
					printf("\nSe ha cerrado el archivo entregaf.c correctamente\n");
				}

				else {
					printf("\nNo se ha cerrado el archivo entregaf.c correctamente\n");
				}

				break;			
			

			case 3:
				printf("Has elegido: 3. Fila más larga \n");

				pf=fopen("/home/jimena/Escritorio/PROG/entregafinal/DatosTelefonosMoviles.csv", "r"); 
				
				if (pf==NULL){ 

					printf("\nERROR: No se puede abrir el archivo. Es posible que no exista.\n");
				}

				else { 	
	
				printf("La fila %d es la más larga\n",filaMasLarga(pf));
			
				}
			
				if(fclose(pf)==0) {
				
					printf("\nSe ha cerrado el archivo entregaf.c correctamente\n");
				}

				else {
					printf("\nNo se ha cerrado el archivo entregaf.c correctamente\n");
				}

				break;			
		}
}


/**
 *Nombre: contarCaracteres 
 *Descripción: Cuenta los caracteres de un fichero que le llega por parámetro
 *Parámetros de entrada: FILE*
 *Return: int
 **/
int contarCaracteres(FILE* f){
	char c;
	int letras=0, nums=0; //actúan como contadores
	
	c = fgetc(f); 

	while (!feof(f)){ //mientras no sea final de fichero se ejecuta el bucle while
		
		if ((c>='a' && c<='z') || (c >= 'A' && c <= 'Z')) { //si el caracter que se lee es una letra (minús. o mayús.) se aumenta el contador
			letras++;
		}
		if (c>='0' && c<='9'){ //si el caracter leído es un número, se aumentar el contador
			nums++;
		}
		c = fgetc(f); //se lee un caracter del archivo 
	}

	int alf=letras+nums;

	return alf;
}



/**
 *Nombre: numeroTotalFilas
 *Descripción: Cuenta el nº total de las filas del fichero, sin contar la cabecera
 *Parámetros de entrada: FILE*
 *Return: int
 **/

int numeroTotalFilas(FILE* f){
	int filas=0; //actúa como contador
	int c = getc(f);

	while (!feof(f)){  //mientras no sea fin de archivo se ejecuta el bucle
		
		if (c == '\n'){  //si el caracter que se lee es un salto de línea, se aumenta en 1 el contador de filas
		
		filas++;

		}
		
		c = getc(f);
	}

	return filas-1; //se resta la fila de la cabecera
}



/**
 *Nombre:filaMasLarga
 *Descripción: Devuelve el índice de la fila con más caracteres
 *Parámetros de entrada: FILE*
 *Return: int
 **/


 int filaMasLarga(FILE* f){

	bool cabecera = false; //este bool nos sirve para no contar la 1a fila, o sea la cabecera
	char c; //declaraciones de var
	int caract=0, filas=1, lector=0, flarga=0, caractlarga=0; //contadores a 0, excepto la de las filas actuales, pues la cabecera no cuenta

	c = fgetc(f); //lectura adelantada

	while (!feof(f)){ 

		if (c!= '\n') { //si el caracter leído no es un salto de línea

			lector++; //se aumenta el contador
		} 
		
		else { //si se lee un salto de línea se aumenta en 1 el contador de líneas
	
			if (cabecera == false) {
				cabecera=true;
			}
			else{

			filas++; 			
			caract = lector; 

			if (caract > caractlarga){
				flarga=filas; //la fila actual se guarda como la fila más larga de momento 
				caractlarga=caract; //el nº de caracteres actual se le asigna al nº de caracteres de la fila más larga

			}
			}

			lector=0; //el contador vuelve a 0 para que solo se cuenten los caracteres de cada fila, no en total
				
		}

		c = fgetc(f);

	
	}
	
	return flarga;	
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
		c = getchar();
	} while (c!='\n');
}

