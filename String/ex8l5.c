#include <stdio.h>
#include <string.h>

int main() 
{
    int N, i;
    scanf("%d\n", &N);  

    for (i = 0; i < N; i++)
    {
        char c;
        char str[500];
        int indice = -1;  // Inicializa o índice como -1 para o caso de não encontrar o caractere

        // Lê o caractere e a string
        scanf("%c %[^\n]%*c", &c, str);

        int j;
        for (j = 0; j < strlen(str); j++) 
        {
            if (str[j] == c)
            {
                indice = j;
                break;
            }
        }

        if (indice != -1) 
        {
            printf("Caractere %c encontrado no indice %d da string.\n", c, indice);
        } 
        else
        {
            printf("Caractere %c nao encontrado.\n", c);
        }
    }

    return 0;
}
