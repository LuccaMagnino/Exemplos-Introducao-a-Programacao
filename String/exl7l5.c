#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *prefixo(int n, char *s)
{
    int tam = strlen(s);
    if (n > tam)
    {
        n = tam;
    }

    char* prefixo = (char*)malloc((n+1)*sizeof(char));
    if (prefixo == NULL)
    {
        return NULL;
    }

    strncpy(prefixo, s, n);
    prefixo[n] = '\0';

    return prefixo;
}

int main()
{
    int c;
    scanf("%d", &c);
    while (c > 0)
    {
        int n;
        char s[500];

        scanf("%d", &n);
        fgets

        c--;
    }

    return 0;
}

