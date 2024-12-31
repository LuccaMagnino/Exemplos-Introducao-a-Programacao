#include <stdio.h>
#include <string.h>

int main()
{
    int i, tam1, tam2, tam3, j;
    char str1[50], str2[50], str3[100];
    int n;
    scanf("%d", &n);
    while (n > 0)
    {
        scanf("%s %s", str1, str2);

        tam1 = strlen(str1);
        tam2 = strlen(str2);
        tam3 = tam1 + tam2;

        for (j = 0; j < tam3; j++)
        {
            if (j < tam1)
            {
                printf("%c", str1[j]);
            }

            if (j < tam2)
            {
                printf("%c", str2[j]);
            }
        }
        printf("\n");
        n--;
    }

    return 0;
}