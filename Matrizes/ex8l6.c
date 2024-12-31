#include <stdio.h>

int main() {
    int largura, altura, largura_borda, valor_borda;
    int matriz[100][100];
    int i, j;

    scanf("%d %d %d %d", &largura, &altura, &largura_borda, &valor_borda);

    if (largura > 100) largura = 100;
    if (altura > 100) altura = 100;

    for (i = 0; i < altura; i++) {
        for (j = 0; j < largura; j++) {
            matriz[i][j] = 0;
        }
    }

    for (i = 0; i < altura; i++) {
        for (j = 0; j < largura; j++) {
            if (i < largura_borda || i >= altura - largura_borda ||
                j < largura_borda || j >= largura - largura_borda) {
                matriz[i][j] = valor_borda;
            }
        }
    }

    printf("P2\n");
    printf("%d %d\n", largura, altura);
    printf("255\n");

    for (i = 0; i < altura; i++) {
        for (j = 0; j < largura; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    return 0;
}
