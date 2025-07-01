#include <stdio.h>
#include <stdlib.h>
#include "../include/pilha_vetor.h"

void constroi_pilha(t_pilha *p, int capacidade) {
    p->dados = (int *) malloc(sizeof(int) * capacidade);
    p->topo = 0;
    p->capacidade = capacidade;
}

int esta_vazia(const t_pilha *p) {
    return p->topo == 0;
}

int esta_cheia(const t_pilha *p) {
    return p->topo == p->capacidade;
}

int tamanho(const t_pilha *p) {
    return p->topo;
}

void empilha(t_pilha *p, int valor) {
    if (!esta_cheia(p)) {
        p->dados[p->topo++] = valor;
    }
}

int desempilha(t_pilha *p) {
    if (!esta_vazia(p)) {
        return p->dados[--p->topo];
    }
    return -1; 
}

void mostra_pilha(const t_pilha *p) {
    if (esta_vazia(p)) {
        printf("Pilha vazia\n");
    } else {
        for (int i = p->topo - 1; i >= 0; i--) {
            printf("%d\n", p->dados[i]);
        }
    }
}
