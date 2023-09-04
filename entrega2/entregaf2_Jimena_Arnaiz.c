/**
 *Nombre: entregaf.c
 *Autor:Jimena Arnaiz González
 *Descripción: Programa que muestra un menú en el que puedes elegir diferentes opciones.
 *Fcha: 5/05/2022
 * */

/*directivas al preprocesador*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h> //biblioteca para cadenas de carácteres largas

/*prototipos de funciones*/

int solicitarOpcionMenu();
void seleccionarOpcion(int);

int contarCaracteres(FILE*);
int numeroTotalFilas(FILE*);
void limpiarBuffer();
int filaMasLarga(FILE*);
int otraFila(FILE*, FILE*);
bool validaEntero(int, int, int, int, char);
bool validaReal(float, float, float, int, char);

int menuMarcasMoviles();

int battery();
int blue();
float clockSpeed();
int dualSim();
int fc();
int intMemory();
int fourG();
float mDep();
int mobileWt();
int nCores();
int pc();
int ram();
int scH();
int scW();


/*funcion principal*/

int main (){
	int opcion;
	
	do{
	opcion= solicitarOpcionMenu();
	seleccionarOpcion(opcion);
	}

	while(opcion!=0); //repite el do mientras no se elija 0
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

	printf("\nBIENVENIDO AL MENÚ\n");
	printf("******************************************************\n");
	printf("*  1. Número total de caracteres alfanuméricos       *\n"); 	
	printf("*  2. Número total de filas, sin contar la cabecera  *\n");
	printf("*  3. Fila más larga                                 *\n");
     	printf("*  4. Añadir nueva fila                              *\n"); 	
	printf("*  0. Salir                                          *\n");                          
	printf("******************************************************\n");

	do {
		printf("Elige una opción: ");
		leidos=scanf("%d", &num); //scanf devuelve 1 o 0 si recoge bien las var introducidas.
		if(leidos!=1){ 
			printf("\n¡La entrada era incorrecta!\n");
			limpiarBuffer();
		}
	
	} while ( num > 4 || num < 0 || leidos !=1 );
	
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
	FILE* pf2; //DatosMovilesv2.csv

		switch (num){
			case 0: 
				printf("Has elegido: 0. Salir\n");
				pf=fopen("DatosTelefonosMoviles.csv", "r"); //abrimos el archivo dada su ubicación para realizar su lectura

				if (pf==NULL){ //el archivo puede no abrirse corrrectamente, por lo que dará un error
					printf("\nERROR: No se puede abrir el archivo. Es posible que no exista.\n");
				}
				else { //si se abre correctamente, se ejecuta la opción 0 (salir)
					exit(-1);
				}

				if(fclose(pf)==0){ /*fclose devuelve 0 si se hace bien*/ 	
					printf("\nSe ha cerrado el archivo DatosTelefonosMoviles.csvcorrectamente\n");
				}

				else {
					printf("\nNo se ha cerrado el archivo DatosTelefonosMoviles.csvcorrectamente\n");
				}

				break;	
		

			case 1:
				printf("Has elegido: 1. Número total de caracteres alfanuméricos\n");
				
				pf=fopen("DatosTelefonosMoviles.csv", "r"); 
				
				if (pf==NULL){ 

					printf("\nERROR: No se puede abrir el archivo. Es posible que no exista.\n");
				}

				else { 	

					printf("Hay %d caracteres alfanuméricos\n",contarCaracteres(pf));
				}

				if(fclose(pf)==0) {
				
					printf("\nSe ha cerrado el archivo DatosTelefonosMoviles.csvcorrectamente\n");
				}

				else {
					printf("\nNo se ha cerrado el archivo DatosTelefonosMoviles.csvcorrectamente\n");
				}

				break;
		

			case 2 :
				printf("Has elegido: 2. Número total de filas, sin contar la cabecera\n");
				pf=fopen("DatosTelefonosMoviles.csv", "r"); 
				
				if (pf==NULL){ 

					printf("\nERROR: No se puede abrir el archivo. Es posible que no exista.\n");
				}

				else { 	

					printf("Hay un total de %d filas\n", numeroTotalFilas(pf));
				}

				
				if(fclose(pf)==0) {
				
					printf("\nSe ha cerrado el archivo DatosTelefonosMoviles.csv correctamente\n");
				}

				else {
					printf("\nNo se ha cerrado el archivo DatosTelefonosMoviles.csv correctamente\n");
				}

				break;			
			

			case 3:
				printf("Has elegido: 3. Fila más larga \n");

				pf=fopen("DatosTelefonosMoviles.csv", "r"); 
				
				if (pf==NULL){ 

					printf("\nERROR: No se puede abrir el archivo. Es posible que no exista.\n");
				}

				else { 	
	
				printf("La fila %d es la más larga\n",filaMasLarga(pf));
			
				}
			
				if(fclose(pf)==0) {
				
					printf("\nSe ha cerrado el archivo DatosTelefonosMoviles.csv correctamente\n");
				}

				else {
					printf("\nNo se ha cerrado el archivo DatosTelefonosMoviles.csv correctamente\n");
				}

				break;	

			case 4:
				printf("Has elegido: 4. Añadir fila nueva \n");

				pf=fopen("DatosTelefonosMoviles.csv", "r"); 
				
				if (pf==NULL){ 

					printf("\nERROR: No se puede abrir el archivo. Es posible que no exista.\n");
				}

				else { 	
					pf2=fopen("DatosTelefonosMovilesv2.csv", "w"); //se abre el archivo 2 en modo escritura

					otraFila(pf,pf2);
			
				}
			
				if(fclose(pf2)==0) {
				
					printf("\nSe ha cerrado el archivo DatosTelefonosMovilesv2.csv correctamente\n");
				}

				else {
					printf("\nNo se ha cerrado el archivo DatosTelefonosMovilesv2.csv correctamente\n");
				}

				
				if(fclose(pf)==0) {
				
					printf("\nSe ha cerrado el archivo DatosTelefonosMoviles.csv correctamente\n");
				}

				else {
					printf("\nNo se ha cerrado el archivo DatosTelefonosMoviles.csv correctamente\n");
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


/**
 *Nombre: validaEntero
 *Descripción: función que valida el dato introducido
 *Parámetros de entrada:
	@param num: valor a valida
       	@param lim_inf: limite lim_inf del rango admitido
       	@param lim_sup: limite lim_sup del rango admitido
       	@param leidos: num de los valores leídos por teclado q devuelve scanf
       	@param enter: salto de línea introducido por teclado
 	
 *Return: resultado de la validación (Booleano)
 * */


bool validaEntero(int num, int lim_inf, int lim_sup, int leidos, char enter){
	
//leidos=scanf("%d%c", &(opcion que se quiera en ese momento),&enter);

	if (leidos!=2 || enter!='\n' || num<lim_inf || num>lim_sup){
		printf("⚠ ⚠ ⚠ ⚠ ⚠ ⚠ ⚠ ⚠ ⚠ ⚠ ⚠ ⚠ ⚠ ⚠ ⚠ ⚠ ⚠ ⚠ ⚠ ⚠ ⚠ ⚠ ⚠\n");
		printf(" Datos mal introducidos, vuelva a intentarlo\n");
		printf("⚠ ⚠ ⚠ ⚠ ⚠ ⚠ ⚠ ⚠ ⚠ ⚠ ⚠ ⚠ ⚠ ⚠ ⚠ ⚠ ⚠ ⚠ ⚠ ⚠ ⚠ ⚠ ⚠\n");
	
		limpiarBuffer();
	return 0; //false

	}

	else

	return 1; //true
	
	}


/**
 *Nombre: validaReal
 *Descripción: función que valida que el dato introducido sea un num real
 *Parámetros de entrada:
	@param num: valor a valida
       	@param lim_inf: limite lim_inf del rango admitido
       	@param lim_sup: limite lim_sup del rango admitido
       	@param leidos: num de los valores leídos por teclado q devuelve scanf
       	@param enter: salto de línea introducido por teclado
 	
 *Return: resultado de la validación (Booleano)
 * */


bool validaReal(float num, float lim_inf, float lim_sup, int leidos, char enter){

	if (leidos!=2 || enter!='\n' || num<lim_inf || num>lim_sup){

		printf("⚠ ⚠ ⚠ ⚠ ⚠ ⚠ ⚠ ⚠ ⚠ ⚠ ⚠ ⚠ ⚠ ⚠ ⚠ ⚠ ⚠ ⚠ ⚠ ⚠ ⚠ ⚠ ⚠\n");
		printf(" Datos mal introducidos, vuelva a intentarlo\n");
		printf("⚠ ⚠ ⚠ ⚠ ⚠ ⚠ ⚠ ⚠ ⚠ ⚠ ⚠ ⚠ ⚠ ⚠ ⚠ ⚠ ⚠ ⚠ ⚠ ⚠ ⚠ ⚠ ⚠\n");

		limpiarBuffer();

	return 0; //false

	}

	else

	return 1; //la función devolverá true (1)
}

/**
 *Nombre:otraFila
 *Descripción: Añade una fila nueva en un nuevo fichero y crea un nuevo fichero con los datos actualizados
 *Parámetros de entrada: FILE*, FILE*
 *Return: int
 **/

int otraFila(FILE* f, FILE* f2){

	char c;
	
	c=fgetc(f); //lectura adelantada

	while(!feof(f)){ 
	//mientras no sea fin de fichero, copia lo que hay en el archivo1 al archivo2
	
		fprintf(f2,"%c", c);
		c=fgetc(f);
	}

	//lo q devuelvan las funciones, se escribe en el archivo f2:
	
	fprintf(f2,"%d,", battery()); //se pone %d, para que separe con comas los datos
	fprintf(f2,"%d,", blue());
	fprintf(f2,"%0.1f,", clockSpeed()); //0.1 para q ponga hasta 1 decimal
	fprintf(f2,"%d,", dualSim());
	fprintf(f2,"%d,", fc() );
	fprintf(f2,"%d,", fourG() );
	fprintf(f2,"%d,", intMemory());
	fprintf(f2,"%0.1f,", mDep());
	fprintf(f2,"%d,", mobileWt());
	fprintf(f2,"%d,", nCores());
	fprintf(f2,"%d,", pc());
	fprintf(f2,"%d,", ram());
	fprintf(f2,"%d,", scH());
	fprintf(f2,"%d,", scW());
	
	int marca=menuMarcasMoviles();

	switch (marca){
	//permite a partir del entero introducido, mostrar la opción elegida como texto

	
		case 1: return fprintf(f2,"Apple"); 
		//si la opción elegida es 1, escribe en el ficherov2 "Apple" en en vez del 1
			break;

	
		case 2: return fprintf(f2,"HTC");
			break;
		
	
		case 3: return fprintf(f2,"LG"); 
			break;
		
		
		case 4: return fprintf(f2,"Nokia"); 
			break;
	
	
		case 5: return fprintf(f2,"Samsung"); 
			break;
		
		
		case 6: return fprintf(f2,"Xiaomi"); 
			break;
		
		
		case 7: return fprintf(f2,"ZTE"); 
			break;
		}
	
	return 0;
}


/**
 *Nombre: menuMarcasMoviles
 *Descripción: Muestra un menú con 7 nombres de marcas de móvil y solicita una opción hasta que la entrada sea válida
 *Parámetro de entrada: -
 *Return: int
 **/

int menuMarcasMoviles(){

	int num, lim_inf=1, lim_sup=7, leidos; //declaramos e inicializamos las var q usaremos en validaEntero
	char enter; 
	bool valida=0; //false


	do{
		printf("MENÚ DE MARCAS TELEFÓNICAS\n");
		printf("********************\n");
		printf("*  1. Apple        *\n"); 	
		printf("*  2. HTC          *\n");
		printf("*  3. LG           *\n");
     		printf("*  4. Nokia        *\n");
     		printf("*  5. Samsung      *\n"); 
     		printf("*  6. Xiaomi       *\n"); 
     		printf("*  7. ZTE          *\n"); 		         
		printf("********************\n");

		printf("Elige una opción: ");

		leidos=scanf("%d%c", &num, &enter); 

		valida=validaEntero(num, lim_inf, lim_sup, leidos, enter); 
		//como "valida" la inicializamos como false, hasta q no se introduzca un valor válido, no se saldrá del bucle while, 
		//pidiéndote otra vez el dato y mostrando el menú
		
	}

	while (valida==0); // 0 es false

	return num;
}

/*----------------------------------------------------------------------------------------------
* Las siguientes funciones tienen la misma estructura, se declaran e inicializan las var necesarias 
* para la validación del dato introducido. Luego se hace un bucle do while para que si lo introduces mal, 
* te vuelva a pedir el dato
-----------------------------------------------------------------------------------------------*/

/**
 *Descripción: Función en la q tienes q introducir un dato limitado por un rango establecido
 *Parámetro de entrada: -
 *Return: int
 **/
 
int battery () {

	int num, lim_inf=0, lim_sup=2000, leidos;
	char enter;	
	bool valida;

	do
	{
		printf("\nIntroduce la batería\n"
				"\tTiene que estar entre los valores 0-2000, siendo un número entero\n");
		leidos=scanf("%d%c", &num,&enter);//Recoge un entero y el enter pulsado
		
		valida=validaEntero(num, lim_inf, lim_sup, leidos, enter); //se comprueba q los datos están bien introducidos

	}

	while(valida==0); //cuando el dato (valida) se introduzca bien, se saldrá del bucle

	return num;	
}


/**
 *Descripción: Función en la q tienes q introducir un dato limitado por un rango establecido
 *Parámetro de entrada: -
 *Return: int
 **/
 
int blue () {

	int num, lim_inf=0, lim_sup=1, leidos;
	char enter;	
	bool valida;

	do
	{
		printf("\nIntroduce el blue\n"
				"\tTiene que ser 0 o 1\n");
		leidos=scanf("%d%c", &num,&enter);//Escanea un entero y el enter pulsado
		valida=validaEntero(num, lim_inf, lim_sup, leidos, enter); //se comprueba q los datos están bien introducidos

	}

	while(valida==0);

	return num;	
}


/**
 *Descripción: Función en la q tienes q introducir un dato limitado por un rango establecido
 *Parámetro de entrada: -
 *Return: float
 **/
 
float clockSpeed () {

	float num, lim_inf=0, lim_sup=3, leidos;
	char enter;	
	bool valida=0;

	do
	{
		printf("\nIntroduce la velocidad de reloj\n"
				"\tTiene que estar entre 0-3, siendo un número real\n");
		leidos=scanf("%f%c", &num,&enter);//Escanea el real y el enter pulsado
		valida=validaEntero(num, lim_inf, lim_sup, leidos, enter);
	}

	while(valida==0);

	return num;	
}


/**
 *Descripción: Función en la q tienes q introducir un dato limitado por un rango establecido
 *Parámetro de entrada: -
 *Return: int
 **/
 
int dualSim () {

	int num, lim_inf=0, lim_sup=1, leidos;
	char enter;	
	bool valida=0;

	do
	{
		printf("\nIntroduce si tiene dual SIM\n"
				"\tTiene que ser 0 o 1\n");
		leidos=scanf("%d%c", &num,&enter);//Escanea un entero y el enter pulsado
		valida=validaEntero(num, lim_inf, lim_sup, leidos, enter);

	}

	while(valida==0);

	return num;	
}


/**
 *Descripción: Función en la q tienes q introducir un dato limitado por un rango establecido
 *Parámetro de entrada: -
 *Return: int
 **/
 
int fc () {

	int num, lim_inf=0, lim_sup=20, leidos;
	char enter;	
	bool valida=0;

	do
	{
		printf("\nIntroduce el fc\n"
				"\tTiene que ser del 0-20\n");
		leidos=scanf("%d%c", &num,&enter);//Escanea un entero y el enter pulsado
		valida=validaEntero(num, lim_inf, lim_sup, leidos, enter);

	}

	while(valida==0);

	return num;	
}


/**
 *Descripción: Función en la q tienes q introducir un dato limitado por un rango establecido
 *Parámetro de entrada: -
 *Return: int
 **/
 
int fourG () {

	int num, lim_inf=0, lim_sup=1, leidos;
	char enter;	
	bool valida=0;

	do
	{
		printf("\nIntroduce si four g\n"
				"\tTiene que ser 0 o 1\n");
		leidos=scanf("%d%c", &num,&enter);
		valida=validaEntero(num, lim_inf, lim_sup, leidos, enter);
	}

	while(valida==0);

	return num;	
}


/**
 *Descripción: Función en la q tienes q introducir un dato limitado por un rango establecido
 *Parámetro de entrada: -
 *Return: int
 **/
 
int intMemory () {

	int num, lim_inf=0, lim_sup=100, leidos;
	char enter;	
	bool valida=0;

	do
	{
		printf("\nIntroduce la memoria interna\n"
				"\tTiene que ser un número entero del 0-100\n");
		leidos=scanf("%d%c", &num,&enter);
		valida=validaEntero(num, lim_inf, lim_sup, leidos, enter);
	}

	while(valida==0);

	return num;	
}


/**
 *Descripción: Función en la q tienes q introducir un dato limitado por un rango establecido
 *Parámetro de entrada: -
 *Return: int
 **/
 
int pc () {

	int num, lim_inf=0, lim_sup=20, leidos;
	char enter;	
	bool valida=0;

	do
	{
		printf("\nIntroduce el pc\n"
				"\tTiene que ser un número entero del 0-20\n");
		leidos=scanf("%d%c", &num,&enter);
		valida=validaEntero(num, lim_inf, lim_sup, leidos, enter);
	}

	while(valida==0);

	return num;
}


/**
 *Descripción: Función en la q tienes q introducir un dato limitado por un rango establecido
 *Parámetro de entrada: -
 *Return: float
 **/
 
float mDep () {

	float num, lim_inf=0, lim_sup=1, leidos;
	char enter;	
	bool valida=0;

	do
	{
		printf("\nIntroduce el M Dep\n"
				"\tTiene que ser un número real del 0-1\n");
		leidos=scanf("%f%c", &num,&enter);
		valida=validaEntero(num, lim_inf, lim_sup, leidos, enter);
	}

	while(valida==0);

	return num;	
}



/**
 *Descripción: Función en la q tienes q introducir un dato limitado por un rango establecido
 *Parámetro de entrada: -
 *Return: int
 **/
 
int mobileWt () {

	int num, lim_inf=0, lim_sup=200, leidos;
	char enter;	
	bool valida=0;

	do
	{
		printf("\nIntroduce el peso del móvil\n"
				"\tTiene que ser un número entero del 0-200\n");
		leidos=scanf("%d%c", &num,&enter);
		valida=validaEntero(num, lim_inf, lim_sup, leidos, enter);

	}

	while(valida==0);

	return num;	
}



/**
 *Descripción: Función en la q tienes q introducir un dato limitado por un rango establecido
 *Parámetro de entrada: -
 *Return: int
 **/
 
int nCores () {

	int num, lim_inf=0, lim_sup=10, leidos;
	char enter;	
	bool valida=0;

	do
	{
		printf("\nIntroduce el número de cores\n"
				"\tTiene que ser un número entero del 0-10\n");
		leidos=scanf("%d%c", &num,&enter);
		valida=validaEntero(num, lim_inf, lim_sup, leidos, enter);
	}

	while(valida==0);

	return num;	
}


/**
 *Descripción: Función en la q tienes q introducir un dato limitado por un rango establecido
 *Parámetro de entrada: -
 *Return: int
 **/
 
int ram () {

	int num, lim_inf=0, lim_sup=4000, leidos;
	char enter;	
	bool valida=0;

	do
	{
		printf("\nIntroduce la memoria de la RAM\n"
				"\tTiene que ser un número entero del 0-4000\n");
		leidos=scanf("%d%c", &num,&enter);
		valida=validaEntero(num, lim_inf, lim_sup, leidos, enter);
	}

	while(valida==0);

	return num;	
}


/**
 *Descripción: Función en la q tienes q introducir un dato limitado por un rango establecido
 *Parámetro de entrada: -
 *Return: int
 **/
 
int scH () {

	int num, lim_inf=0, lim_sup=20, leidos;
	char enter;	
	bool valida=0;

	do
	{
		printf("\nIntroduce sc H\n"
				"\tTiene que ser un número entero del 0-20\n");
		leidos=scanf("%d%c", &num,&enter);
		valida=validaEntero(num, lim_inf, lim_sup, leidos, enter);
	}

	while(valida==0);

	return num;	
}


/**
 *Descripción: Función en la q tienes q introducir un dato limitado por un rango establecido
 *Parámetro de entrada: -
 *Return: int
 **/
 
int scW () {

	int num, lim_inf=0, lim_sup=20, leidos;
	char enter;	
	bool valida=0;

	do
	{
		printf("\nIntroduce sc W\n"
				"\tTiene que ser un número entero del 0-20\n");
		leidos=scanf("%d%c", &num,&enter);
		valida=validaEntero(num, lim_inf, lim_sup, leidos, enter);

	}

	while(valida==0);

	return num;	
}

