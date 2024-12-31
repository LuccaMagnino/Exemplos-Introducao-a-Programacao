#include <stdio.h>

int soma (int c)
{

    if (c == 0)
    {
        return 0;
    }
    if (c%2 == 0)
    {
        return 3 + soma(c - 1);
    }
    if (c%2 != 0)
    {
        return 2 + soma(c - 1);
    }
}

int main()
{
    int n;
    scanf ("%d", &n);
    while (n>0)
    {
        int c;
        scanf ("%d", &c);
        printf("%d\n", soma(c));
        n--;
    }
    return 0;
}