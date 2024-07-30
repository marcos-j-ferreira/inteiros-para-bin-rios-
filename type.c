#include <stdio.h>
#include "type.h"

int bin(int number){

    int y = number;

    if (number < 0) {
        printf("Número inválido. Digite um número não-negativo.\n");
    }

    // Determina o tamanho necessário para armazenar a representação binária
    int temp = number;
    int bits = 0;
    while (temp > 0) {
        temp /= 2;
        bits++;
    }

    // Aloca memória para armazenar a representação binária
    int *bin = (int *)malloc(bits * sizeof(int));
    if (bin == NULL) {
        perror("Falha ao alocar memória");
    }

    // Preenche o array com a representação binária
    int index = 0;
    while (number > 0) {
        bin[index++] = number % 2;
        number /= 2;
    }

    printf("%d em binary: ", y);
    // Imprime a representação binária na ordem correta
    for (int i = bits - 1; i >= 0; i--) {
        printf("%d", bin[i]);
    }
    printf("\n");

    return 0;
}