#include <stdio.h>

int piso (int x)
{
    if (x == 1)
    {
        return 0;
    }
    else
    {
        return 1 + piso (x/2);
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    while (n > 0)
    {
        int x;
        scanf("%d", &x);
        printf("%d\n", piso (x));
        n--;
    }

    return 0;
}