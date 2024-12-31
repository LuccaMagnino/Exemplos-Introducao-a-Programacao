#include <stdio.h>

int main()
 {

    double a, b, c, d;
    
    scanf("%lf %lf", &a, &b);
    scanf("%lf %lf", &c, &d);
    
    double determinante = (a * d) - (b * c);
    
    printf("%.2lf\n", determinante);
    
    return 0;
}