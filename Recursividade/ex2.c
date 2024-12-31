#include <stdio.h>
#include <string.h>
 
int soma = 0;
 
int achar_hi(char str[5000], int index, int tam)
{
 
    if (index == tam - 2)
    {
        if (str[index] == 'h' && str[index + 1] == 'i')
        {
            soma++;
        }
    return 0;
    }
 
    if (str[index] == 'h' && str[index + 1] == 'i')
    {
        soma++;
    }
 
    return achar_hi(str, index + 1, tam);
}
 
 
int main()
{
    int i, tam;
    scanf("%d", &i);
    while(i>0)
    {
        char str [5000];
        soma = 0;
        scanf(" %[^\n]", str);
 
            tam = strlen(str);
            achar_hi(str, 0, tam);
 
        printf("%d\n", soma);
    i--;
    }
    return 0;
}
