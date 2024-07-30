#include "type.h"

int main (void){
    
    int repetir; 
    scanf("%d", &repetir);
    int number = 0;
    int contador = 0;
    while(contador < repetir){
        scanf("%d", &number);
        printf("\n");
        bin(number);
        contador++;
    }

    return 0;
}