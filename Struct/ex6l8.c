#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Nome
{
    char *str;
};

int main()
{
    int n, i;
    scanf("%d", &n);
    getchar();

    struct Nome *nomes;
    nomes = (struct Nome *) malloc (n * sizeof(struct Nome));

    char buffer [10000];

        for (i = 0; i < n; i++) 
        {
            fgets(buffer, 10000, stdin);

            nomes[i].str = (char *)malloc((strlen(buffer) + 1) * sizeof(char));

            strcpy (nomes[i].str, buffer);
        }

    for(i = 0; i < n; i++)
    {
        printf("%s\n", nomes[i].str);
    }

    free(nomes);

    return 0;
}