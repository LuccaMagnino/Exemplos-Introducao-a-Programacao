#include <stdio.h>
#include <string.h>
int main()
{
    long n,m;
    char str[15];
    char a[15];
    scanf("%ld %ld", &n, &m);
    while(n != 0 || m != 0)
    {
        n+=m;
        sprintf(str, "%ld", n);
        int i;
        int j=0;
        for(i=0; str[i] != '\0'; i++)
            {
                if(str[i] != '0')
                {
                    a[j] = str[i];
                    j++;
                }
                else{
                    j++;
                }
            }
            a[j]='\0';
            printf("%s\n", a);
            scanf("%ld %ld", &n, &m);
    }



return 0;
}