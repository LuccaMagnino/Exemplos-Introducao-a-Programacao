#include<stdio.h>
int main()
{
    int n; //valor n, inteiro e positivo!
    scanf("%d", &n);
 
        if(n<=0)
 
 
        {
            printf("Numero invalido!");
        }
 
        else
        {
            double l = 1, i = 1, s;
                for(l = 1; l<=n; l++)
                {
 
                 i/l;
                 s += i/l;
 
 
 
                }
 
            printf("%.6lf", s);
 
        }
 
return 0;
}