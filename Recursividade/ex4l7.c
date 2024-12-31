#include <stdio.h>

// Função recursiva para somar de 1 a n
int soma(int n) 
{
    if (n == 0) 
    {
        return 0;
    }
    return n + soma(n - 1);
}

int main() 
{
    int t;
    scanf("%d", &t);
    
    while (t > 0) 
    {
        int n;
        scanf("%d", &n);

        // Chama a função para calcular a soma e imprime o resultado
        printf("%d\n", soma(n));

        t--;
    }

    return 0;
}
