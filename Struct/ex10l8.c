#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Fracao
{
    int numerador;
    int denominador;
};

int main()
{
    int n, i, j, idx = 0;
    char *teste;
    int *array[2];
    scanf("%d", &n);
    
    for (i = 0; i < n; i++)
    {
        struct Fracao piroca[1001];
        char str [1001];
        *str = (char *) malloc (1001 * sizeof (char));
        getchar();
        fgets(str, 1001, stdin);
        
        teste = strtok(str, " ");
        while (teste != NULL) 
        {
            sscanf(teste, "%d/%d", &piroca[idx].numerador, &piroca[idx].denominador);
            simplificarFracao(&piroca[idx]);
            idx++;
            teste = strtok(NULL, " ");
        }

        printf("Caso de teste %d", i + 1);
    }



    return 0;
}