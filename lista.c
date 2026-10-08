#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

struct no {
    Musica* musica;
    struct no* prox;
};
typedef struct no No;

struct lista {
    No* inicio;
    int qtd;
};

Lista* criar_lista() {
    Lista* li = (Lista*) malloc(sizeof(struct lista));
    if (li != NULL) {
        li->inicio = NULL;
        li->qtd = 0;
    }
    return li;
}

int inserir_inicio(Lista* li, Musica* m) {
    if (li == NULL) return 0;
    No* no = (No*) malloc(sizeof(No));
    if (no == NULL) return 0;
    no->musica = m;
    no->prox = li->inicio;
    li->inicio = no;
    li->qtd++;
    return 1;
}

int inserir_final(Lista* li, Musica* m) {
    if (li == NULL) return 0;
    No* no = (No*) malloc(sizeof(No));
    if (no == NULL) return 0;
    no->musica = m;
    no->prox = NULL;
    if (li->inicio == NULL) {
        li->inicio = no;
    } else {
        No* aux = li->inicio;
        while (aux->prox != NULL) {
            aux = aux->prox;
        }
        aux->prox = no;
    }
    li->qtd++;
    return 1;
}

int inserir_por_posicao(Lista* li, Musica* m, int pos) {
    if (li == NULL || pos < 0 || pos > li->qtd) return 0;
    if (pos == 0) return inserir_inicio(li, m);
    if (pos == li->qtd) return inserir_final(li, m);

    No* no = (No*) malloc(sizeof(No));
    if (no == NULL) return 0;
    no->musica = m;
    No* aux = li->inicio;
    for (int i = 0; i < pos - 1; i++) {
        aux = aux->prox;
    }
    no->prox = aux->prox;
    aux->prox = no;
    li->qtd++;
    return 1;
}

int remover_primeira(Lista* li) {
    if (li == NULL || li->inicio == NULL) return 0;
    No* aux = li->inicio;
    li->inicio = aux->prox;
    free(aux);
    li->qtd--;
    return 1;
}

int remover_ultima(Lista* li) {
    if (li == NULL || li->inicio == NULL) return 0;
    if (li->inicio->prox == NULL) {
        free(li->inicio);
        li->inicio = NULL;
    } else {
        No* ant = li->inicio;
        No* aux = ant->prox;
        while (aux->prox != NULL) {
            ant = aux;
            aux = aux->prox;
        }
        ant->prox = NULL;
        free(aux);
    }
    li->qtd--;
    return 1;
}

int remover_por_posicao(Lista* li, int pos) {
    if (li == NULL || li->inicio == NULL || pos < 0 || pos >= li->qtd) return 0;
    if (pos == 0) return remover_primeira(li);

    No* ant = li->inicio;
    No* aux = ant->prox;
    for (int i = 1; i < pos; i++) {
        ant = aux;
        aux = aux->prox;
    }
    ant->prox = aux->prox;
    free(aux);
    li->qtd--;
    return 1;
}

Musica* consultar_primeira(Lista* li) {
    if (li == NULL || li->inicio == NULL) return NULL;
    return li->inicio->musica;
}

Musica* consultar_por_posicao(Lista* li, int pos) {
    if (li == NULL || li->inicio == NULL || pos < 0 || pos >= li->qtd) return NULL;
    No* aux = li->inicio;
    for (int i = 0; i < pos; i++) {
        aux = aux->prox;
    }
    return aux->musica;
}

int quantidade_musicas(Lista* li) {
    if (li == NULL) return 0;
    return li->qtd;
}

void destruir_lista(Lista* li) {
    if (li != NULL) {
        No* aux = li->inicio;
        while (aux != NULL) {
            No* temp = aux;
            aux = aux->prox;
            free(temp);
        }
        free(li);
    }
}