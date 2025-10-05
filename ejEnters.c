#include <stdio.h>


int main() {
	
	int entero;
	
	printf("Introduce un numero ");
	if (fgets (entero) >= 0 ) {
		printf("El n'umero es par");
	} else {
		printf("Error al leer el nombre. \n");
	
	}
	int N; long suma = 0;
	if(scanf("%d", &N) != 1 || N<0) return 1;
	for(int i=0; i <N; i++) {int x; if (scanf("%d", &x) != 1) return 1;
		suma += x; }
	printf("&ld\n", suma);
	
	return 0;
}
