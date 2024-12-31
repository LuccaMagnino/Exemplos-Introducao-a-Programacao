#include <stdio.h>

int main() {
    int m, n, i, j;


    scanf("%d %d", &m, &n);

    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) 
        {

            if ((i + j) % 2 == 0) 
            {
                printf("1");
            } 
            else 
            {
                printf("0");
            }
        }
        printf("\n");
    }

    return 0;
}
