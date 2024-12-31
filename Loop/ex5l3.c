#include<stdio.h>
int main()
{

int a1, r, n;
scanf("%d%d%d",&a1, &r, &n);

    int i = 0, l = 0, s = 0;
        for(i = 0; i<n; i++){
        l = a1 + i*r; //a1 + (n - 1) * r
      
        s+=l;

        }
        printf("%d", s);
 
 
return 0;
}
