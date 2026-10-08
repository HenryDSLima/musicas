#ifndef LISTA_H
#define LISTA_H

#include "musica.h"

typedef struct lista Lista;

Lista* criar_lista();
int inserir_inicio(Lista* li, Musica* m);
int inserir_final(Lista* li, Musica* m);
int inserir_por_posicao(Lista* li, Musica* m, int pos);
int remover_primeira(Lista* li);
int remover_ultima(Lista* li);
int remover_por_posicao(Lista* li, int pos);
Musica* consultar_primeira(Lista* li);
Musica* consultar_por_posicao(Lista* li, int pos);
int quantidade_musicas(Lista* li);
void destruir_lista(Lista* li);

#endif