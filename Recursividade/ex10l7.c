#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void pref (char *str)
{
    int tam = strlen(str);

    if (tam - 1 > 0)
    {
        str[tam - 1] = '\0';
        printf("%s\n", str);
        pref(str);
    }
}
int main()
{
    int C;
    scanf("%d ", &C);
    int i;
    
    for (i = 0; i < C; i++)
    {
        printf("Caso de teste %d\n", i + 1);   
        char str[1001];
        fgets(str, 1001, stdin);

        pref(str);
    }
    return 0;
}