#include <stdio.h>

int main()
{
int n;
scanf("%d", &n);
int i, j, V[n], aux;
    for(i=0; i<n; i++){
        scanf("%d", &V[i]);
    }
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(V[i]>V[j])
            {
                aux = V[i];
                V[i]=V[j];
                V[j] = aux;
            }
        }
    }
    for(i=0;i<n;i++)
    {
        printf("%d\n", V[i]);
    }
    return 0;
}