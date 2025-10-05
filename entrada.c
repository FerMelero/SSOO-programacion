#include <stdio.h>


int main() {
	
	char nombre [100];
	
	printf("Introduce tu nombre ");
	if (fgets (nombre, sizeof(nombre), stdin) != NULL) {
		printf("Hola, %sBienvenido al curso de C\n", nombre);
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
