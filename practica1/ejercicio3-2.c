#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {

	int i = 0;
	int j;
	pid_t rf;
	rf = fork();
	
	switch (rf){
	
		case -1:
			printf("\nNo he podido crear el proceso hijo");
			break;
		
		case 0:
			printf("\nSoy el ehijo, mi PID es %d y mi variable i (inicialmente a %d) es par", getpid(), i);
			for (j = 0; j < 5; j++){
				i++;
				i++;
				printf("\nSoy el hijo, mi variable i es %d", i);
			
			}
			
			break;
		
		default:
			printf("\nSoy el padre, mi PID es %d y mi variable i (inicalmente a %d) es impar", getpid(), i);
			for (j = 0; j < 5; j++){
				i++;
				printf("\nSoy el padre, mi variable i es %d", i);
			}
	
	}
	
	printf("\nFinal de ejecución de %d\n", getpid());
	exit(0);









}
