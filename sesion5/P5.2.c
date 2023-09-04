#include <stdio.h>
#include <stdbool.h> //me da bool, true, false


//prototipos

bool validafecha(int*, int*, int*);
void pidefecha(int, int, int);
int muestrafecha (int, int, int);

//funcion principal

int main () {
	
	int dia, mes, anio;

	pidefecha(dia, mes, anio);
	validafecha(&dia, &mes, &anio);
	muestrafecha(dia, mes, anio);

	return 0;
}


void pidefecha(int d, int m, int a){
	printf("Introduce una fecha: ");
	scanf("%d/%d/%d", &d, &m ,&a);
}
*
/**
 *Descripcion:
 *Devuelve: no
 */

bool validafecha(int* dia, int* mes, int* anio){
	bool fechacorrecta = false;
	
	if (*anio>0) {
		switch (*mes){
			case 1:  
			case 3:
			case 5:
			case 7:
			case 8:
			case 10:
			case 12:
				if (*dia > 0 && *dia <= 31)
					fechacorrecta = true;
				break;
			case 4:
			case 6:
			case 9:
			case 11:
				if (*dia > 0 && *dia <= 30)
					fechacorrecta = true;
				break;
			
		
			case 2:
				if (*dia > 0 && *dia <= 28)
					fechacorrecta = true;

				}
 			}
}


int muestrafecha (int d, int m, int a){
	return printf("%d/%d/%d\n", d, m, a);
}

