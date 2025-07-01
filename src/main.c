#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../include/pilha_vetor.h"

int gerar_numero_aleatorio() {
    return 1 + rand() % 100;
}

int main() {
    t_pilha pilha;
    int capacidade;

    srand(time(NULL)); 

    printf("Digite o tamanho da pilha: ");
    scanf("%d", &capacidade);

    constroi_pilha(&pilha, capacidade);

    printf("\nEmpilhando numeros aleatorios: ");
    for (int i = 0; i < capacidade; i++) {
        int valor = gerar_numero_aleatorio();
        empilha(&pilha, valor);
        printf("%d ", valor);
    }

    printf("\n\nEstado atual da pilha:\n");
    mostra_pilha(&pilha);

    printf("\nVerificando estado da pilha:\n");
    printf("A pilha esta vazia? %s\n", esta_vazia(&pilha) ? "Sim" : "Nao");
    printf("A pilha esta cheia? %s\n", esta_cheia(&pilha) ? "Sim" : "Nao");
    printf("Tamanho atual: %d\n", tamanho(&pilha));

    printf("\nDesempilhando 1 elemento:\n");
    desempilha(&pilha);
    mostra_pilha(&pilha);

    printf("\nVerificando novamente:\n");
    printf("A pilha esta vazia? %s\n", esta_vazia(&pilha) ? "Sim" : "Nao");
    printf("A pilha esta cheia? %s\n", esta_cheia(&pilha) ? "Sim" : "Nao");
    printf("Tamanho atual: %d\n", tamanho(&pilha));

    free(pilha.dados);
    return 0;
}
