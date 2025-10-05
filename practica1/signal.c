#include <unistd.h>   // write, read
#include <stdlib.h>   // exit
#include <signal.h>   // signal
#include <stdio.h>    // printf


// este código admite el Ctrl + C como señal para terminar
void noacabar(int sig) {

    write(1, "\nNo voy a terminar", 19);

}

int main(void) {
    signal(SIGTERM, noacabar);

    printf("Mi PID es %d. Envía una señal SIGTERM \n", getpid());

    while(1) {   
        sleep(1);
    }

    return 0;
}

