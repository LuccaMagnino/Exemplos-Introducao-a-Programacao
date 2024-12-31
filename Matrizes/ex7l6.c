#include <stdio.h>

int main() {
    int matriz[6][6];
    int maior_soma = -9999;
    int i, j; 

    for (i = 0; i < 6; i++) {
        for (j = 0; j < 6; j++) {
            scanf("%d", &matriz[i][j]);
        }
    }


    for (i = 0; i <= 3; i++) {
        for (j = 0; j <= 3; j++) {

            if (i + 2 < 6 && j + 2 < 6) {
                int soma_ampulheta = matriz[i][j] + matriz[i][j+1] + matriz[i][j+2]
                                    + matriz[i+1][j+1]
                                    + matriz[i+2][j] + matriz[i+2][j+1] + matriz[i+2][j+2];

                if (soma_ampulheta > maior_soma) {
                    maior_soma = soma_ampulheta;
                }
            }
        }
    }


    printf("%d\n", maior_soma);

    return 0;
}
