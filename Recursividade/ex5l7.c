#include <stdio.h>
#include <stdlib.h>

int soma(int V[], int n, int index) 
{
    if (index == n) 
    {
        return 0;
    }

    return V[index] + soma(V, n, index + 1);
}

int main() 
{
    int c;
    scanf("%d", &c);
    
    while (c > 0) 
    {
        int n, i;
        scanf("%d", &n);

        int *V = (int *)malloc(n * sizeof(int));

        for (i = 0; i < n; i++) 
        {
            scanf("%d", &V[i]);
        }

        printf("%d\n", soma(V, n, 0));

        free(V);
        c--;
    }
    return 0;
}