# Playlist de Musicas - Atividade 1GQ

Este projeto contem a implementacao de uma playlist de musicas utilizando listas unicamente encadeadas na linguagem C, estruturado com Tipos Abstratos de Dados (TAD).

## Pre-requisitos

Para compilar e executar o codigo, e necessario ter um compilador da linguagem C instalado no seu computador. O mais comum e o GCC (GNU Compiler Collection). 

## Como compilar

1. Abra o seu terminal ou prompt de comando.
2. Navegue ate a pasta onde os arquivos do repositorio foram salvos.
3. Digite o seguinte comando e pressione Enter:

gcc main.c musica.c lista.c -o playlist

Este comando diz ao compilador para ler os arquivos fonte (main.c, musica.c e lista.c) e gerar um arquivo executavel chamado "playlist" (ou "playlist.exe" no Windows).

## Como executar

Apos a compilacao terminar sem erros, o executavel estara disponivel na mesma pasta. Para roda-lo, utilize o comando adequado para o seu sistema operacional:

Se voce estiver usando Linux ou macOS, digite:
./playlist

Se voce estiver usando Windows, digite:
playlist.exe

O programa iniciara e exibira no terminal o teste da playlist, incluindo as musicas reproduzidas, o tempo restante calculado e a contagem final de musicas.