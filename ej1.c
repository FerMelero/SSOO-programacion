#include <stdio.h>
#include <stdbool.h>

//Lee un entero desde la entrada estándar. Usando if/else, imprime si es positivo, negativo o cero. Después, indica si es par o impar. Maneja correctamente el signo y el valor cero.

int main(){

    int numero = 0;
    bool positivo = true;
    bool par = true;
    

    printf("Introduce un número: ");
    scanf("%d", &numero);

    printf("\n");

    if (numero == 0){
        printf("El 0 es par\n");
        return 0;
    }

    if(numero < 0){
        positivo = false;
        
    }

    if (numero%2 != 0) {
        par = false;
    }

    if (positivo && par) {
        printf("El número es positivo y par\n");
    } else if (positivo && !par) {
        printf("El número es positivo e impar\n");
    } else if (!positivo && par) {
        printf("El número es negativo y par\n");
    } else {
        printf("El número es negativo e impar\n");
    }






    return 0;
}