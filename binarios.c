#include <stdio.h>
#include <stdlib.h>

// Função que converte um número decimal para binário e imprime o resultado
// Input: Um número inteiro decimal
// Output: Impressão da representação binária do número no console
void formula(int number) {
    if (number < 0) {
        printf("Número inválido. Digite um número não-negativo.\n");
        return;
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
        exit(1);
    }

    // Preenche o array com a representação binária
    int index = 0;
    while (number > 0) {
        bin[index++] = number % 2;
        number /= 2;
    }

    // Imprime a representação binária na ordem correta
    for (int i = bits - 1; i >= 0; i--) {
        printf("%d", bin[i]);
    }
    printf("\n");

    // Libera a memória alocada
    free(bin);
}

// Função que permite ao usuário inserir números e ver suas representações binárias
// A função continua a executar até que o usuário escolha parar
void repetir(void) {
    int again;  // Variável para armazenar a escolha do usuário sobre continuar ou não
    int number;  // Variável para armazenar o número inserido pelo usuário

    do {
        printf("Digite um número não-negativo: ");
        if (scanf("%d", &number) != 1) {
            printf("Entrada inválida. Por favor, insira um número inteiro.\n");
            while (getchar() != '\n');  // Limpa o buffer de entrada
            continue;
        }

        printf("\n");
        formula(number);  // Converte o número para binário e imprime
        printf("\n");
        printf("Deseja continuar?\n1 - sim\n2 - não\n");
        
        if (scanf("%d", &again) != 1) {
            printf("Entrada inválida. Por favor, insira 1 ou 2.\n");
            while (getchar() != '\n');  // Limpa o buffer de entrada
            again = 2;  // Define o valor para sair do loop
        }

        while (again != 1 && again != 2) {
            printf("Entrada inválida. Por favor, insira 1 para continuar ou 2 para parar.\n");
            if (scanf("%d", &again) != 1) {
                printf("Entrada inválida. Por favor, insira 1 ou 2.\n");
                while (getchar() != '\n');  // Limpa o buffer de entrada
                again = 2;  // Define o valor para sair do loop
            }
        }
        
    } while (again == 1);  // Continua até que o usuário escolha parar
}

// Função principal que inicia a execução do programa
int main(void) {
    repetir();  // Chama a função repetir para iniciar o processo
    return 0;
}
