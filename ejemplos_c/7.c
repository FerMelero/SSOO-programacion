#include <stdio.h>
#define PI 3.1416
/* definición de constante */
int main () {
	float perim, radio; int dos=2;
	printf(" Calcula el perímetro de una circunferencia\n");
	printf(" Indique el tamaño de radio de la circunferencia");
	scanf("%f", &radio);
	perim= dos*PI*radio;
	printf(" El perímetro de la circunferencia es %f\n", perim);
	printf("Valores utilizados para calcular el perímetro:\n");
	printf(" Constante PI=%f, valor de dos = %d, radio=%f ",
	PI, dos,radio);
	return 0;
}
