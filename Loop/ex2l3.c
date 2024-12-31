#include <stdio.h>
int main()
{

    int n;
    scanf("%d", &n);
    int l = 0;
    for (l = 0; l < n; l++)
    {
        double temp;
        scanf("%lf", &temp); 

        printf("%.2lf FAHRENHEIT EQUIVALE A %.2lf CELSIUS\n", temp,
               (5 * (temp - 32)) / 9);
    }

    return 0;
}