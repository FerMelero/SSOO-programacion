#include <stdio.h>
#include <stdbool.h>

int main() {

    int numero = 0;
    int suma = 0;
    //int x = 1;
    //int fact = 1;
    printf("Introduce un número: ");
    scanf("%d", &numero);

    if(numero < 0){
        printf("El número debe ser mayor a 0");
        return 0;
    }

    for(int i = 1; i <= numero; i++){
        if(numero == 0){
            printf("1");
            return 0;
        }
        suma += i;

    }
    printf("%d", suma);

    while(true){
       
    }
    
   // while(x <= numero){
     //   fact *= x;
       // x += 1;

    
   // printf("\n%d", fact);

    return 0;
}
