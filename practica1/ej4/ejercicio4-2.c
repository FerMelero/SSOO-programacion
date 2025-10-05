#include <unistd.h>   // fork, write, usleep, getpid
#include <stdlib.h>   // exit
#include <stdio.h>    // printf, perror
#include <fcntl.h>    // creat
#include <sys/types.h>

int main(void) {
    int i;
    int fd1, fd2;
    const char string1[10] = "**********";
    const char string2[10] = "----------";
    pid_t rf;

    fd1 = creat("ficheroA", 0666);
    fd2 = creat("ficheroB", 0666);
    if (fd1 < 0 || fd2 < 0) {
        perror("creat");
        exit(1);
    }

    rf = fork();
    switch (rf) {
        case -1:
            printf("No he podido crear el proceso hijo\n");
            break;

        case 0: // Proceso hijo
            for (i = 0; i < 10; i++) {
                write(fd1, string2, sizeof(string2));
                write(fd2, string2, sizeof(string2));
                sleep(1);
            }
            break;

        default: // Proceso padre
            for (i = 0; i < 10; i++) {
                write(fd1, string1, sizeof(string1));
                write(fd2, string1, sizeof(string1));
                usleep(5000);   
            }
            break;
    }

    printf("\nFinal de ejecución de %d\n", getpid());
    close(fd1);
    close(fd2);
    exit(0);
}

