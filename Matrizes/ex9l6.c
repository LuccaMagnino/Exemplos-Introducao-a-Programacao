#include <stdio.h>

int main() {
    int m, n, i, j;
    scanf("%d %d", &m, &n);

    int matriz[m][n];
    int num_branco = 1;  


    for (i = 0; i < m; i++) 
    {
        for (j = 0; j < n; j++) 
        {
            if ((i + j) % 2 == 0) 
            {
                matriz[i][j] = 0;  
            } 
            else 
            {
                matriz[i][j] = num_branco;
                num_branco++;
            }
        }
    }

    for (i = 0; i < m; i++) 
    {
        for (j = 0; j < n; j++) 
        {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    return 0;
}
