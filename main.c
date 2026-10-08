#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

void adiciona_musica(Lista* li, Musica* m) {
    inserir_final(li, m);
}

void adiciona_musica_posicao(Lista* li, Musica* m, int pos) {
    inserir_por_posicao(li, m, pos);
}

void remove_musica(Lista* li, int pos, int* pos_atual) {
    remover_por_posicao(li, pos);
    if (pos < *pos_atual) {
        (*pos_atual)--;
    }
}

void tempo_restante(Lista* li, int pos_atual) {
    int total = 0;
    int qtd = quantidade_musicas(li);
    for (int i = pos_atual; i < qtd; i++) {
        Musica* m = consultar_por_posicao(li, i);
        if (m != NULL) {
            char *titulo, *artista;
            int duracao;
            consultar_musica(m, &titulo, &artista, &duracao);
            total += duracao;
        }
    }
    printf("Tempo total restante: %d segundos\n", total);
}

void play(Lista* li, int* pos_atual) {
    Musica* m = consultar_por_posicao(li, *pos_atual);
    if (m != NULL) {
        imprimir_musica(m);
        (*pos_atual)++;
    } else {
        printf("Fim da playlist.\n");
    }
}

void musicas_reproduzidas(int pos_atual) {
    printf("Musicas ja reproduzidas: %d\n", pos_atual);
}

int main() {
    Lista* playlist = criar_lista();
    int pos_atual = 0;

    Musica* m1 = criar_musica("Musica A", "Banda 1", 210);
    Musica* m2 = criar_musica("Musica B", "Banda 2", 180);
    Musica* m3 = criar_musica("Musica C", "Banda 3", 195);
    Musica* m4 = criar_musica("Musica D", "Banda 4", 240);
    Musica* m5 = criar_musica("Musica E", "Banda 5", 200);
    Musica* m6 = criar_musica("Musica F", "Banda 6", 150);
    Musica* m7 = criar_musica("Musica G", "Banda 7", 175);
    Musica* m8 = criar_musica("Musica H", "Banda 8", 225);
    Musica* m9 = criar_musica("Musica I", "Banda 9", 215);
    Musica* m10 = criar_musica("Musica J", "Banda 10", 190);

    adiciona_musica(playlist, m1);
    adiciona_musica(playlist, m2);
    adiciona_musica(playlist, m3);
    adiciona_musica(playlist, m4);
    adiciona_musica(playlist, m5);
    adiciona_musica(playlist, m6);
    adiciona_musica(playlist, m7);
    adiciona_musica(playlist, m8);
    adiciona_musica(playlist, m9);
    adiciona_musica_posicao(playlist, m10, 4);

    play(playlist, &pos_atual);
    play(playlist, &pos_atual);

    musicas_reproduzidas(pos_atual);

    tempo_restante(playlist, pos_atual);

    remove_musica(playlist, 5, &pos_atual);

    printf("Quantidade de musicas na playlist: %d\n", quantidade_musicas(playlist));
    printf("Posicao da proxima musica a ser reproduzida: %d\n", pos_atual);

    destruir_musica(m1);
    destruir_musica(m2);
    destruir_musica(m3);
    destruir_musica(m4);
    destruir_musica(m5);
    destruir_musica(m6);
    destruir_musica(m7);
    destruir_musica(m8);
    destruir_musica(m9);
    destruir_musica(m10);
    destruir_lista(playlist);

    return 0;
}