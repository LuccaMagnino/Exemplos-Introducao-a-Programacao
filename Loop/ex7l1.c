#include<stdio.h>
#include<math.h>
int main()
 
{
double l1;
double l2;
double l3;
scanf("%lf", &l1);
scanf("%lf", &l2);
scanf("%lf", &l3);nn
printf("A AREA DO TRIANGULO E = %.2lf\n", sqrt(
((l1+l2+l3)/2)*
(((l1+l2+l3)/2)-l1)*
(((l1+l2+l3)/2)-l2)*
(((l1+l2+l3)/2)-l3)
)
);
return 0;
}