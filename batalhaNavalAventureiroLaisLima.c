#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3

int main() {

    // Criação do tabuleiro 10x10
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];

    int linha, coluna;

    // Inicializa todo o tabuleiro com 0 (água)
    for (linha = 0; linha < TAMANHO_TABULEIRO; linha++) {
        for (coluna = 0; coluna < TAMANHO_TABULEIRO; coluna++) {
            tabuleiro[linha][coluna] = 0;
        }
    }

    // =========================================================
    // DEFINIÇÃO DAS COORDENADAS DOS NAVIOS
    // =========================================================

    // Navio horizontal
    int linhaHorizontal = 1;
    int colunaHorizontal = 2;

    // Navio vertical
    int linhaVertical = 4;
    int colunaVertical = 7;

    // Navio diagonal principal (\)
    int linhaDiagonal1 = 6;
    int colunaDiagonal1 = 1;

    // Navio diagonal secundária (/)
    int linhaDiagonal2 = 0;
    int colunaDiagonal2 = 9;

    int valido = 1;

    // =========================================================
    // VALIDAÇÃO E POSICIONAMENTO DO NAVIO HORIZONTAL
    // =========================================================

    // Verifica se o navio cabe no tabuleiro
    if (colunaHorizontal + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) {

        // Verifica sobreposição
        for (coluna = 0; coluna < TAMANHO_NAVIO; coluna++) {

            if (tabuleiro[linhaHorizontal][colunaHorizontal + coluna] != 0) {
                valido = 0;
            }
        }

        // Posiciona o navio
        if (valido) {

            for (coluna = 0; coluna < TAMANHO_NAVIO; coluna++) {
                tabuleiro[linhaHorizontal][colunaHorizontal + coluna] = 3;
            }

        }

    }

    // =========================================================
    // VALIDAÇÃO E POSICIONAMENTO DO NAVIO VERTICAL
    // =========================================================

    valido = 1;

    if (linhaVertical + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) {

        // Verifica sobreposição
        for (linha = 0; linha < TAMANHO_NAVIO; linha++) {

            if (tabuleiro[linhaVertical + linha][colunaVertical] != 0) {
                valido = 0;
            }
        }

        // Posiciona o navio
        if (valido) {

            for (linha = 0; linha < TAMANHO_NAVIO; linha++) {
                tabuleiro[linhaVertical + linha][colunaVertical] = 3;
            }

        }

    }

    // =========================================================
    // VALIDAÇÃO E POSICIONAMENTO DO NAVIO DIAGONAL PRINCIPAL
    // =========================================================

    valido = 1;

    if (linhaDiagonal1 + TAMANHO_NAVIO <= TAMANHO_TABULEIRO &&
        colunaDiagonal1 + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) {

        // Verifica sobreposição
        for (linha = 0; linha < TAMANHO_NAVIO; linha++) {

            if (tabuleiro[linhaDiagonal1 + linha][colunaDiagonal1 + linha] != 0) {
                valido = 0;
            }
        }

        // Posiciona o navio
        if (valido) {

            for (linha = 0; linha < TAMANHO_NAVIO; linha++) {
                tabuleiro[linhaDiagonal1 + linha][colunaDiagonal1 + linha] = 3;
            }

        }

    }

    // =========================================================
    // VALIDAÇÃO E POSICIONAMENTO DO NAVIO DIAGONAL SECUNDÁRIO
    // =========================================================

    valido = 1;

    if (linhaDiagonal2 + TAMANHO_NAVIO <= TAMANHO_TABULEIRO &&
        colunaDiagonal2 - (TAMANHO_NAVIO - 1) >= 0) {

        // Verifica sobreposição
        for (linha = 0; linha < TAMANHO_NAVIO; linha++) {

            if (tabuleiro[linhaDiagonal2 + linha][colunaDiagonal2 - linha] != 0) {
                valido = 0;
            }
        }

        // Posiciona o navio
        if (valido) {

            for (linha = 0; linha < TAMANHO_NAVIO; linha++) {
                tabuleiro[linhaDiagonal2 + linha][colunaDiagonal2 - linha] = 3;
            }

        }

    }

    // =========================================================
    // EXIBIÇÃO DO TABULEIRO
    // =========================================================

    printf("\nTABULEIRO BATALHA NAVAL\n\n");

    for (linha = 0; linha < TAMANHO_TABULEIRO; linha++) {

        for (coluna = 0; coluna < TAMANHO_TABULEIRO; coluna++) {

            printf("%d ", tabuleiro[linha][coluna]);

        }

        printf("\n");
    }

    return 0;
}