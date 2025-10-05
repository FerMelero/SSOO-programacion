#include <stdio.h>
#include <string.h>

struct Persona {
	char nombre[50];
	int edad;
	};

int main() {
	
	struct Persona p1;
	strcpy(p1.nombre, "Ana");
	p1.edad = 22;
	printf("Nombre: %s, Edad: %d\n", p1.nombre, p1.edad);
	return 0;

}
