// En P4.3.c es float per, long y area, no void

/*Nombre programa: P4.2.c
 *Descripcion: Definir un tipo de dato enumerado para los días de la semana.
 *Fecha: 11/03/2022
 *Versión: 1.0
 */


#include <stdio.h>

int main () {
	enum dias {lunes, martes, miercoles, jueves, viernes, sabado, domingo};
	enum dias semana; //

	semana = lunes;

	printf("%d\n",semana++); //nunca sale lunes, sino 0, q es por dnd empieza enum
	printf("%d\n",semana++);
	printf("%d\n",semana++);
	printf("%d\n",semana++);
	printf("%d\n",semana++);
	printf("%d\n",semana++);
	printf("%d\n",semana++);


return 0;
}
