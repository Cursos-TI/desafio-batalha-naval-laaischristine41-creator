#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_HABILIDADE 5
#define TAMANHO_NAVIO 3

int main() {

    // =====================================================
    // CRIAÇÃO DO TABULEIRO
    // =====================================================

    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];

    int linha, coluna;

    // Inicializa o tabuleiro com água (0)
    for (linha = 0; linha < TAMANHO_TABULEIRO; linha++) {

        for (coluna = 0; coluna < TAMANHO_TABULEIRO; coluna++) {

            tabuleiro[linha][coluna] = 0;

        }
    }

    // =====================================================
    // POSICIONAMENTO DOS NAVIOS
    // =====================================================

    // Navio horizontal
    for (coluna = 1; coluna <= 3; coluna++) {

        tabuleiro[2][coluna] = 3;

    }

    // Navio vertical
    for (linha = 5; linha <= 7; linha++) {

        tabuleiro[linha][7] = 3;

    }

    // Navio diagonal principal
    for (linha = 0; linha < TAMANHO_NAVIO; linha++) {

        tabuleiro[linha + 6][linha + 1] = 3;

    }

    // Navio diagonal secundária
    for (linha = 0; linha < TAMANHO_NAVIO; linha++) {

        tabuleiro[linha + 1][8 - linha] = 3;

    }

    // =====================================================
    // CRIAÇÃO DAS MATRIZES DE HABILIDADE
    // =====================================================

    int cone[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];
    int cruz[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];
    int octaedro[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];

    // Inicializa todas as matrizes com 0
    for (linha = 0; linha < TAMANHO_HABILIDADE; linha++) {

        for (coluna = 0; coluna < TAMANHO_HABILIDADE; coluna++) {

            cone[linha][coluna] = 0;
            cruz[linha][coluna] = 0;
            octaedro[linha][coluna] = 0;

        }
    }

    // =====================================================
    // HABILIDADE CONE
    // =====================================================

    /*
        Forma esperada:

        0 0 1 0 0
        0 1 1 1 0
        1 1 1 1 1
        0 0 0 0 0
        0 0 0 0 0
    */

    for (linha = 0; linha < 3; linha++) {

        for (coluna = 0; coluna < TAMANHO_HABILIDADE; coluna++) {

            if (coluna >= 2 - linha && coluna <= 2 + linha) {

                cone[linha][coluna] = 1;

            }

        }
    }

    // =====================================================
    // HABILIDADE CRUZ
    // =====================================================

    /*
        Forma esperada:

        0 0 1 0 0
        0 0 1 0 0
        1 1 1 1 1
        0 0 1 0 0
        0 0 1 0 0
    */

    for (linha = 0; linha < TAMANHO_HABILIDADE; linha++) {

        for (coluna = 0; coluna < TAMANHO_HABILIDADE; coluna++) {

            if (linha == 2 || coluna == 2) {

                cruz[linha][coluna] = 1;

            }

        }
    }

    // =====================================================
    // HABILIDADE OCTAEDRO (LOSANGO)
    // =====================================================

    /*
        Forma esperada:

        0 0 1 0 0
        0 1 1 1 0
        1 1 1 1 1
        0 1 1 1 0
        0 0 1 0 0
    */

    for (linha = 0; linha < TAMANHO_HABILIDADE; linha++) {

        for (coluna = 0; coluna < TAMANHO_HABILIDADE; coluna++) {

            // Distância do centro
            int distanciaLinha = linha - 2;
            if (distanciaLinha < 0) {
                distanciaLinha = -distanciaLinha;
            }

            int distanciaColuna = coluna - 2;
            if (distanciaColuna < 0) {
                distanciaColuna = -distanciaColuna;
            }

            // Forma de losango
            if (distanciaLinha + distanciaColuna <= 2) {

                octaedro[linha][coluna] = 1;

            }

        }
    }

    // =====================================================
    // POSIÇÃO DAS HABILIDADES NO TABULEIRO
    // =====================================================

    int origemConeLinha = 0;
    int origemConeColuna = 0;

    int origemCruzLinha = 4;
    int origemCruzColuna = 4;

    int origemOctaedroLinha = 5;
    int origemOctaedroColuna = 1;

    // =====================================================
    // SOBREPOSIÇÃO DO CONE NO TABULEIRO
    // =====================================================

    for (linha = 0; linha < TAMANHO_HABILIDADE; linha++) {

        for (coluna = 0; coluna < TAMANHO_HABILIDADE; coluna++) {

            int linhaTabuleiro = origemConeLinha + linha;
            int colunaTabuleiro = origemConeColuna + coluna;

            // Verifica limites do tabuleiro
            if (linhaTabuleiro < TAMANHO_TABULEIRO &&
                colunaTabuleiro < TAMANHO_TABULEIRO) {

                // Aplica habilidade
                if (cone[linha][coluna] == 1 &&
                    tabuleiro[linhaTabuleiro][colunaTabuleiro] == 0) {

                    tabuleiro[linhaTabuleiro][colunaTabuleiro] = 5;

                }

            }

        }
    }

    // =====================================================
    // SOBREPOSIÇÃO DA CRUZ NO TABULEIRO
    // =====================================================

    for (linha = 0; linha < TAMANHO_HABILIDADE; linha++) {

        for (coluna = 0; coluna < TAMANHO_HABILIDADE; coluna++) {

            int linhaTabuleiro = origemCruzLinha + linha - 2;
            int colunaTabuleiro = origemCruzColuna + coluna - 2;

            if (linhaTabuleiro >= 0 &&
                linhaTabuleiro < TAMANHO_TABULEIRO &&
                colunaTabuleiro >= 0 &&
                colunaTabuleiro < TAMANHO_TABULEIRO) {

                if (cruz[linha][coluna] == 1 &&
                    tabuleiro[linhaTabuleiro][colunaTabuleiro] == 0) {

                    tabuleiro[linhaTabuleiro][colunaTabuleiro] = 5;

                }

            }

        }
    }

    // =====================================================
    // SOBREPOSIÇÃO DO OCTAEDRO NO TABULEIRO
    // =====================================================

    for (linha = 0; linha < TAMANHO_HABILIDADE; linha++) {

        for (coluna = 0; coluna < TAMANHO_HABILIDADE; coluna++) {

            int linhaTabuleiro = origemOctaedroLinha + linha - 2;
            int colunaTabuleiro = origemOctaedroColuna + coluna - 2;

            if (linhaTabuleiro >= 0 &&
                linhaTabuleiro < TAMANHO_TABULEIRO &&
                colunaTabuleiro >= 0 &&
                colunaTabuleiro < TAMANHO_TABULEIRO) {

                if (octaedro[linha][coluna] == 1 &&
                    tabuleiro[linhaTabuleiro][colunaTabuleiro] == 0) {

                    tabuleiro[linhaTabuleiro][colunaTabuleiro] = 5;

                }

            }

        }
    }

    // =====================================================
    // EXIBIÇÃO DO TABULEIRO
    // =====================================================

    printf("\n=== TABULEIRO BATALHA NAVAL ===\n\n");

    for (linha = 0; linha < TAMANHO_TABULEIRO; linha++) {

        for (coluna = 0; coluna < TAMANHO_TABULEIRO; coluna++) {

            // Água
            if (tabuleiro[linha][coluna] == 0) {

                printf("0 ");

            }

            // Navio
            else if (tabuleiro[linha][coluna] == 3) {

                printf("3 ");

            }

            // Área afetada pela habilidade
            else if (tabuleiro[linha][coluna] == 5) {

                printf("5 ");

            }

        }

        printf("\n");

    }

    return 0;
}