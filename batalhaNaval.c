#include <stdio.h>

#define TAMANHO 10

// Função para inicializar o tabuleiro
void inicializarTabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            tabuleiro[i][j] = 0;
        }
    }
}

// Função para exibir o tabuleiro
void exibirTabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

// Função para posicionar navios
void posicionarNavios(int tabuleiro[TAMANHO][TAMANHO]) {
    // Navio horizontal de tamanho 3
    for (int i = 0; i < 3; i++) {
        tabuleiro[2][i] = 3;
    }
    
    // Navio vertical de tamanho 3
    for (int i = 0; i < 3; i++) {
        tabuleiro[i][5] = 3;
    }
    
    // Navio diagonal superior-esquerdo para inferior-direito
    for (int i = 0; i < 3; i++) {
        tabuleiro[i][i] = 3;
    }
    
    // Navio diagonal superior-direito para inferior-esquerdo
    for (int i = 0; i < 3; i++) {
        tabuleiro[i][TAMANHO - 1 - i] = 3;
    }
}

// Função para aplicar habilidade "Cone"
void habilidadeCone(int tabuleiro[TAMANHO][TAMANHO], int x, int y) {
    if (x >= 1 && y >= 1 && y < TAMANHO - 1) {
        tabuleiro[x - 1][y] = 1;
        tabuleiro[x][y - 1] = 1;
        tabuleiro[x][y] = 1;
        tabuleiro[x][y + 1] = 1;
    }
    if (x >= 2) {
        tabuleiro[x - 2][y] = 1;
    }
}

// Função para aplicar habilidade "Cruz"
void habilidadeCruz(int tabuleiro[TAMANHO][TAMANHO], int x, int y) {
    if (x > 0) tabuleiro[x - 1][y] = 1;
    if (x < TAMANHO - 1) tabuleiro[x + 1][y] = 1;
    if (y > 0) tabuleiro[x][y - 1] = 1;
    if (y < TAMANHO - 1) tabuleiro[x][y + 1] = 1;
    tabuleiro[x][y] = 1;
}

// Função para aplicar habilidade "Octaedro"
void habilidadeOctaedro(int tabuleiro[TAMANHO][TAMANHO], int x, int y) {
    if (x > 0) tabuleiro[x - 1][y] = 1;
    if (x < TAMANHO - 1) tabuleiro[x + 1][y] = 1;
    if (y > 0) tabuleiro[x][y - 1] = 1;
    if (y < TAMANHO - 1) tabuleiro[x][y + 1] = 1;
    tabuleiro[x][y] = 1;
    
    if (x > 1) tabuleiro[x - 2][y] = 1;
    if (x < TAMANHO - 2) tabuleiro[x + 2][y] = 1;
    if (y > 1) tabuleiro[x][y - 2] = 1;
    if (y < TAMANHO - 2) tabuleiro[x][y + 2] = 1;
}

int main() {
    int tabuleiro[TAMANHO][TAMANHO];
    inicializarTabuleiro(tabuleiro);
    posicionarNavios(tabuleiro);

    printf("Tabuleiro Inicial:\n");
    exibirTabuleiro(tabuleiro);

    // Aplicando habilidades em posições específicas
    habilidadeCone(tabuleiro, 5, 5);
    habilidadeCruz(tabuleiro, 2, 2);
    habilidadeOctaedro(tabuleiro, 7, 7);

    printf("\nTabuleiro Após Habilidades:\n");
    exibirTabuleiro(tabuleiro);
    
    return 0;
}
