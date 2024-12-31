#include <stdio.h>

int main() {
    int n;

    do
    {
        
        scanf("%d", &n);
        if (n <= 1) 
        {
            printf("Fatoracao nao e possivel para o numero %d!\n", n);

        }

    } 
    
    while (n <= 1);

    printf("%d = ", n);

    int i = 2;
    for (i = 2; n > 1; i++) {
        while (n % i == 0) {
            printf("%d", i);
            n /= i;
            if (n > 1) {
                printf(" x ");
            }
        }
    }

    printf("\n");

    return 0;
}