#include <stdio.h>
 
int ans = 0;
 
void conta_x (char str [5000], int index, int tam)
{
    if (index == tam - 1)
    {
        if (str[index] == 'x')
        {
            ans++;
        }
        return;
    }
 
    if (str[index] == 'x')
    {
        ans++;
    }
 
    return conta_x(str, index + 1, tam);
}
 
int main()
{
    int i;
    scanf ("%d", &i);
    while(i>0)
    {
        ans = 0;
        char str [5000];
        int j, tam;
        //loop em string nao precisa!!!!
            //for (j = 0; j < tam; j++)
            //{ 
            //}
                getchar();
                fgets(str, 5000, stdin);
 
        tam = strlen(str);
        conta_x(str, 0, tam);
        printf("%d\n", ans);
 
        i--;
    }
 
return 0;
}