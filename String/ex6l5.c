#include <stdio.h>
#include <string.h>
int main()
{
    char p[200];

    while (scanf("%s",p) != EOF)
    {
        int tam, i, j;
        tam = strlen(p);
        int ok=1;

        for (i = 0; i < tam; i++)
        {
            if(p[i] != p[tam-1-i]){
                ok=0;
            }
        }
        if(ok == 1) printf("sim\n");
        else printf("nao\n");
    }
    return 0;
}