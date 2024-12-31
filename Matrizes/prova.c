#include <stdio.h>
#include <stdlib.h>

//Funcao de numero primo
int primo(int n)
{
    if(n == 1 || n == 2) return 1;
    int i;

    // N n eh primo -> return 1
    // N eh primo -> return 0

    for(i = 3; i * i <= n; i++)
    {
        // N n eh primo
        if(n % i == 0)
        {
            return 1;
        }
    }

    return 0;
}
 
 
int main()
{
    int N, i, j, aux = 0, pos;
    scanf("%d", &N);

    // int mat[510][510]

    int ** matriz;
    
    matriz=(int **) malloc(N*sizeof(int *));
    // ** mat [ptr1, pt2, ptr3, .. ptrn]
    /*
        ptr1 = malloc();
        ptr2 = malloc();
        ...
    */
    for(i=0; i<N; i++) matriz[i]= (int *) malloc(N*sizeof(int));

    //Leitura da matriz
    for (i = 0; i<N; i++)
    {
        for(j=0; j<N; j++)
        {
           scanf("%d", &matriz[i][j]);
        }
    
    }
    //Leitrua da diagonal principal
    for (i = 0; i < N; i++)
    {
        if(primo(matriz[i][i]) == 0)
        {
            aux = matriz[i][i];
            pos=i;
            break;
        }
        else
        {
            aux = matriz[N-1][N-1];
        }
    }
    //Com o numero primo ou o ultimo valor da diagonal principal
    //Basta multiplica-lo pelas linhas impares (1,3...)
    if(primo(aux) == 0){
        if(pos%2 == 0) i=1;
        else i=0;
        for (; i<N; i+= 2)
        {
            for(j = 0; j<N; j++)
            {
            matriz[j][i] = matriz[j][i] * aux;
            }
    
        }
    }else{
        for (i = 1; i<N; i+= 2)
        {
            for(j = 0; j<N; j++)
            {
            matriz[i][j] = matriz[i][j] * aux;
            }
    
        }
    }
 
    //Imprimir
    for (i=0; i<N; i++)
    {
        for(j=0; j<N; j++)
            printf("%d ", matriz[i][j]);
        printf("\n");
    }
    
    for(int i=0; i<N; i++) free(matriz[i]);
    free(matriz);


return 0;
}