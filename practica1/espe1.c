#include <unistd.h>   // fork, getpid, getppid, sleep
#include <stdio.h>    // printf
#include <stdlib.h>   // exit
#include <sys/wait.h> // wait

int main(void) {
    pid_t rf;

    rf = fork();
    switch (rf) {
        case -1:
            printf("\nNo he podido crear el proceso hijo\n");
            break;

        case 0: // Proceso hijo
            printf("Soy el hijo, mi PID es %d y mi PPID es %d\n", getpid(), getppid());
            sleep(10);
            break;

        default: // Proceso padre
            printf("Soy el padre, mi PID es %d y el PID de mi hijo es %d\n", getpid(), rf);
            wait(0); // espera a que termine el hijo
            sleep(10); // sleep después del wait para esperar al finalizar
            break;
    }

    printf("\nFinal de ejecución de %d\n", getpid());
    exit(0);
}

