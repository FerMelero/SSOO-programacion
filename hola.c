#include <stdio.h>

void saludar(const char *nombre) {
	printf("Hola, %s!\n,", nombre);
}

int main() {
	
	for (int i=0; i < 5; i++){
		if (i%2 == 0) {
			printf("%d es par\n", i);
		} else {
			printf("%d es impar\n", i);
		}
	}
	printf("Hola mundo desde C\n");
	saludar("Ana");
	return 0;

}
