#include <stdio.h>

int main() {
    int m, n, i, j;

    
    do {
        scanf("%d", &m);
        scanf("%d", &n);
    } while (m < 1 || m > 10 || n < 1 || n > 10);

    int A[10][10];


    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &A[i][j]);
        }
    }


    for (i = 0; i < m; i++) {
        printf("linha %d: ", i + 1);

        for (j = 0; j < n; j++) {
            printf("%d", A[i][j]);
            if (j < n - 1) {
                printf(",");
            }
        }
        printf("\n");
    }

    return 0;
}
