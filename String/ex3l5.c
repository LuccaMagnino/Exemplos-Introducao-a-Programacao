#include<stdio.h>
#include <string.h>
int main()
{
    int N, tam, i;
    char str[10000];
    scanf("%d ", &N);
        while (N > 0)
        {
            int let = 0, vog = 0, con = 0;
            scanf(" %[^\n]", str);
 
            tam = strlen(str);
            for (i = 0; i < tam; i++)
            {
 
                if(str[i]>='a' && str[i] <= 'z'
                || str[i]>='A' && str[i] <= 'Z')
                {
                    if(str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u'
                    || str[i] == 'A' || str[i] == 'E' || str[i] == 'I'|| str[i] == 'O' || str[i] == 'U')
                    {
                        vog++;
                    }
 
                    else
                    {
                        con++;
                    }
                    let++;
                }
 
 
            }
        printf("Letras = %d\n", let);
        printf("Vogais = %d\n", vog);
        printf("Consoantes = %d\n", con);
 
        N--;
        }
 
    return 0;
}
