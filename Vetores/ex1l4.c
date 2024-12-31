#include <stdio.h>
int main()
{
    int N, j = 0;
    scanf("%d", &N);
    int V[N];

    for (j = 0; j < N; j++)
    {
        scanf("%d", &V[j]);
    }

    int M, X, i;
    scanf("%d", &X);
    while (X > 0)
    {
        scanf("%d", &M);
        int ver = 0;

        for (i = 0; i<N; i++){

            if (M == V[i])
            {
                ver = 1;
            }
        }



        if (ver == 1)
        {
            printf("ACHEI\n");
        }
        else
        {
            printf("NAO ACHEI\n");
        }
        X--;
    }
    return 0;
}