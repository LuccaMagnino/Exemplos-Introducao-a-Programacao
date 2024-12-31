#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Produtos {
    char nome[51];
    double preco;
};

int main() {
    int N;
    scanf("%d", &N);

    while (N > 0) {
        int i, j;

        int M;
        scanf("%d", &M);

        struct Produtos Parcinova[M];

        for (i = 0; i < M; i++) {
            scanf("%s %lf", Parcinova[i].nome, &Parcinova[i].preco);
        }

        int P;
        scanf("%d", &P);

        double t = 0.0;

        for (i = 0; i < P; i++) {
            char nome_p[51];
            int quantidade;
            scanf("%s %d", nome_p, &quantidade);

            for (j = 0; j < M; j++) {
                if (strcmp(nome_p, Parcinova[j].nome) == 0) {
                    t += quantidade * Parcinova[j].preco;
                    break;
                }
            }
        }
        printf("R$ %.2lf\n", t);

        N--;
    }

    return 0;
}
