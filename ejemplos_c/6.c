#include <stdio.h>
int main () {
	char c;
	int n, d;
	n= sizeof(c);
	printf(" el número de bytes de la variable c es %d\n", n);
	n= sizeof(d);
	printf(" el número de bytes de la variable d es %d\n", n);
	n= sizeof(int);
	printf(" el número de bytes que ocupa el tipo entero es %d\n",
	n);
	n= sizeof(double);
	printf(" el número de bytes que ocupa el tipo double es %d\n",
	n);
	return 0;
}
