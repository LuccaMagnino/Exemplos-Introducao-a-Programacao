#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *entrada, *saida;
    int numero, soma = 0, cont = 0;
    double media = 0.0;

    entrada = fopen("entrada.txt", "r");
    if (entrada == NULL) {
        printf("Erro ao abrir o arquivo de entrada.\n");
        return 1;
    }

    while (fscanf(entrada, "%d", &numero) != EOF) {
        soma += numero;
        cont++;
    }
    fclose(entrada);

    if (cont != 0) {
        media = (double)soma / cont;
    }

    saida = fopen("saida.txt", "w");
    if (saida == NULL) {
        printf("Erro ao abrir o arquivo de saída.\n");
        return 1;
    }

    fprintf(saida, "Soma dos numeros: %d\n", soma);
    fprintf(saida, "Media: %.2lf\n", media);
    fclose(saida);

    return 0;
}
