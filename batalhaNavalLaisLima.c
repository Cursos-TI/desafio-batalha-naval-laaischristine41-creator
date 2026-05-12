#include <stdio.h>

int main() {

    // MATRIZ 10x10
    int tabuleiro[10][10];

    // TAMANHO DOS NAVIOS
    int tamanhoNavio = 3;

    // COORDENADAS INICIAIS
    int linhaHorizontal = 2;
    int colunaHorizontal = 4;

    int linhaVertical = 5;
    int colunaVertical = 7;

    // =========================
    // PREENCHER TABULEIRO COM 0
    // =========================

    for(int linha = 0; linha < 10; linha++) {

        for(int coluna = 0; coluna < 10; coluna++) {

            tabuleiro[linha][coluna] = 0;

        }
    }

    // =========================
    // VALIDAR NAVIO HORIZONTAL
    // =========================

    if(colunaHorizontal + tamanhoNavio <= 10) {

        for(int i = 0; i < tamanhoNavio; i++) {

            tabuleiro[linhaHorizontal][colunaHorizontal + i] = 3;

        }

    }

    // =======================
    // VALIDAR NAVIO VERTICAL
    // =======================

    if(linhaVertical + tamanhoNavio <= 10) {

        for(int i = 0; i < tamanhoNavio; i++) {

            // VERIFICA SOBREPOSIÇÃO
            if(tabuleiro[linhaVertical + i][colunaVertical] == 0) {

                tabuleiro[linhaVertical + i][colunaVertical] = 3;

            }

        }

    }

    // =======================
    // EXIBIR TABULEIRO
    // =======================

    for(int linha = 0; linha < 10; linha++) {

        for(int coluna = 0; coluna < 10; coluna++) {

            printf("%d ", tabuleiro[linha][coluna]);

        }

        printf("\n");

    }

    return 0;
}