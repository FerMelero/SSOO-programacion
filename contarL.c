#include <stdio.h>


int main(int argc, char **argv) {
	
	if (argc < 2) { fprint(stderr, "Uso %s fichero\n", argv[0]};
		return 1;}
	
	FILE *f = fopen(argv[1], "r");
	if (!f) {perror("fopen"); return 1; }
	int c, lineas = 0;
	while ((c = fgetc(f)) != EOF) if (c == '\n') lineas ++;
	fclose(f);
	printf("%d\n", lineas);
	
	
	
	
	
	return 0;
}

