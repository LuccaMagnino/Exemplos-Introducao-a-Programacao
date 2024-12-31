#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Fracao 
{
    int numerador;
    int denominador;
};


int mdc(int a, int b) 
{
    while (b != 0) 
    {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

void simplificarFracao(struct Fracao *f) 
{
    int divisor = mdc(f->numerador, f->denominador);
    f->numerador /= divisor;
    f->denominador /= divisor;
}

int main() {
    int casos;
    scanf("%d", &casos);
    getchar();
    int t, j, k;

    for (t = 1; t <= casos; t++) 
    {
        char str[1001];
        fgets(str, 1001, stdin);

        int numFra = 0;
        char *token = strtok(str, " ");
        while (token != NULL) 
        {
            numFra++;
            token = strtok(NULL, " ");
        }

        struct Fracao *fra = (struct Fracao *)malloc(numFra * sizeof(struct Fracao));

        token = strtok(str, " ");
        int idx = 0;
        while (token != NULL) 
        {
            sscanf(token, "%d/%d", &fra[idx].numerador, &fra[idx].denominador);
            simplificarFracao(&fra[idx]);
            idx++;
            token = strtok(NULL, " ");
        }


        int encontrouEquivalentes = 0;
        for (j = 0; j < numFra - 1; j++) 
        {
            for (k = j + 1; k < numFra; k++) 
            {
                if (fra[j].numerador * fra[k].denominador == fra[j].denominador * fra[k].numerador) 
                {
                    printf("Caso de teste %d\n", t);
                    printf("%d/%d equivalente a %d/%d\n", fra[j].numerador, fra[j].denominador, fra[k].numerador, fra[k].denominador);
                    encontrouEquivalentes = 1;
                }
            }
        }

        if (!encontrouEquivalentes) 
        {
            printf("Caso de teste %d\n", t);
            printf("Nao ha fracoes equivalentes na sequencia\n");
        }
        free(fra);
    }

    return 0;
}
