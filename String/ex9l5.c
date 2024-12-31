#include <stdio.h>
#include <string.h>

int main()
{
    int n;
    scanf("%d", &n);
    char str[244430];
    char a[100];
    while (n > 0)
    {
        int b, e;
        scanf("%d %d", &b, &e);
        int j = 0;
            for (; b <= e; b++)
            {
                sprintf(str + j, "%d", b);
                for (; str[j] != '\0'; j++);
                    
            }
        j--;
        int k = j + 1;
            for (; j >= 0; j--, k++)
            {
                str[k] = str[j];
            }
        str[k] = '\0';
        printf("%s\n", str);
        n--;
    }

    return 0;
}